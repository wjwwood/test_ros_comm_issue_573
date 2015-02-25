cmake_minimum_required(VERSION 2.8.3)
project(test_ros_comm_issue_573)

cmake_policy(SET CMP0054 OLD)

find_package(catkin REQUIRED COMPONENTS roscpp std_srvs)

catkin_package()

include_directories(${catkin_INCLUDE_DIRS})

add_executable(service_client src/${PROJECT_NAME}/service_client.cpp)
add_dependencies(service_client ${catkin_EXPORTED_TARGETS})
target_link_libraries(service_client ${catkin_LIBRARIES})

add_executable(service_server src/${PROJECT_NAME}/service_server.cpp)
add_dependencies(service_server ${catkin_EXPORTED_TARGETS})
target_link_libraries(service_server ${catkin_LIBRARIES})

# if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
#     message("Using AddressSanitizer")
#     set(santizier_flags "-O1 -g -fsanitize=address -fno-omit-frame-pointer")
#     set_target_properties(service_client PROPERTIES COMPILE_FLAGS ${santizier_flags})
#     set_target_properties(service_server PROPERTIES COMPILE_FLAGS ${santizier_flags})
# endif()

install(TARGETS service_client service_server
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
