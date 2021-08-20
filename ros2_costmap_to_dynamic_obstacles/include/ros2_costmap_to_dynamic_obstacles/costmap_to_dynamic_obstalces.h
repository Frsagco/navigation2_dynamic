#ifndef COSTMAP_TO_DYNAMIC_OBSTACLES_H_
#define COSTMAP_TO_DYNAMIC_OBSTACLES_H_

// ROS
//#include <costmap_converter/costmap_converter_interface.h>
#include <nav_msgs/msg/odometry.hpp>
#include <pluginlib/class_loader.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp_lifecycle/lifecycle_node.hpp>
#include <nav2_costmap_2d/costmap_2d.hpp>
#include <nav2_costmap_2d/costmap_2d_ros.hpp>

// OpenCV
#include <cv_bridge/cv_bridge.h>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/video/tracking.hpp>

// dynamic reconfigure
//#include <costmap_converter/CostmapToDynamicObstaclesConfig.h>
//#include <dynamic_reconfigure/server.h>

// Own includes
#include <ros2_costmap_to_dynamic_obstacles/background_subtractor.h>
#include <ros2_costmap_to_dynamic_obstacles/blob_detector.h>

// STL
#include <memory>

namespace my_costmap_converter
{

    class CostmapToDynamicObstacles
    {
    public:
        /**
   * @brief Constructor
   */
        CostmapToDynamicObstacles();

        /**
   * @brief Destructor
   */
        virtual ~CostmapToDynamicObstacles();

        /**
   * @brief Initialize the parameter for background subtractor and blob detector
   */
        virtual void initialize();

        /**
   * @brief Pass a pointer to the costmap to the plugin.
   * @sa updateCostmap2D
   * @param costmap Pointer to the costmap2d source
   */
        virtual void setCostmap2D(nav2_costmap_2d::Costmap2D *costmap);

    private:
        std::mutex mutex_;
        nav2_costmap_2d::Costmap2D* costmap_;
        cv::Mat costmap_mat_;
        // ObstacleArrayPtr obstacles_;
        cv::Mat fg_mask_;
        std::unique_ptr<BackgroundSubtractor> bg_sub_;
        cv::Ptr<BlobDetector> blob_det_;
        //   std::vector<cv::KeyPoint> keypoints_;
        //   rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;
        //   Point_t ego_vel_;

        //   std::string odom_topic_ = "/odom";
        //   bool publish_static_obstacles_ = true;
    }

}

#endif /* COSTMAP_TO_DYNAMIC_OBSTACLES_H_ */