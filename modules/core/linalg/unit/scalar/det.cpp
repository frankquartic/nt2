//==============================================================================
//         Copyright 2003 - 2013   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//         Copyright 2012 - 2013   MetaScale SAS
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <nt2/table.hpp>
#include <nt2/include/functions/det.hpp>
#include <nt2/include/functions/eye.hpp>
#include <nt2/include/functions/kms.hpp>
#include <nt2/include/functions/binomial.hpp>
#include <nt2/include/functions/eye.hpp>
#include <nt2/include/functions/ones.hpp>
#include <nt2/include/functions/cons.hpp>
#include <nt2/include/constants/one.hpp>
#include <nt2/include/constants/ten.hpp>
#include <nt2/include/constants/mone.hpp>

#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/unit/tests/relation.hpp>
#include <nt2/sdk/unit/tests/ulp.hpp>

NT2_TEST_CASE_TPL(det, NT2_REAL_TYPES)
{
  using nt2::det;
  using nt2::tag::det_;
  nt2::table<T> n = nt2::eye(10, 10, nt2::meta::as_<T>());
  NT2_TEST_ULP_EQUAL(det(n), nt2::One<T>(), 0);
  NT2_TEST_ULP_EQUAL(det(n+n), T(1024), 0);
  n(10, 10) = 10;
  NT2_TEST_ULP_EQUAL(det(n), nt2::Ten<T>(), 0);
  NT2_TEST_ULP_EQUAL(det(n+n), nt2::Ten<T>()*T(1024), 0);
  n(10, 10) = -1;
  NT2_TEST_ULP_EQUAL(det(n), nt2::Mone<T>(), 0);
  NT2_TEST_ULP_EQUAL(det(n+n), T(-1024), 0);

  NT2_TEST_ULP_EQUAL(det(nt2::binomial(4, nt2::meta::as_<T>())), T(64), 1);
  NT2_TEST_ULP_EQUAL(det(nt2::kms<T>(4)), T(0.421875), 1);
}
NT2_TEST_CASE_TPL(det1, NT2_REAL_TYPES)
{
  nt2::table<T> a = nt2::eye(4, 4, nt2::meta::as_<T>());
  nt2::table<T> b = a(nt2::_, nt2::cons(2, 1, 3, 4));
  NT2_TEST_ULP_EQUAL(det(a), -det(b), 1);
}

NT2_TEST_CASE_TPL(detem, NT2_REAL_TYPES)
{
  using nt2::det;
  using nt2::tag::det_;
  nt2::table<T> n = nt2::eye(10, 10, nt2::meta::as_<T>());
  int e;
  T m;
  m = det(n, e);
  NT2_DISPLAY(m);
  NT2_DISPLAY(e);
  NT2_TEST_ULP_EQUAL(ldexp(m, e), nt2::One<T>(), 0);
  m = det(n+n, e);
  NT2_DISPLAY(m);
  NT2_DISPLAY(e);
  NT2_TEST_ULP_EQUAL(ldexp(m, e), T(1024), 0);
  n(10, 10) = 10;
  m = det(n, e);
  NT2_DISPLAY(m);
  NT2_DISPLAY(e);
  NT2_TEST_ULP_EQUAL(ldexp(m, e), nt2::Ten<T>(), 0);
  m = det(n+n, e);
  NT2_DISPLAY(m);
  NT2_DISPLAY(e);
  NT2_TEST_ULP_EQUAL(ldexp(m, e), T(1024)*nt2::Ten<T>(), 0);
  n(10, 10) = -1;
  m = det(n, e);
  NT2_DISPLAY(m);
  NT2_DISPLAY(e);
  NT2_TEST_ULP_EQUAL(ldexp(m, e), nt2::Mone<T>(), 0);
  m = det(n+n, e);
  NT2_DISPLAY(m);
  NT2_DISPLAY(e);
  NT2_TEST_ULP_EQUAL(ldexp(m, e), T(-1024), 0);
}
