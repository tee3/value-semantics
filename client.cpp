#include <iostream>

#include "library.hpp"

class my_class_t : public object_t
{
public:
   void
   draw (std::ostream & out,
         std::size_t position) const
   {
      out << std::string (position,' ') << "my_class_t" << std::endl;
   }
};

int
main ()
{
   document_t document;

   document.emplace_back (new my_class_t ());

   draw (document,std::cout,0);

   return 0;
}

// Local variables:
// flycheck-clang-language-standard: "c++14"
// End:
