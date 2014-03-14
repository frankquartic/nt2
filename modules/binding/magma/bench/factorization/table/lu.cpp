//==============================================================================
//         Copyright 2003 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2013 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//         Copyright 2012        MetaScale SAS
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <nt2/sdk/bench/benchmark.hpp>
#include <nt2/sdk/magma/magma.hpp>

#include <nt2/table.hpp>
#include <nt2/include/functions/lu.hpp>
#include <nt2/include/functions/rand.hpp>
#include <nt2/include/functions/zeros.hpp>
#include <magma.h>
#include "../../flops/lu.hpp"

template<typename T> struct lu_1;

template<typename T> NT2_EXPERIMENT(lu_1< nt2::table<T> >)
{
  public:
  lu_1( std::size_t h_, std::size_t w_)
      : NT2_EXPRIMENT_CTOR(1.,"GFLOPS")
      , h(h_), w(w_)
  {}

  virtual void run() const
  {
    result = nt2::lu(input);
  }

  virtual double compute(nt2::benchmark_result_t const& r) const
  {
    return (FLOPS_GETRF(h,w)/r.second)/1000.;
  }

  virtual void info(std::ostream& os) const
  {
    os << "(" << h << "x" << w << ")";
  }

  virtual void reset() const
  {
    result = nt2::zeros(h,w, nt2::meta::as_<T>());
    input  = nt2::rand(h,w, nt2::meta::as_<T>());
  }

  private:
  std::size_t   h,w;
  mutable nt2::table<T> input, result;

};


// NT2_RUN_EXPERIMENT_TPL( lu_1, (nt2::table<float>), (1023,1025) );
// NT2_RUN_EXPERIMENT_TPL( lu_1, (nt2::table<float>), (2047,2048) );
// NT2_RUN_EXPERIMENT_TPL( lu_1, (nt2::table<float>), (4000,4000) );
// NT2_RUN_EXPERIMENT_TPL( lu_1, (nt2::table<float>), (5000,5000) );
// NT2_RUN_EXPERIMENT_TPL( lu_1, (nt2::table<float>), (6000,6000) );
// NT2_RUN_EXPERIMENT_TPL( lu_1, (nt2::table<float>), (7000,7000) );
// NT2_RUN_EXPERIMENT_TPL( lu_1, (nt2::table<float>), (8000,8000) );
// NT2_RUN_EXPERIMENT_TPL( lu_1, (nt2::table<float>), (9000,9000) );
 NT2_RUN_EXPERIMENT_TPL( lu_1, (nt2::table<double>), (20000,20000) );
// NT2_RUN_EXPERIMENT_TPL( lu_1, (nt2::table<float>), (10004,10004) );


 // NT2_RUN_EXPERIMENT_TPL( lu_1, (nt2::table<double>), (1023,1025) );
 // NT2_RUN_EXPERIMENT_TPL( lu_1, (nt2::table<double>), (2048,2048) );
 // NT2_RUN_EXPERIMENT_TPL( lu_1, (nt2::table<double>), (12000,12000) );
