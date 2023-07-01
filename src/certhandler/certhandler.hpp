#ifndef CERTHANDLER_HPP
#define CERTHANDLER_HPP

#include <filesystem>
#include <fstream>
#include <string>

namespace fs = std::filesystem;

/// Namespace for certificate related classes, etc
namespace Cert {

/// Exception class for certificate errors
class CertException : public std::exception {
public:
  CertException(const char *message) : msg(message) {}
  CertException(CertException const &) noexcept = default;
  ~CertException() override                     = default;

  CertException &operator=(CertException const &) noexcept = default;

  const char *what() const noexcept override { return msg; }

protected:
  const char *msg;

private:
};

/// Interface for certificate handling class
class ICertHandler {
public:
  virtual void get_ca_certificates(std::string &ca_certs);

protected:
private:
};

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
#endif
