//==============================================================================
//         Copyright 2015 J.T. Lapreste
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <nt2/trig_derivatives/include/functions/acot.hpp>
#include <nt2/include/functions/acot.hpp>
#include <nt2/include/functor.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/unit/tests/ulp.hpp>
#include <boost/simd/sdk/config.hpp>

#include <nt2/include/constants/half.hpp>


NT2_TEST_CASE_TPL ( acot,  NT2_REAL_TYPES)
{
  using nt2::acot;

  NT2_TEST_ULP_EQUAL(acot<1>(nt2::Half<T>()),
                     T(-0.8), 1.5);
  NT2_TEST_ULP_EQUAL(acot<2>(nt2::Half<T>()),
                     T(0.64), 1.5);
  NT2_TEST_ULP_EQUAL(acot<3>(nt2::Half<T>()),
                     T(0.256), 6);

}

