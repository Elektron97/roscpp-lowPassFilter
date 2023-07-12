cmake_minimum_required(VERSION 3.0.2)
project(roscpp_lowpass_filter)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS roscpp
)

include_directories(
 include
  ${catkin_INCLUDE_DIRS}
)

#### Low Pass Library ####
add_library(${PROJECT_NAME} src/LowPassFilter.cpp)
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES})

#### Export Library ####
install(
  TARGETS ${PROJECT_NAME}
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
)

install(
  DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
)