################################################################################
#         Copyright 2003 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
#         Copyright 2009 - 2012 LRI    UMR 8623 CNRS/Univ Paris Sud XI
#         Copyright 2012 - 2013 MetaScale SAS
#
#          Distributed under the Boost Software License, Version 1.0.
#                 See accompanying file LICENSE.txt or copy at
#                     http://www.boost.org/LICENSE_1_0.txt
################################################################################

get_property(NT2_CORE.LINALG_FOUND GLOBAL PROPERTY NT2_CORE.LINALG_FOUND)
if(NOT NT2_CORE.LINALG_FOUND)
  return()
endif()

add_executable(sdot_mkl sdot_mkl.cpp)
