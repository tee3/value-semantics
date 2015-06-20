#include <iostream>

#include <vector>
#include <string>
#include <memory>

#include <cstddef>

#include <cassert>

template<typename T>
void
draw (const T & x, std::ostream & out, std::size_t position)
{
   out << std::string (position,' ') << x << std::endl;
}

class object_t
{
public:
   template<typename T>
   object_t (T x) :
      self_ (std::make_shared<model<T>> (std::move (x)))
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
   struct concept_t
   {
      virtual
      ~concept_t () = default;

      virtual
      void
      draw_ (std::ostream & out, std::size_t position) const = 0;
   };

   template<typename T>
   struct model : concept_t
   {
      model (T x) :
         data_ (std::move (x))
      {
      }

      void
      draw_ (std::ostream & out, std::size_t position) const
      {
         draw (data_,out,position);
      }

      T data_;
   };

   std::shared_ptr<const concept_t> self_;
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

using history_t = std::vector<document_t>;

void
commit (history_t & x)
{
   assert (x.size () > 0);
   x.push_back (x.back ());
}

void
undo (history_t & x)
{
   assert (x.size () > 0);
   x.pop_back ();
}

document_t &
current (history_t & x)
{
   assert (x.size () > 0);
   return x.back ();
}

// Local variables:
// flycheck-clang-language-standard: "c++14"
// End:
