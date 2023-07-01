#include <gtest/gtest.h>

#include "crypto_api.hpp"

class CryptoAPITest : public ::testing::Test {};

TEST_F(CryptoAPITest, DoSomething) {
  DoSomething ds;
  ASSERT_EQ(0, 0);
}
