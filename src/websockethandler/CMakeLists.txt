set(SRCS
  websockethandler.cpp
  )

add_library(
  websockethandler
  ${SRCS})

target_include_directories(
  websockethandler
  PUBLIC
  #$<INSTALL_INTERFACE:include>
  ${CMAKE_CURRENT_LIST_DIR}
  )
