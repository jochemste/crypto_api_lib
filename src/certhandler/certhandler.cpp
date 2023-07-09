#include "certhandler.hpp"

#ifdef __linux__
#include "certhandlerlinux.hpp"
#elif _WIN32
#elif __APPLE__
#endif

Cert::ICertHandler *Cert::CerthandlerFactory::create() {
#ifdef __linux__
  static Cert::CertHandlerLinux ch;
  return &ch;
#elif _WIN32
#error Windows CertHandler is not implemented
#elif __APPLE__
#error Apple CertHandler is not implemented
#endif
}
