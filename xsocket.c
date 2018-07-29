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

// implementations goes here.

#ifdef __cplusplus
  }
#endif
