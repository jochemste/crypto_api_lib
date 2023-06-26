# Define the library
add_library(crypto_api crypto_api.c)

# Set the library version
set_target_properties(crypto_api PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(crypto_api PROPERTIES SOVERSION 1)

# Make the library public
target_include_directories(crypto_api PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
)
