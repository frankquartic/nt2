//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_EXPONENTIAL_CONSTANTS_MAXLOG_HPP_INCLUDED
#define NT2_EXPONENTIAL_CONSTANTS_MAXLOG_HPP_INCLUDED

#include <boost/simd/constant/hierarchy.hpp>
#include <boost/simd/constant/register.hpp>

namespace nt2
{
  namespace tag
  {
    /*!
      @brief Maxlog generic tag

      Represents the Maxlog constant in generic contexts.

      @par Models:
      Hierarchy
    **/
    BOOST_SIMD_CONSTANT_REGISTER( Maxlog, double
                                , 0, 0x42b17218
                                , 0x40862e42fefa39efll
                                );
  }
  /*!
    Generates constant MaxLog used in logarithm computations

    @par Semantic:

    @code
    T r = Log_10<T>();
    @endcode

    is similar to:

    @code
    if T is integral
    r = T(2)
    else if T is double
    r = 709.78271289338400;
    else if T is float
    r = 88.722839355468750;

    @endcode

  **/
  BOOST_SIMD_CONSTANT_IMPLEMENTATION(tag::Maxlog, Maxlog);
}

#endif
