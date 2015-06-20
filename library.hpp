#include <iostream>

#include <vector>
#include <string>

#include <cstddef>

class object_t
{
public:
   virtual
   ~object_t () { }

   virtual
   void
   draw (std::ostream & out,
         std::size_t position) const = 0;
};

using document_t = std::vector<std::shared_ptr<object_t>>;

void
draw (const document_t & x, std::ostream & out, std::size_t position)
{
   out << std::string (position,' ') << "<document>" << std::endl;
   for (const auto & e : x)
   {
      e->draw (std::cout,position + 2);
   }
   out << std::string (position,' ') << "</document>" << std::endl;
}

// Local variables:
// flycheck-clang-language-standard: "c++14"
// End:
