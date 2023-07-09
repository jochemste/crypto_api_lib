#ifndef CERTHANDLERLINUX_HPP
#define CERTHANDLERLINUX_HPP

#include "certhandler.hpp"

#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

namespace Cert {

/// Implementation of ICertHandler for Linux systems
class CertHandlerLinux : public ICertHandler {
public:
  ~CertHandlerLinux();
  void get_ca_certificates(std::string &ca_certs);

protected:
  void open_file(const fs::path &file_path);
  void read_file(std::string &output);
  void close_file();

private:
  std::ifstream m_filestream;
  const fs::path m_ca_cert_path = "/etc/ssl/certs/ca-certificates.crt";
};
} // namespace Cert

#endif // CERTHANDLERLINUX_HPP
