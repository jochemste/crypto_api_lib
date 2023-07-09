include(GoogleTest)

# function to add tests
function(custom_add_test test_target test_name)
  # Define test executable
  add_executable(
    ${test_name}
    ${test_name}.cpp
    )

  # Link test executable to the library
  target_link_libraries(
    ${test_name}
    ${test_target}
    GTest::gtest_main)

  gtest_discover_tests(${test_name})

  # Add memory test
  add_test(
    NAME ${test_name}_memory
    COMMAND /usr/bin/valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all ${CMAKE_BINARY_DIR}/test/${test_name})
endfunction()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/372e81d8141783ff2914349bf6c02819ec08d980.zip
  )
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

##################
# CERTHANDLER TEST
custom_add_test(certhandler test_certhandler)

#################
# CRYPTO API TEST
custom_add_test(crypto_api test_crypto_api)
