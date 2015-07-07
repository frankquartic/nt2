//==============================================================================
//        Copyright 2015   J.T. Lapreste
//
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_TRIG_DERIVATIVES_FUNCTIONS_COTANGENT_HPP_INCLUDED
#define NT2_TRIG_DERIVATIVES_FUNCTIONS_COTANGENT_HPP_INCLUDED
#include <nt2/trigonometric/include/functions/cotangent.hpp>
#include <nt2/include/functions/simd/cotangent.hpp>
#include <nt2/include/functor.hpp>


namespace nt2
{
  /*!
    Compute the Nth derivative of cotangent at x
    by cotangent<mode, N>(x)
    @see @funcref{cotangent}
  **/
  NT2_FUNCTION_IMPLEMENTATION_TPL(tag::cotangent_<A0>, cotangent,  (A1 const&)(A2 const&), 3)


  template < class mode,  long N, class T> BOOST_FORCEINLINE T cotangent(const T & x)
  {
    return cotangent<mode>(boost::mpl::long_<N>(), x);
  }

}

#endif

