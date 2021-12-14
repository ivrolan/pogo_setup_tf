#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

// TODO: measure pogo dimensions
#define X_DIFF 0.0
#define Y_DIFF 0.0
#define Z_DIFF 0.2

// rotation of pi in Z axis
#define X_QUAT 0
#define Y_QUAT 0
#define Z_QUAT 1
#define W_QUAT 0


int main(int argc, char** argv){
  ros::init(argc, argv, "pogo_tf_publisher");
  ros::NodeHandle n;

  ros::Rate r(100);

  tf::TransformBroadcaster broadcaster;

  while(n.ok()){
    broadcaster.sendTransform(
      tf::StampedTransform(
        tf::Transform(tf::Quaternion(X_QUAT, Y_QUAT, Z_QUAT, W_QUAT), tf::Vector3(X_DIFF, Y_DIFF, Z_DIFF)),
        // TODO instead of hardcoding the name frames we should use parameters that change in the launch file  
        ros::Time::now(),"base_link", "laser"));
    r.sleep();
  }
}
