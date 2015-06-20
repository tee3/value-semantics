#include <iostream>

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
