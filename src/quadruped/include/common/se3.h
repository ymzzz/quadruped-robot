#ifndef SE3_H
#define SE3_H

#include <Eigen/Dense>
#include "common/eigentypes.h"
namespace Math {

// TODO: fill this file that will be used in qr_robot.h
//  template<typename T>
//  Eigen::Matrix<float, 4, 1> rpy2quat(const Eigen::MatrixBase<float 3, 1> &rpy)
//  {
//    Mat3<typename T::Scalar> R = rpyToRotMat(rpy);
//    Quat<typename T::Scalar> q = rotationMatrixToQuaternion(R);
//    return q;
//  }
}

#endif // SE3_H