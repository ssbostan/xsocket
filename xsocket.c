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

#ifdef __cplusplus
  extern "C" {
#endif

#include "xsocket.h"

int xstartup() {
  #ifdef XWIN32
    WSADATA wsadata;
    return WSAStartup(MAKEWORD(2, 2), &wsadata); // for using winsock version 2.2 on windows.
  #else
    return 0;
  #endif
}

int xcleanup() {
  #ifdef XWIN32
    return WSACleanup(); // terminates use of winsock library on windows.
  #else
    return 0;
  #endif
}

int xclose(xsocket_t socket) {
  #ifdef XWIN32
    return closesocket(socket); // close socket on windows.
  #else
    return close(socket);
  #endif
}

int xerror() {
  #ifdef XWIN32
    return WSAGetLastError(); // socket errors on windows.
  #else
    return errno; // socket errors on posix.
  #endif
}

xsocket_t xaccept(xsocket_t socket, struct sockaddr *addr, xsocklen_t *addr_len) {
  return accept(socket, addr, addr_len);
}

xsocket_t xsocket(int domain, int type, int protocol) {
  return socket(domain, type, protocol);
}

// implementations goes here.

#ifdef __cplusplus
  }
#endif
