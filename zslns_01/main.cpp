#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

int igl10 = 0;//!int_glowna_liczba_dziesietna
string gl7 = "";//!glowna_liczba_siodemkowa
string gl3 = "0000000000";//!glowna_liczba_trojkowa
string pl3 = "";//!pomocna_liczba_trojkowa
int b = 0;

void z3n10( )//!zamiana_z_trojkowego_na_dziesiatkowy
	{
	cin >> pl3;
	for ( int i = 0; i < pl3.length( ); i++ )
		{
		gl3.pop_back( );
		}
	for ( int i = 0; i < pl3.length( ); i++ )
		{
		gl3.push_back( pl3 [ i ] );
		}
	igl10 = stoi( gl3.substr( 9, 1 ) ) + stoi( gl3.substr( 8, 1 ) ) * 3 + stoi( gl3.substr( 7, 1 ) ) * 9 + stoi( gl3.substr( 6, 1 ) ) * 27 + stoi( gl3.substr( 5, 1 ) ) * 81 + stoi( gl3.substr( 4, 1 ) ) * 243 + stoi( gl3.substr( 3, 1 ) ) * 729 + stoi( gl3.substr( 2, 1 ) ) * 2187 + stoi( gl3.substr( 1, 1 ) ) * 6561 + stoi( gl3.substr( 0, 1 ) ) * 19683;
	cout << igl10 << endl;
	}

void z10n7( )//!zamiana_z_dziesietkowego_na_siodemkowy
	{
	while ( b != 1 )
		{
		gl7 = to_string( igl10 % 7 ) [ 0 ] + gl7;
		igl10 = igl10 / 7;
		if ( igl10 == 0 )
			b = 1;
		}
	cout << gl7 << endl;
	}

int main( )
	{
	system( "CLS" );
	z3n10( );
	z10n7( );
	return 0;
	}
