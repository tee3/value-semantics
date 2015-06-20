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
   document_t document;
   document.emplace_back (0);
   document.emplace_back (std::string ("Hello!"));
   document.emplace_back (document);
   document.emplace_back (my_class_t ());

   draw (document,std::cout,0);

   return 0;
}

// Local variables:
// flycheck-clang-language-standard: "c++14"
// End:
