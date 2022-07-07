// The MIT License

// Copyright (c) 2022
// Robot Motion and Vision Laboratory at East China Normal University
// Contact:tophill.robotics@gmail.com

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

#ifndef QR_ROBOT_H
#define QR_ROBOT_H

#include <array>
#include <unordered_map>


#include "qr_robot_config.h"
#include "qr_motor_cmd.h"
#include "qr_robot_state.h"
#include "common/qr_types.h"
#include "common/qr_timer.h"
#include "common/qr_eigen_types.h"

/**
 *  @brief a base class for all robot classes.It stores runtime status and data of the robot.
 */
class qrRobot
{
public:

    /**
     *  @brief Constructor of the class
     */
    qrRobot();

    /**
     *  @brief Constructor of the class
     *  @param path: the path to the YAML file
     */
    qrRobot(std::string path);

    /**
     *  @brief Destructor of the class
     */
    virtual ~qrRobot();


    /**
     * @brief load config from path
     * @param path to config file
     * @see qrRobotConfig
     */
    void LoadConfig(std::string path);

    /**
     *  @brief Receive robot state and store information to robotState
     */
    virtual void Observation()=0;

    /**
     * @brief send command to motors according to vector qrMotorCmd. Depends on type of robot
     */
    virtual void SendCmd()=0;

    /**
     * @brief get the motor command to be executed
     * @return result of motor command
     */
    std::array<qrMotorCmd, 12> GetCmd();

    //TODO: change this
    /**
     * @brief setCmd config the cmds
     * @param motorCmdValues: values needed to config cmds
     * @param mode: control mode the the motorCmdValues
     */
    void SetCmd(const Eigen::MatrixXf &motorCmdValues, MotorMode mode);
    /**
     * @brief setCmd config the cmds
     * @param cmd: command vector
     */
    void SetCmd(const std::array<qrMotorCmd, 12> cmd);

    /**
     * @brief set target angle values to cmds
     * @param qValues: target value matrix
     */
    void SetAngleCmd(const Vec12<float> &qValues);

    /**
     * @brief set target torque values to cmds
     * @param cmdValues: target value matrix
     */
    void SetTorqueCmd(const Vec12<float> &tauValues);

    /**
     * @brief set target torque values to cmds
     * @param cmdValues: target value matrix
     */
    void SetHybridCmd(const Eigen::Matrix<float, 5, 12> &cmdValues);

    /**
     * @brief get config of the robot
     * @return config of the robot
     */
    inline qrRobotConfig* GetRobotConfig(){
        return robotConfig;
    }

    /**
     * @brief get state of the robot
     * @return state of the robot
     */
    inline qrRobotState* GetRobotState(){
        return &robotState;
    }

    /**
     * @brief return last reset time
     * @return last reset time
     */
    inline double GetTimeSinceReset(){
        return timer.GetTimeSinceReset();
    }

    /**
     * @brief reset the start time of the robot
     */
    inline void ResetStartTime(){
        timer.ResetStartTime();
    }

    /**
     * @brief return the status of the robot
     * @return whether the robot is stopped
     */
    inline bool IsStop()const{
        return stop;
    }

    /**
     * @brief set the status of the robot
     * @param b: stop or not
     */
    inline void SetStop(bool b){
        stop = b;
    }

    void ApplyAction(const std::array<qrMotorCmd, 12> cmd);

    void ApplyAction(const Eigen::MatrixXf &motorCmdValues, MotorMode mode);

protected:

    /**
     * @brief whether robot is running
     */
    bool stop;

    /**
     * @brief timer for controlling the robot
     */
    Timer timer;

    /**
     * @brief stores the static config of the robot
     */
    qrRobotConfig* robotConfig;

    /**
     * @brief stores the command that will execute at each motor
     */
    std::array<qrMotorCmd, 12> cmds;

    /**
     * @brief robot state from observation
     */
    qrRobotState robotState;
};

#endif // QR_ROBOT_H