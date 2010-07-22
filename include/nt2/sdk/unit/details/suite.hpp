/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_UNIT_DETAILS_SUITE_HPP_INCLUDED
#define NT2_SDK_UNIT_DETAILS_SUITE_HPP_INCLUDED

#include <cstdio>
#include <nt2/sdk/unit/details/register.hpp>

namespace nt2 { namespace details
{
  //////////////////////////////////////////////////////////////////////////////
  // RAII class for reporting error at end of modules
  //////////////////////////////////////////////////////////////////////////////
  struct suite
  {
    ////////////////////////////////////////////////////////////////////////////
    // Display the count of test/pass/fail
    ////////////////////////////////////////////////////////////////////////////
    ~suite()
    {
      int t = details::test_count();
      int e = details::error_count();
      #if !defined(NT2_TEST_SILENT)
      puts("===============================================================");
      printf( "[%s] : %d test - %d passed - %d failure.\n"
            , NT2_UNIT_MODULE, t, (t-e), e
            );
      #endif
    }

    ////////////////////////////////////////////////////////////////////////////
    // Run the embedded tests
    ////////////////////////////////////////////////////////////////////////////
    void process() const
    {
      #if !defined(NT2_TEST_SILENT)
      printf("[%s] Tests starting ...\n",NT2_UNIT_MODULE);
      #endif
      if(tests) tests->process();
    }

    ////////////////////////////////////////////////////////////////////////////
    // Chains tests in the suite
    ////////////////////////////////////////////////////////////////////////////
    test const* link(test const* n) const { return tests->link(n); }

    ////////////////////////////////////////////////////////////////////////////
    // List of registere test functions
    ////////////////////////////////////////////////////////////////////////////
    mutable test const*  tests;
  };

  suite const main_suite  = { &dummy };

} }

#endif
