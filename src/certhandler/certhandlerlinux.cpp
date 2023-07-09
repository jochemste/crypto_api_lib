#include "certhandlerlinux.hpp"

// PUBLIC

Cert::CertHandlerLinux::~CertHandlerLinux() {
  if (m_filestream.is_open()) {
    close_file();
  }
}

void Cert::CertHandlerLinux::get_ca_certificates(std::string &ca_certs) {
  try {
    open_file(m_ca_cert_path);
    read_file(ca_certs);
    close_file();
  } catch (Cert::CertException &exc) {
    throw(exc);
  }
}

// PRIVATE

void Cert::CertHandlerLinux::open_file(const fs::path &file_path) {
  m_filestream.open(file_path);
  if (!m_filestream.is_open()) {
    throw Cert::CertException("Certificate file could not be opened");
  }
}

void Cert::CertHandlerLinux::close_file() { m_filestream.close(); }

void Cert::CertHandlerLinux::read_file(std::string &output) {
  output = "";

  while (m_filestream) {
    output += m_filestream.get();
  }
}
