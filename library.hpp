#include <iostream>

#include <vector>
#include <string>
#include <memory>

#include <cstddef>

void
draw (const int & x, std::ostream & out, std::size_t position)
{
   out << std::string (position,' ') << x << std::endl;
}

class object_t
{
public:
   object_t (const int & x) :
      self_ (new int_model_t (x))
   {
   }

   friend
   void
   draw (const object_t & x,
         std::ostream & out,
         std::size_t position)
   {
      x.self_->draw_ (out,position);
   }

private:
   struct int_model_t
   {
      int_model_t (const int & x) :
         data_ (x)
      {
      }

      void
      draw_ (std::ostream & out, std::size_t position) const
      {
         draw (data_,out,position);
      }

      int data_;
   };

   std::unique_ptr<int_model_t> self_;
};

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
