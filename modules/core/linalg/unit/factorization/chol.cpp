//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2013   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <nt2/include/functions/chol.hpp>
#include <nt2/include/functions/rand.hpp>
#include <nt2/include/functions/eye.hpp>
#include <nt2/include/functions/cons.hpp>
#include <nt2/include/functions/transpose.hpp>
#include <nt2/include/functions/mtimes.hpp>
#include <nt2/include/functions/pascal.hpp>
#include <nt2/include/functions/dec.hpp>

#include <nt2/table.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/unit/tests/ulp.hpp>
#include <nt2/sdk/unit/tests/relation.hpp>
#include <nt2/sdk/unit/tests/exceptions.hpp>

NT2_TEST_CASE_TPL(chol_scalar, NT2_REAL_TYPES )
{
  typedef nt2::table<T>           t_t;
  T a0 =  nt2::One<T>();
  t_t s = nt2::chol(a0);
  NT2_TEST_ULP_EQUAL(s, nt2::ones<T>(1),1 );
  s =  nt2::chol(a0, nt2::econ_);
  NT2_TEST_ULP_EQUAL(s, nt2::ones<T>(1),1 );

}


NT2_TEST_CASE_TPL(chol, NT2_REAL_TYPES )
{
  using nt2::_;
  using nt2::lower_;
  using nt2::upper_;

  typedef nt2::table<T>           t_t;

  t_t r,l;
  int info;
  nt2::table<T,nt2::positive_definite_>
      a = nt2::cons<T>(nt2::of_size(3,3),2,-1,0,-1,2,-1,0,-1,2);


  // R = CHOL(A)
  r = nt2::chol(a);
  NT2_TEST_ULP_EQUAL(a, nt2::mtimes(nt2::trans(r),r), T(20) );

  // R = CHOL(A,upper_)
  r = nt2::chol(a,upper_);
  NT2_TEST_ULP_EQUAL(a, nt2::mtimes(nt2::trans(r),r), T(20) );

  // R = CHOL(A,lower_)
  nt2::tie(l,info) = nt2::chol(a,lower_);
  NT2_TEST_ULP_EQUAL(a, nt2::mtimes(l,nt2::trans(l)), T(20) );

  // [R,P] = CHOL(A)
  nt2::tie(r,info) = nt2::chol(a);
  NT2_TEST_EQUAL(info,0);
  NT2_TEST_ULP_EQUAL(a, nt2::mtimes(nt2::trans(r),r), T(20) );

  // [R,P] = CHOL(A,upper_)
  nt2::tie(r,info) = nt2::chol(a);
  NT2_TEST_EQUAL(info,0);
  NT2_TEST_ULP_EQUAL(a, nt2::mtimes(nt2::trans(r),r), T(20) );

  // [R,P] = CHOL(A,lower_)
  nt2::tie(l,info) = nt2::chol(a,lower_);
  NT2_TEST_EQUAL(info,0);
  NT2_TEST_ULP_EQUAL(a, nt2::mtimes(l,nt2::trans(l)), T(20) );
}

NT2_TEST_CASE_TPL(cholnd, NT2_REAL_TYPES )
{
  // testing when matrix is positive but not definite
  using nt2::_;
  using nt2::lower_;
  using nt2::upper_;

  typedef nt2::table<T>           t_t;

  t_t l;

  t_t a = nt2::pascal(5, nt2::meta::as_<T>());
  a(5, 5) = nt2::dec(a(5, 5));
  NT2_DISPLAY(a);
  int p;
  nt2::tie(l,p) = nt2::chol(a,lower_);
  NT2_TEST_EQUAL(p,5);
  NT2_DISPLAY(l);
  NT2_TEST_ULP_EQUAL(a(nt2::_(1, 4), nt2::_(1, 4)), nt2::mtimes(l,nt2::trans(l)), T(20) );

  t_t r;
  nt2::tie(r,p) = nt2::chol(a,upper_);
  NT2_TEST_EQUAL(p,5);
  NT2_DISPLAY(l);
  NT2_TEST_ULP_EQUAL(a(nt2::_(1, 4), nt2::_(1, 4)), nt2::mtimes(nt2::trans(r),r), T(20) );
}
