#include <gtest/gtest.h>

#include "certhandler.hpp"

#include <iostream>
#include <string>

class CerthandlerTest : public ::testing::Test {};

TEST_F(CerthandlerTest, NoErrorOnGetCert) {
  Cert::CerthandlerFactory ch_factory;
  Cert::ICertHandler *ch = ch_factory.create();
  std::string ca_certs;

  ASSERT_NO_THROW(ch->get_ca_certificates(ca_certs));

  ASSERT_FALSE(ca_certs.empty());
}
