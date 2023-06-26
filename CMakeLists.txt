cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS -Wall -Wextra)

# Project name and version
project(crypto_api VERSION 0.1.0)

option(BuildTest "BuildTest" OFF)
option(BuildExample "BuildExample" OFF)

# Add the include directory to the build
message("Adding the include directory")
include_directories(include)

# Add the src directory to the build
message("Running on the src directory")
add_subdirectory(src)

if(BuildTest)

  # Add googletest to the build
  #message("Running on the lib/googletest directory")
  #add_subdirectory(lib/googletest)

  # Add the test directory to the build
  message("Running on the test directory")
  add_subdirectory(test)
endif()

if(BuildExample)
  #Add the examples directory to the build
  #message("Running on the examples directory")
  #add_subdirectory(examples)
endif()

# Install the headers and library
install(DIRECTORY include/ DESTINATION include)
install(TARGETS crypto_api DESTINATION lib)
