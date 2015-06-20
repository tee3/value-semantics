#include <iostream>

#include "library.hpp"

int
main ()
{
   document_t document;
   document.emplace_back (0);
   document.emplace_back (1);
   document.emplace_back (2);
   document.emplace_back (3);

   draw (document,std::cout,0);

   return 0;
}

// Local variables:
// flycheck-clang-language-standard: "c++14"
// End:
