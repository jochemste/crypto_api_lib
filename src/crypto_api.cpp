#include "crypto_api.hpp"

#include <boost/beast/websocket.hpp>
#include <iostream>

namespace beast = boost::beast;

DoSomething::DoSomething() { std::cout << "testing\n"; };
