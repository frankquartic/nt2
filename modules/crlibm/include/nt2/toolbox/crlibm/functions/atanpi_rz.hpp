//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_CRLIBM_FUNCTIONS_ATANPI_RZ_HPP_INCLUDED
#define NT2_TOOLBOX_CRLIBM_FUNCTIONS_ATANPI_RZ_HPP_INCLUDED
#include <nt2/include/simd.hpp>
#include <nt2/include/functor.hpp>

namespace nt2 { namespace crlibm { namespace tag
  {         
    struct atanpi_rz_ {};
  }
  NT2_FUNCTION_IMPLEMENTATION(crlibm::tag::atanpi_rz_, atanpi_rz, 1)
  } }
 
#include <nt2/toolbox/crlibm/functions/scalar/atanpi_rz.hpp>
// #include <nt2/toolbox/crlibm/functions/simd/all/atanpi_rz.hpp> 

 
#endif

// modified by jt the 29/12/2010