//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_BITWISE_FUNCTIONS_BITWISE_ORNOT_HPP_INCLUDED
#define BOOST_SIMD_BITWISE_FUNCTIONS_BITWISE_ORNOT_HPP_INCLUDED
#include <boost/simd/include/functor.hpp>
#include <boost/dispatch/include/functor.hpp>

namespace boost { namespace simd { namespace tag
  {
    /*!
      @brief  bitwise_ornot generic tag

      Represents the bitwise_ornot function in generic contexts.

      @par Models:
      Hierarchy
    **/
    struct bitwise_ornot_ : ext::elementwise_<bitwise_ornot_>
    {
      /// @brief Parent hierarchy
      typedef ext::elementwise_<bitwise_ornot_> parent;
      template<class... Args>
      static BOOST_FORCEINLINE BOOST_AUTO_DECLTYPE dispatch(Args&&... args)
      BOOST_AUTO_DECLTYPE_BODY( dispatching_bitwise_ornot_( ext::adl_helper(), static_cast<Args&&>(args)... ) )
    };
  }
  namespace ext
  {
    template<class Site>
    BOOST_FORCEINLINE generic_dispatcher<tag::bitwise_ornot_, Site> dispatching_bitwise_ornot_(adl_helper, boost::dispatch::meta::unknown_<Site>, ...)
    {
      return generic_dispatcher<tag::bitwise_ornot_, Site>();
    }
    template<class... Args>
    struct impl_bitwise_ornot_;
  }
  /*!
    Computes the bitwise and not of its parameters.

    @par semantic:
    For any given value @c x, of type @c T1 @c y of type @c T2
    of same memory size:

    @code
    T1 r = bitwise_ornot(x, y);
    @endcode

    The code is equivalent to:

    @code
    T1 r = x | ~y;
    @endcode

    @par Alias

    b_ornot

    @see  @funcref{bitwise_and}, @funcref{bitwise_xor}, @funcref{bitwise_notand},
    @funcref{bitwise_andnot}, @funcref{bitwise_notor}, @funcref{bitwise_ornot}, @funcref{complement}
    @param  a0
    @param  a1

    @return      a value of the same type as the first input.

  **/
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::bitwise_ornot_, bitwise_ornot, 2)
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::bitwise_ornot_, b_ornot, 2)
} }

#endif
