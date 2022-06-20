#ifndef QR_EIGEN_TYPES_H
#define QR_EIGEN_TYPES_H

#include <Eigen/Dense>

// TODO: fill this file
/**
 * @brief a 3x3 matrix with type T
 */
template<typename T>
using Mat3 = typename Eigen::Matrix<T, 3, 3>;

#endif // QR_EIGEN_TYPES_H