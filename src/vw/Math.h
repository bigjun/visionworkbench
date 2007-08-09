// __BEGIN_LICENSE__
// 
// Copyright (C) 2006 United States Government as represented by the
// Administrator of the National Aeronautics and Space Administration
// (NASA).  All Rights Reserved.
// 
// Copyright 2006 Carnegie Mellon University. All rights reserved.
// 
// This software is distributed under the NASA Open Source Agreement
// (NOSA), version 1.3.  The NOSA has been approved by the Open Source
// Initiative.  See the file COPYING at the top of the distribution
// directory tree for the complete NOSA document.
// 
// THE SUBJECT SOFTWARE IS PROVIDED "AS IS" WITHOUT ANY WARRANTY OF ANY
// KIND, EITHER EXPRESSED, IMPLIED, OR STATUTORY, INCLUDING, BUT NOT
// LIMITED TO, ANY WARRANTY THAT THE SUBJECT SOFTWARE WILL CONFORM TO
// SPECIFICATIONS, ANY IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR
// A PARTICULAR PURPOSE, OR FREEDOM FROM INFRINGEMENT, ANY WARRANTY THAT
// THE SUBJECT SOFTWARE WILL BE ERROR FREE, OR ANY WARRANTY THAT
// DOCUMENTATION, IF PROVIDED, WILL CONFORM TO THE SUBJECT SOFTWARE.
// 
// __END_LICENSE__

/// \file Math.h
/// 
/// A convenience header that includes the header files in vw/Math.
/// 
#ifndef __VW_MATH_H__
#define __VW_MATH_H__

#include <vw/Math/Functions.h>
#include <vw/Math/Functors.h>
#include <vw/Math/Vector.h>
#include <vw/Math/Matrix.h>
#include <vw/Math/BShape.h>
#include <vw/Math/BBox.h>
#include <vw/Math/BBall.h>
#include <vw/Math/Quaternion.h>
#include <vw/Math/ConjugateGradient.h>
#include <vw/Math/NelderMead.h>
#include <vw/Math/EulerAngles.h>
#include <vw/Math/Statistics.h>
#include <vw/Math/SpatialTree.h>
#include <vw/Math/PointListIO.h>

#if defined(VW_HAVE_PKG_LAPACK) && VW_HAVE_PKG_LAPACK==1
#include <vw/Math/LinearAlgebra.h>
#include <vw/Math/LevenbergMarquardt.h>
#include <vw/Math/Geometry.h>
#endif

#if defined(VW_HAVE_PKG_PPL) && VW_HAVE_PKG_PPL==1
#include <vw/Math/BConvex.h>
#endif

#endif // __VW_MATH_H__
