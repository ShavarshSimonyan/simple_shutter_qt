cmake_minimum_required(VERSION 2.6)
 
set(CMAKE_CXX_FLAGS "-Wall -fPIC -std=c++11")
# Locate GTest
find_package(GTest REQUIRED)
# Find the QtWidgets library
find_package(Qt5 COMPONENTS Widgets Core Sql REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} ${Qt5Widgets_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(executeTests main.cpp ../db_handling/dbData.cpp)
target_link_libraries(executeTests ${GTEST_LIBRARIES} Qt5::Widgets Qt5::Sql Qt5::Core pthread)
