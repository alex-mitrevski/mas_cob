/*
 * look_at_point_node.h
 *
 *  Created on: Mar 29, 2015
 *      Author: fred
 */

#ifndef LOOK_AT_POINT_NODE_H_
#define LOOK_AT_POINT_NODE_H_

#include <signal.h>

#include <std_msgs/Float64MultiArray.h>
#include <geometry_msgs/PointStamped.h>
#include <ros/ros.h>
#include <sensor_msgs/JointState.h>
#include <std_msgs/String.h>
#include <tf/transform_listener.h>

class LookAtPointNode
{
public:
    enum State {INIT, IDLE, RUN};

    LookAtPointNode();
    ~LookAtPointNode();

    State update();


private:

    void pointCallback(const geometry_msgs::PointStampedPtr &msg);
    void jointStatesCallback(const sensor_msgs::JointStatePtr &msg);
    void eventCallback(const std_msgs::StringPtr &msg);

    void idleState();
    void runState();


    bool calculatePanAndTiltAngle();
    void publishTorsoJointvelocities(const double &lower_pan, const double &lower_tilt, const double &upper_pan, const double &upper_tilt);
    void publishZeroTorsoJointvelocities();

    ros::Subscriber sub_point_;
    ros::Subscriber sub_joint_states_;
    ros::Subscriber sub_event_;

    ros::Publisher pub_torso_velocities_;

    std_msgs::String event_msg_;
    bool event_msg_received_;

    geometry_msgs::PointStamped point_msg_;
    bool point_msg_received_;

    geometry_msgs::PointStamped set_point_in_pan_frame_;
    geometry_msgs::PointStamped set_point_in_tilt_frame_;
    double pan_angle_;
    double tilt_angle_;

    sensor_msgs::JointStatePtr joint_states_;
    ros::Time last_joint_states_timestamp;

    tf::TransformListener *tf_listener_;

    std::string pan_frame_;
    std::string pan_joint_name_;
    std::string tilt_frame_;
    std::string tilt_joint_name_;

    double min_pan_angle_;
    double max_pan_angle_;
    double min_pan_velocity_;
    double max_pan_velocity_;

    double min_tilt_angle_;
    double max_tilt_angle_;
    double min_tilt_velocity_;
    double max_tilt_velocity_;

    State current_state_;

    // variables fill in the joint state callback
    double current_pan_angle_;
    double current_tilt_angle_;
    double current_pan_velocity_;
    double current_tilt_velocity_;
};

#endif /* LOOK_AT_POINT_NODE_H_ */
