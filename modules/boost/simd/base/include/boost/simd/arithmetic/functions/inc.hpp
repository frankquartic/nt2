//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_ARITHMETIC_FUNCTIONS_INC_HPP_INCLUDED
#define BOOST_SIMD_ARITHMETIC_FUNCTIONS_INC_HPP_INCLUDED

#include <boost/simd/include/functor.hpp>

namespace boost { namespace simd {
  namespace tag
  {
    /*!
      @brief  inc generic tag

      Represents the inc function in generic contexts.

      @par Models:
      Hierarchy
    **/
    struct inc_ : ext::elementwise_<inc_>
    {
      /// @brief Parent hierarchy
      typedef ext::elementwise_<inc_> parent;
      template<class... Args>
      static BOOST_FORCEINLINE BOOST_AUTO_DECLTYPE dispatch(Args&&... args)
      BOOST_AUTO_DECLTYPE_BODY( dispatching_inc_( ext::adl_helper(), static_cast<Args&&>(args)... ) )
    };
  }
  namespace ext
  {
    template<class Site>
    BOOST_FORCEINLINE generic_dispatcher<tag::inc_, Site> dispatching_inc_(adl_helper, boost::dispatch::meta::unknown_<Site>, ...)
    {
      return generic_dispatcher<tag::inc_, Site>();
    }
    template<class... Args>
    struct impl_inc_;
  }
  /*!
    Increments a value by 1.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    T r = inc(x);
    @endcode

    is equivalent to:

    @code
    T r =  x+T(1);
    @endcode

    @see  @funcref{oneplus}, @funcref{plus}
    @param  a0

    @return      a value of the same type as the input.

  **/
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::inc_, inc, 1)
} }

#endif
