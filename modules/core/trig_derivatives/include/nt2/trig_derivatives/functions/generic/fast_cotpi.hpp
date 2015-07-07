//==============================================================================
//          Copyright 2015 J.T. Lapreste
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_TRIG_DERIVATIVES_FUNCTIONS_GENERIC_FAST_COTPI_HPP_INCLUDED
#define NT2_TRIG_DERIVATIVES_FUNCTIONS_GENERIC_FAST_COTPI_HPP_INCLUDED
#include <nt2/include/functions/simd/fast_cotpi.hpp>
#include <nt2/include/functions/simd/fast_cot.hpp>
#include <nt2/include/functions/simd/pow.hpp>
#include <nt2/include/constants/invpi.hpp>
#include <nt2/include/functor.hpp>

namespace nt2
{
  namespace ext
  {

    BOOST_DISPATCH_IMPLEMENT  ( fast_cotpi_, tag::cpu_
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
        return fast_cotpi(u);
      }
      BOOST_FORCEINLINE result_type compute(const boost::mpl::long_<1>
                                           , const A0& u) const
      {
        return -oneplus(sqr(fast_cotpi(u)))*Invpi<result_type>();
      }

      BOOST_FORCEINLINE result_type compute(const boost::mpl::long_<2>
                                           , const A0& u) const
      {
        result_type x = fast_cotpi(u);
        return  oneplus(sqr(x))*x*Two<result_type>()*sqr(Invpi<result_type>());
      }

      template<long P>
        BOOST_FORCEINLINE result_type compute(const boost::mpl::long_<P>
                                             , const A0& u) const
      {
        container::table<sA0> pol;
        details::tan_kernel<P, A0>::cotpi_pl(pol);
        return polyval(pol, fast_cotpi(u));
      }
    };
  }
}


#endif
