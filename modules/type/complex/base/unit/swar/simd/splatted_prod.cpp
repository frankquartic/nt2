//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <nt2/swar/include/functions/splatted_prod.hpp>
#include <nt2/include/functions/load.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/complex/complex.hpp>
#include <nt2/sdk/complex/dry.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <boost/simd/sdk/simd/io.hpp>

#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/unit/tests/relation.hpp>
#include <nt2/sdk/unit/tests/type_expr.hpp>

NT2_TEST_CASE_TPL ( splatted_prod_cplx, NT2_SIMD_REAL_TYPES)
{
  using nt2::splatted_prod;
  using nt2::tag::splatted_prod_;
  using boost::simd::native;
  using boost::simd::splat;

  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef std::complex<T>               cT;
  typedef native<T,ext_t>               vT;
  typedef native<cT,ext_t>              vcT;

  NT2_TEST_TYPE_IS( typename nt2::meta::call<splatted_prod_(vcT)>::type
                  , vcT
                  );

  static const std::size_t n = vT::static_size;
  T data[n];
  cT fact  = cT(1,0);

  for(std::size_t i=0;i<n;++i) data[i] = i+1;
  for(std::size_t i=0;i<n;++i) fact *= cT(i+1,i+1);

  vT v = boost::simd::load<vT>(&data[0]);
  vcT vn(v,v);

  NT2_TEST_EQUAL(splatted_prod(vn), splat<vcT>(fact)  );
}

NT2_TEST_CASE_TPL ( splatted_prod_dry, NT2_SIMD_REAL_TYPES)
{
  using nt2::splatted_prod;
  using nt2::tag::splatted_prod_;
  using boost::simd::native;
  using boost::simd::splat;

  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef nt2::dry<T>                   cT;
  typedef native<T,ext_t>               vT;
  typedef native<cT,ext_t>              vcT;

  NT2_TEST_TYPE_IS( typename nt2::meta::call<splatted_prod_(vcT)>::type
                  , vcT
                  );

  static const std::size_t n = vT::static_size;
  T data[n];
  cT fact  = cT(1);

  for(std::size_t i=0;i<n;++i) data[i] = i+1;
  for(std::size_t i=0;i<n;++i) fact *= cT(i+1);

  vT v = boost::simd::load<vT>(&data[0]);
  vcT vn(v);

  NT2_TEST_EQUAL(splatted_prod(vn), splat<vcT>(fact) );
}
