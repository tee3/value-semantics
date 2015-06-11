#include <iostream>

#include <vector>
#include <string>

#include <cstddef>

using object_t = int;

void
draw (const object_t & x, std::ostream & out, std::size_t position)
{
   out << std::string (position,' ') << x << std::endl;
}

using document_t = std::vector<object_t>;

void
draw (const document_t & x, std::ostream & out, std::size_t position)
{
   out << std::string (position,' ') << "<document>" << std::endl;
   for (const auto & e : x)
   {
      draw (e,std::cout,position + 2);
   }
   out << std::string (position,' ') << "</document>" << std::endl;
}

// Local variables:
// flycheck-clang-language-standard: "c++14"
// End:
