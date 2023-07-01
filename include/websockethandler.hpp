#ifndef WEBSOCKETHANDLER_HPP
#define WEBSOCKETHANDLER_HPP

class IWebSocketHandler {
public:
  inline IWebSocketHandler()          = delete;
  virtual inline void connect() const = 0;
};

class WebSocketHandler : public IWebSocketHandler {
  WebSocketHandler();
  void connect() const override;
};

#endif // WEBSOCKETHANDLER
