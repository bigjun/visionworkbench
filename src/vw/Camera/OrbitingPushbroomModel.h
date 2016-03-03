// __BEGIN_LICENSE__
//  Copyright (c) 2006-2013, United States Government as represented by the
//  Administrator of the National Aeronautics and Space Administration. All
//  rights reserved.
//
//  The NASA Vision Workbench is licensed under the Apache License,
//  Version 2.0 (the "License"); you may not use this file except in
//  compliance with the License. You may obtain a copy of the License at
//  http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
// __END_LICENSE__


/// \file OrbitingPushbroomModel.h
///
/// Orbiting pushbroom camera model object.
///
/// Notes:
///
/// The orbiting pushbroom camera model takes the local curvature of a
/// spacecraft's orbit into account when computing it's position.  The
/// position estimate is based on:
///
/// camera_poses (std::vector of quaternions)
/// positions    (std::vector of Vector3's containing a position in 3-space)
///
/// The position is be approximated using a 2nd degree quadratic
/// curve, fit using linear least squares.  The orientation
/// (quaternion) will be extrapolated using the SLERP algorithm.  (See
/// Extrinsics.h)

#ifndef __VW_CAMERA_ORBITINGPUSHBROOM_MODEL_H__
#define __VW_CAMERA_ORBITINGPUSHBROOM_MODEL_H__

#include <vw/Camera/LinescanModel.h>
#include <vw/Camera/Extrinsics.h>

#include <vector>

namespace vw {
namespace camera {

  class OrbitingPushbroomModel : public LinescanModel<Curve3DPositionInterpolation,
                                                      SLERPPoseInterpolation> {

  public:
    //------------------------------------------------------------------
    // Constructors / Destructors
    //------------------------------------------------------------------

    /// Set up the position and pose estimators.  These are the
    /// characteristics that differentiate the orbiting pushbroom model
    /// from other linescan imagers.
    OrbitingPushbroomModel( int     number_of_lines,
                            int     samples_per_line,
                            int     sample_offset,
                            double  focal_length,
                            double  along_scan_pixel_size,
                            double  across_scan_pixel_size,
                            double  line_integration_time,
                            double  t0_camera_pose, // Time of camera_poses[0]
                            double  dt_camera_pose, // Time increment for camera_poses
                            double  t0_position,    // Time of positions[0]
                            double  dt_position,    // Time increment for positions
                            Vector3 pointing_vec,
                            Vector3 u_vec,
                            std::vector<Quaternion<double> > const& camera_poses,
                            std::vector<Vector3            > const& positions);

    /// This constructor is used when the exposure time varies from
    /// scanline to scanline, e.g. in the case of HRSC.
    OrbitingPushbroomModel( int     number_of_lines,
                            int     samples_per_line,
                            int     sample_offset,
                            double  focal_length,
                            double  along_scan_pixel_size,
                            double  across_scan_pixel_size,
                            std::vector<double> line_times,
                            double  t0_camera_pose,
                            double  dt_camera_pose,
                            double  t0_position,
                            double  dt_position,
                            Vector3 pointing_vec,
                            Vector3 u_vec,
                            std::vector<Quaternion<double> > const& camera_poses,
                            std::vector<Vector3            > const& positions);

    virtual ~OrbitingPushbroomModel();
    virtual std::string type() const;

  };
}}      // namespace vw::camera

#endif  //__VW_CAMERA_ORBITINGPUSHBROOM_MODEL_H__
