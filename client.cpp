#include <iostream>

#include <thread>
#include <future>
#include <chrono>

#include "library.hpp"

class my_class_t
{
};

void
draw (const my_class_t & x, std::ostream & out, std::size_t position)
{
   out << std::string (position,' ') << "my_class_t" << std::endl;
}

int
main ()
{
   history_t h (1);

   current (h).emplace_back (0);
   current (h).emplace_back (std::string ("Hello!"));

   draw (current (h),std::cout,0);
   std::cout << "---------------------------------" << std::endl;

   commit (h);

   current (h)[0] = 42.5;

   auto document = current (h);
   auto saving = std::async (
      [=] ()
      {
         std::this_thread::sleep_for (std::chrono::seconds (3));
         std::cout << "----------- save -----------" << std::endl;
         draw (document,std::cout,0);
      }
   );

   current (h)[1] = std::string ("World");
   current (h).emplace_back (current (h));
   current (h).emplace_back (my_class_t ());

   draw (current (h),std::cout,0);
   std::cout << "---------------------------------" << std::endl;

   undo (h);

   draw (current (h),std::cout,0);

   return 0;
}

// Local variables:
// flycheck-clang-language-standard: "c++14"
// End:
