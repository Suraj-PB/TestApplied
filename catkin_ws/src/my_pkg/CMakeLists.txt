cmake_minimum_required(VERSION 2.8.3)
project(my_pkg)


enable_testing()
SET(CMAKE_COLOR_MAKEFILE ON)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg)

## Declare a catkin package
catkin_package(

  LIBRARIES ${PROJECT_NAME}
)



add_definitions (-Wall -Werror -g -DHAVE_PTHREAD -Wno-error=sign-compare -Wno-unused-value -Wno-unused-variable)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O3 -fPIC")

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})


include_directories (
  .
  ${CMAKE_BINARY_DIR}

)

add_subdirectory(third_party/subprocess)







add_executable(main src/main.cpp src/stack_impl.cpp)
target_link_libraries(main PRIVATE ${catkin_LIBRARIES} subprocess_cxx stdc++fs)
