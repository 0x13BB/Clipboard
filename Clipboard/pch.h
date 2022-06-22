#pragma once

#include <iostream>
#include <thread>

// data structures
#include <string>
#include <vector>
#include <array>
#include <chrono>
#include <ctime>


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