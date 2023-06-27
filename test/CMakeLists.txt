include(FetchContent)
  FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/372e81d8141783ff2914349bf6c02819ec08d980.zip
    )
  # For Windows: Prevent overriding the parent project's compiler/linker settings
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  FetchContent_MakeAvailable(googletest)

enable_testing()
# Define the test executable
add_executable(test_crypto_api test_crypto_api.cpp)

# Link the test executable to the library
target_link_libraries(
  test_crypto_api
  crypto_api
  GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(test_crypto_api)
