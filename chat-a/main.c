#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <windows.h>

BOOL bEnd = FALSE;

#include "wsp.h"

int main( ) {
  WSADATA wsaData = {0};
  SOCKET sock;
  WORD wSrcPort, wDstPort;
  wSrcPort = (WORD) atoi( SRC_PORT );
  wDstPort = (WORD) atoi( DST_PORT );
  WSAStartup( MAKEWORD( 2, 2 ), &wsaData );
  sock = MakeSocket( wSrcPort );


  if ( sock ) {
    HANDLE hThread = CreateThread( NULL, 0, RecvThread, (PVOID) sock, 0, NULL );

    while ( 1 ) {
      if ( !SendData( sock, wDstPort ) )
        break;
      }
    bEnd = TRUE;
    closesocket( sock );

    if ( WaitForSingleObject( hThread, 3000 ) == WAIT_TIMEOUT ) {
      printf( "Error : Thread End\n" );
      TerminateThread( hThread, 0 );
      }
    }


  WSACleanup( );
  }