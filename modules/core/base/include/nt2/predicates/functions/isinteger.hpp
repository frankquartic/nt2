//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//         Copyright 2011 - 2012   MetaScale SAS
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_PREDICATES_FUNCTIONS_ISINTEGER_HPP_INCLUDED
#define NT2_PREDICATES_FUNCTIONS_ISINTEGER_HPP_INCLUDED

/*!
  @file
  @brief Defines the isinteger function
**/

#include <nt2/include/functor.hpp>

namespace nt2
{
  namespace tag
  {
    /*!
      @brief Tag for isinteger functor
    **/
    struct isinteger_ : ext::abstract_<isinteger_>
    {
      typedef ext::abstract_<isinteger_> parent;
      template<class... Args>
      static BOOST_FORCEINLINE BOOST_AUTO_DECLTYPE dispatch(Args&&... args)
      BOOST_AUTO_DECLTYPE_BODY( dispatching_isinteger_( ext::adl_helper(), static_cast<Args&&>(args)... ) )
    };
  }
  namespace ext
  {
    template<class Site>
    BOOST_FORCEINLINE generic_dispatcher<tag::isinteger_, Site> dispatching_isinteger_(adl_helper, boost::dispatch::meta::unknown_<Site>, ...)
    {
      return generic_dispatcher<tag::isinteger_, Site>();
    }
    template<class... Args>
    struct impl_isinteger_;
  }

  /*!
    @brief Is an expression

    @param

    @return
  **/
  NT2_FUNCTION_IMPLEMENTATION(nt2::tag::isinteger_, isinteger, 1)
}

#endif

