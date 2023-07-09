#ifndef CERTHANDLER_HPP
#define CERTHANDLER_HPP

#include <string>

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
  virtual void get_ca_certificates(std::string &ca_certs) = 0;

protected:
private:
};

class CerthandlerFactory {
public:
  ICertHandler *create();

protected:
private:
};

} // namespace Cert
#endif
