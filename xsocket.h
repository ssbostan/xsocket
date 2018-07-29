/*
 *  XSocket is a cross-platform socket library.
 *
 *  Copyright (c) 2018 Saeid Bostandoust <ssbostan@gmail.com>
 *
 *  BSD 3-Clause "New" or "Revised" License.
 *
 *  @link http://bostandoust.ir/
 *  @link http://gitlab.com/ssbostan/XSocket/
 *
 */

#ifndef __XSOCKET_H__
#define __XSOCKET_H__

#ifdef __cplusplus
  extern "C" {
#endif

#ifdef _WIN32
  #define XWIN32 // if operating system is windows.
#endif

#ifdef XWIN32
  #include <winsock2.h>
  #include <ws2tcpip.h>
#else
  #include <unistd.h>
  #include <sys/socket.h>
  #include <arpa/inet.h>
  #include <netinet/in.h>
  #include <netdb.h>
#endif

#ifdef XWIN32
  #pragma comment(lib, "Ws2_32.lib") // tell linker to link winsock library.
#endif

#ifdef XWIN32
  #define XSHUT_RECV SD_RECEIVE
  #define XSHUT_SEND SD_SEND
  #define XSHUT_BOTH SD_BOTH
  #define XSOCKET_INVALID INVALID_SOCKET
  #define XSOCKET_ERROR SOCKET_ERROR
  typedef SOCKET xsocket_t;
  typedef int xsocklen_t;
#else
  #define XSHUT_RECV SHUT_RD
  #define XSHUT_SEND SHUT_WR
  #define XSHUT_BOTH SHUT_RDWR
  #define XSOCKET_INVALID -1
  #define XSOCKET_ERROR -1
  typedef int xsocket_t;
  typedef socklen_t xsocklen_t;
#endif

int xstartup();
int xcleanup();

// implementations goes here.

#ifdef __cplusplus
  }
#endif

#endif
