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

// implementations goes here.

#ifdef __cplusplus
  }
#endif

#endif
