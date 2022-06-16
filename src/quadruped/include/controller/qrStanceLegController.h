// The MIT License

// Copyright (c) 2022 
// Robot Motion and Vision Laboratory at East China Normal University
// Contact: Xinyu Zhang   email: tophill.robotics@gmail.com

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE. 

#ifndef QR_STANCE_LEG_CONTROLLER_H
#define QR_STANCE_LEG_CONTROLLER_H
namespace QuadrupedRobot{

    class qrStanceLegController{
    public:
        /// Construct function of qrStanceLegController
        qrStanceLegController();

        virtual ~qrStanceLegController() = default;
        
        /// Reset the parameters of the qrStanceLegController.
        virtual void Reset();
        
        /// Update the parameters of the qrStanceLegController.
        virtual void Update();

        /// Compute all motors' commands via controllers.
        /// @return tuple<map, Matrix<3,4>> : 
        ///         return control ouputs (e.g. positions/torques) for all (12) motors.
        virtual std::tuple<std::vector<MotorCommand>, Eigen::Matrix<float, 3, 4>> GetAction();
    };
}
#endif //QR_STANCE_LEG_CONTROLLER_H