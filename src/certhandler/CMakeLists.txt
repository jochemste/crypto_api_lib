set(SRCS
  certhandler.cpp
  certhandlerlinux.cpp
  )

add_library(
  certhandler
  ${SRCS})

target_include_directories(
  certhandler
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
  )
