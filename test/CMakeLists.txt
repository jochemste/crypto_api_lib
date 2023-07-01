
include(FetchContent)
  FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/372e81d8141783ff2914349bf6c02819ec08d980.zip
    )
  # For Windows: Prevent overriding the parent project's compiler/linker settings
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  FetchContent_MakeAvailable(googletest)

enable_testing()

# Define test executable
add_executable(
  test_crypto_api
  test_crypto_api.cpp
  )

# Link test executable to the library
target_link_libraries(
  test_crypto_api
  crypto_api
  GTest::gtest_main)

add_test(
  NAME test_crypto_api
  COMMAND test_crypto_api)
add_test(
  NAME test_crypto_api
  COMMAND /usr/bin/valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all ${CMAKE_BINARY_DIR}/test/test_crypto_api)

# Define test executable
add_executable(
  test_certhandler
  test_certhandler.cpp)

# Link test executable to the library
target_link_libraries(
  test_certhandler
  certhandler
  GTest::gtest_main)

add_test(
  NAME test_certhandler
  COMMAND test_certhandler)
add_test(
  NAME test_certhandler
  COMMAND /usr/bin/valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all ${CMAKE_BINARY_DIR}/test/test_certhandler)


include(GoogleTest)
gtest_discover_tests(test_crypto_api test_certhandler)
