//==============================================================================
//          Copyright 2015 J.T. Lapreste
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_TRIG_DERIVATIVES_FUNCTIONS_GENERIC_ASIN_HPP_INCLUDED
#define NT2_TRIG_DERIVATIVES_FUNCTIONS_GENERIC_ASIN_HPP_INCLUDED
#include <nt2/include/functions/simd/asin.hpp>
#include <nt2/include/functions/simd/acos.hpp>
#include <nt2/include/functions/simd/unary_minus.hpp>
#include <nt2/include/functor.hpp>

namespace nt2
{
  namespace ext
  {

    BOOST_DISPATCH_IMPLEMENT  ( asin_, tag::cpu_
                              , (order)(A0)
                              , (unspecified_<order>)
                                (generic_<unspecified_<A0>>)
                              )
    {
      typedef A0                                            result_type;
      typedef typename meta::scalar_of<A0>::type                    sA0;
      BOOST_FORCEINLINE result_type operator()(const order&
                                              , const A0& u) const
      {
        return compute(order(), u);
      }
    private:
      BOOST_FORCEINLINE result_type compute(const boost::mpl::long_<0>
                                           , const A0& u) const
      {
        return asin(u);
      }
      template<long P>
      BOOST_FORCEINLINE result_type compute(const boost::mpl::long_<P>
                                           , const A0& u) const
      {
        return  -acos(order(), u);
      }
   };
  }
}


#endif
