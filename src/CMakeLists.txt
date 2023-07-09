# Define source files
set(SRCS
  crypto_api.cpp
  )

# Define the library
add_library(
  ${PROJECT_NAME}
  ${SRCS}
  )

# Set the library version
set_target_properties(crypto_api PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(crypto_api PROPERTIES SOVERSION 1)

set(BOOST_INCLUDE_LIBRARIES beast)
set(BOOST_ENABLE_CMAKE ON)

include(FetchContent)
FetchContent_Declare(
  Boost
  GIT_REPOSITORY https://github.com/boostorg/boost.git
  GIT_TAG boost-1.82.0
)
FetchContent_MakeAvailable(Boost)

add_subdirectory(certhandler)
add_subdirectory(websockethandler)

if (BuildTest)
  target_link_libraries(
    crypto_api
    PUBLIC
    certhandler
    PRIVATE
    Boost::beast)
else()
  target_link_libraries(
    crypto_api
    PRIVATE
    Boost::beast
    certhandler)
endif()

# Make the library public
target_include_directories(
  crypto_api
  PUBLIC
  #$<INSTALL_INTERFACE:include>
  #$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
)
