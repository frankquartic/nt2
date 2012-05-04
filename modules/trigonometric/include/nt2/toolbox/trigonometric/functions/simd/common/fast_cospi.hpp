//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_TRIGONOMETRIC_FUNCTIONS_SIMD_COMMON_FAST_COSPI_HPP_INCLUDED
#define NT2_TOOLBOX_TRIGONOMETRIC_FUNCTIONS_SIMD_COMMON_FAST_COSPI_HPP_INCLUDED
#include <nt2/include/constants/one.hpp>
#include <nt2/toolbox/trigonometric/functions/simd/common/impl/trigo.hpp>
#include <nt2/include/functions/simd/is_eqz.hpp>
#include <nt2/include/functions/simd/if_else_allbits.hpp>

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::fast_cospi_, boost::simd::tag::simd_
                            , (A0)(X)
                            , ((simd_<arithmetic_<A0>,X>))
                            )
  {
    typedef typename meta::as_floating<A0>::type result_type;
    NT2_FUNCTOR_CALL(1)
    {
      return if_else_allbits(is_eqz(a0),One<result_type>()); 
    }
  };
} }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is floating_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::fast_cospi_, boost::simd::tag::simd_
                            , (A0)(X)
                            , ((simd_<floating_<A0>,X>))
                            )
  {
    typedef A0 result_type;
    NT2_FUNCTOR_CALL(1)
    {
      A0 that = {impl::trig_base<A0,pi_tag,  tag::simd_type, clipped_pio4>::cosa(a0)}; 
      return that;
    }
  };
} }

#endif
