#include <gtest/gtest.h>

#include "certhandler.hpp"

#include <string>

class CerthandlerTest : public ::testing::Test {};

TEST_F(CerthandlerTest, NoErrorOnGetCert) {
  Cert::CerthandlerFactory ch_factory;
  Cert::ICertHandler *ch = ch_factory.create();

  std::string output;
  ch->get_ca_certificates(output);
}
