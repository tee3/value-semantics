#include <iostream>

#include "library.hpp"

int
main ()
{
   document_t document;
   document.reserve (5);
   document.emplace_back (0);
   document.emplace_back (1);
   document.emplace_back (2);
   document.emplace_back (3);

   std::reverse (document.begin (),document.end ());

   draw (document,std::cout,0);

   return 0;
}

// Local variables:
// flycheck-clang-language-standard: "c++14"
// End:
