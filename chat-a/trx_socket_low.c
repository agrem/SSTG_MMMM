#include "wsp.h"


SOCKET MakeSocket( WORD wPort ) {
	SOCKET sock = (SOCKET) NULL;
	SOCKADDR_IN Addr = {0};

	sock = socket( AF_INET, SOCK_DGRAM, IPPROTO_UDP );
	if ( sock == INVALID_SOCKET ) {
		return (SOCKET) NULL;
		}

	Addr.sin_family = AF_INET;
	Addr.sin_port = htons( wPort );
	Addr.sin_addr.s_addr = INADDR_ANY;

	if ( bind( sock, (SOCKADDR*) &Addr, sizeof( Addr ) ) == SOCKET_ERROR ) {
		closesocket( sock );
		return (SOCKET) NULL;
		}
	return sock;
	}


BOOL SendData( SOCKET sock, WORD wDstPort )
	{
	SOCKADDR_IN SendAddr = {0};
	char buf [ 1024 ];

	SendAddr.sin_family = AF_INET;
	SendAddr.sin_port = htons( wDstPort );
	SendAddr.sin_addr.s_addr = inet_addr( IP_TARGET );

	printf( "Enter : " );
	fgets( buf, 1024, stdin );

	if ( buf [ 0 ] == 'q' )
		return FALSE;

	sendto( sock, buf, strlen( buf ), 0, (SOCKADDR*) &SendAddr, sizeof( SendAddr ) );

		return TRUE;
	}


    DWORD WINAPI RecvThread( LPVOID pParm )
	{
	SOCKET sock = (SOCKET) pParm;
	SOCKADDR_IN RecvAddr = {0};
	int iRet, iRecvSize;
	char buf [ 1024 ];

	while( !bEnd)
		{
		iRecvSize = sizeof( RecvAddr );
		iRet = recvfrom( sock, buf, 1024, 0, (SOCKADDR *) &RecvAddr, &iRecvSize );

		if ( iRet == SOCKET_ERROR )
			continue;

		buf [ iRet ] = '\0';
		printf( "[%s:%d] : %s", inet_ntoa( RecvAddr.sin_addr ), htons( RecvAddr.sin_port ), buf );
		}

	printf( "Recv Thread End\n" );

	return 0;
	}