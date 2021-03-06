
################################################################################
###   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
###   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
###
###          Distributed under the Boost Software License, Version 1.0
###                 See accompanying file LICENSE.txt or copy at
###                     http://www.boost.org/LICENSE_1_0.txt
################################################################################

SET( SOURCES
  sinc.cpp
  sincpi.cpp
  nbd_atan2.cpp
  proper_tanpi.cpp
  rem_pio2_straight.cpp
  rem_pio2_medium.cpp
  rem_pio2_cephes.cpp
#  rem_pio2.cpp
  sinecosine.cpp
  cosecant.cpp
  secant.cpp
  cotangent.cpp
  tangent.cpp
  sine.cpp
  cosine.cpp
  tanpi.cpp
  tand.cpp
  tan.cpp
  sinpi.cpp
  sind.cpp
  sincospi.cpp
  sincosd.cpp
  sincos.cpp
  sin.cpp
  secpi.cpp
  secd.cpp
  sec.cpp
  inrad.cpp
  indeg.cpp
  fast_tanpi.cpp
  fast_tand.cpp
  fast_tan.cpp
  fast_sinpi.cpp
  fast_sind.cpp
  fast_sincospi.cpp
  fast_sincosd.cpp
  fast_sincos.cpp
  fast_sin.cpp
  fast_cotpi.cpp
  fast_cotd.cpp
  fast_cot.cpp
  fast_cospi.cpp
  fast_cosd.cpp
  fast_cos.cpp
  cscpi.cpp
  cscd.cpp
  csc.cpp
  cotpi.cpp
  cotd.cpp
  cot.cpp
  cospi.cpp
  cosd.cpp
  cos.cpp
  atanpi.cpp
  atand.cpp
  atan2.cpp
  atan.cpp
  asinpi.cpp
  asind.cpp
  asin.cpp
  asecd.cpp
  asec.cpp
  acscd.cpp
  acsc.cpp
  acotd.cpp
  acot.cpp
  acospi.cpp
  acosd.cpp
  acos.cpp
# List of scalar test files for toolbox trigonometric
   )

nt2_module_add_tests(core.trigonometric.scalar.cover ${SOURCES})

