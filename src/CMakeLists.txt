# Define the library
add_library(crypto_api crypto_api.cpp)

# Set the library version
set_target_properties(crypto_api PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(crypto_api PROPERTIES SOVERSION 1)

set(BOOST_INCLUDE_LIBRARIES thread filesystem system beast)
set(BOOST_ENABLE_CMAKE ON)

include(FetchContent)
FetchContent_Declare(
  Boost
  GIT_REPOSITORY https://github.com/boostorg/boost.git
  GIT_TAG boost-1.82.0
)
FetchContent_MakeAvailable(Boost)

target_link_libraries(crypto_api PRIVATE Boost::beast)

# Make the library public
target_include_directories(crypto_api PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
)
