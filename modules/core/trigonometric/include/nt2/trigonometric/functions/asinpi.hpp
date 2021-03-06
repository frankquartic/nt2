//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_TRIGONOMETRIC_FUNCTIONS_ASINPI_HPP_INCLUDED
#define NT2_TRIGONOMETRIC_FUNCTIONS_ASINPI_HPP_INCLUDED
#include <nt2/include/functor.hpp>


namespace nt2 {
  namespace tag
  {
   /*!
     @brief asinpi generic tag

     Represents the asinpi function in generic contexts.

     @par Models:
        Hierarchy
   **/
    struct asinpi_ : ext::elementwise_<asinpi_>
    {
      /// @brief Parent hierarchy
      typedef ext::elementwise_<asinpi_> parent;
      template<class... Args>
      static BOOST_FORCEINLINE BOOST_AUTO_DECLTYPE dispatch(Args&&... args)
      BOOST_AUTO_DECLTYPE_BODY( dispatching_asinpi_( ext::adl_helper(), static_cast<Args&&>(args)... ) )
    };
  }
  namespace ext
  {
   template<class Site>
   BOOST_FORCEINLINE generic_dispatcher<tag::asinpi_, Site> dispatching_asinpi_(adl_helper, boost::dispatch::meta::unknown_<Site>, ...)
   {
     return generic_dispatcher<tag::asinpi_, Site>();
   }
   template<class... Args>
   struct impl_asinpi_;
  }
  /*!
    inverse sine in \f$\pi\f$ multiples.
    @par Semantic:

    For every parameter of floating type T0

    @code
    T0 r = asinpi(a0);
    @endcode

    Returns the arc @c r in the interval
    \f$[-0.5, 0.5[\f$ such that <tt>cos(r) == x</tt>.
    If @c x is outside \f$[-1, 1[\f$ the result is Nan.

    @param a0

    @return a value of the same type as the parameter
  **/
  NT2_FUNCTION_IMPLEMENTATION(tag::asinpi_, asinpi, 1)
}

#endif


