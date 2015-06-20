#include "library.hpp"

object_t func ()
{
   object_t result = 5;
   return result;
};

int
main ()
{
   /*
      Quiz: What will this print?
   */

   object_t x = 0;

   x = func ();
}


// Local variables:
// flycheck-clang-language-standard: "c++14"
// End:
