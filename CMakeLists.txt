cmake_minimum_required(VERSION 3.12)

project(IntentGenerator)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})



