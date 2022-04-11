#pragma once

#include <iostream>

// data structures
#include <string>
#include <chrono>
// api
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <Windows.h>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iphlpapi.h>
#include "PerfTimer.h"


#pragma comment(lib, "Ws2_32.lib")