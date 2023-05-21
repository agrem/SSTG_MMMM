#ifndef wsp_h
#define wsp_h

#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <windows.h>

extern BOOL bEnd;

#define IP_TARGET "192.168.10.206"
#define SRC_PORT "9000"
#define DST_PORT "8000"

SOCKET MakeSocket(WORD wPort);
BOOL SendData(SOCKET sock, WORD wDstPort);
DWORD WINAPI RecvThread(LPVOID pParm);

#endif