#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;


char plg [ 9 ] = {'1','2','3','4','5','6','7','8','9'};//!plansza_gry
char plgs [ 9 ] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};//!plansza_gry_sprawdzajaca
int wyb = 0;//!wybor
int wybw = 0;//!wybor_wlasciwy
char azna = 'x';//!aktywny_znak
int sws = 0;//!sprawdzanie_wygranej_status
int zp = 0;//!zapelnienie_planszy

int swsp = 0;//!sprawdzanie_wygranej_status_pomocowe
int zpp = 0;//!zapelnienie_planszy_pomocwe

void dpg( )//!drukuj_plansze_gry
	{
	system( "CLS" );
	for ( int i = 0; i < 9; i++ )
		{
		if ( i % 3 == 0 )
			cout << endl;
		cout << plg [ i ] << " ";
		}
	cout << "\n\n";
	}

void scwp( )//!sprawdzanie_czy_wygrana_pomocowa
	{
	zpp = 0;
	if ( plgs [ 0 ] == 'o' && plgs [ 1 ] == 'o' && plgs [ 2 ] == 'o' )
		swsp = 2;
	if ( plgs [ 3 ] == 'o' && plgs [ 4 ] == 'o' && plgs [ 5 ] == 'o' )
		swsp = 2;
	if ( plgs [ 6 ] == 'o' && plgs [ 7 ] == 'o' && plgs [ 8 ] == 'o' )
		swsp = 2;
	//!===========================================================
	if ( plgs [ 0 ] == 'o' && plgs [ 3 ] == 'o' && plgs [ 6 ] == 'o' )
		swsp = 2;
	if ( plgs [ 1 ] == 'o' && plgs [ 4 ] == 'o' && plgs [ 7 ] == 'o' )
		swsp = 2;
	if ( plgs [ 2 ] == 'o' && plgs [ 5 ] == 'o' && plgs [ 8 ] == 'o' )
		swsp = 2;
	//!===========================================================
	if ( plgs [ 0 ] == 'o' && plgs [ 4 ] == 'o' && plgs [ 8 ] == 'o' )
		swsp = 2;
	if ( plgs [ 2 ] == 'o' && plgs [ 4 ] == 'o' && plgs [ 6 ] == 'o' )
		swsp = 2;

	}

void swz( )//!samo_wkladanie_znaku
	{
	for ( int i = 0; i < 9; i++ )
		plgs [ i ] = plg [ i ];
	for ( int i = 0; i < 9; i++ )
		{
		if ( plg [ i ] != 'x' && plg [ i ] != 'o' )
			{
			plgs [ i ] = 'o';
			scwp( );
			if ( swsp == 2 ) {
				plg [ i ] = 'o';
				break;
				}
			else
				{
				for ( int a = 0; a < 9; a++ )
					{
					if ( plg [ a ] != 'x' && plgs [ a ] != 'o' )
						{
						plgs [ a ] = 'o';
						scwp( );
						if ( swsp == 2 )
							{
							plg [ i ] = 'o';
							break;
							break;
							}
						else
							{
							plg [ a ] = 'o';
							break;
							break;
							}
						}
					}
				}
			}
		}
	azna = 'x';
	}


void wpz( )//!wybieranie_pola_znaku
	{
	if ( azna == 'x' )
		cin >> wyb;
	if ( azna == 'o' )
		{
		swz( );
		}
	switch ( wyb )
		{
			case 1:wybw = 0; break;
			case 2:wybw = 1; break;
			case 3:wybw = 2; break;
			case 4:wybw = 3; break;
			case 5:wybw = 4; break;
			case 6:wybw = 5; break;
			case 7:wybw = 6; break;
			case 8:wybw = 7; break;
			case 9:wybw = 8; break;
		}
	if ( azna == 'x' && plg [ wybw ] != 'x' && plg [ wybw ] != 'o' )
		{
		plg [ wybw ] = 'x';
		azna = 'o';
		}
	}


void scw( )//!sprawdzanie_czy_wygrana
	{
	zp = 0;
	if ( plg [ 0 ] == 'x' && plg [ 1 ] == 'x' && plg [ 2 ] == 'x' )
		sws = 1;
	if ( plg [ 3 ] == 'x' && plg [ 4 ] == 'x' && plg [ 5 ] == 'x' )
		sws = 1;
	if ( plg [ 6 ] == 'x' && plg [ 7 ] == 'x' && plg [ 8 ] == 'x' )
		sws = 1;
	//!===========================================================
	if ( plg [ 0 ] == 'o' && plg [ 1 ] == 'o' && plg [ 2 ] == 'o' )
		sws = 2;
	if ( plg [ 3 ] == 'o' && plg [ 4 ] == 'o' && plg [ 5 ] == 'o' )
		sws = 2;
	if ( plg [ 6 ] == 'o' && plg [ 7 ] == 'o' && plg [ 8 ] == 'o' )
		sws = 2;
	//!===========================================================
	if ( plg [ 0 ] == 'o' && plg [ 3 ] == 'o' && plg [ 6 ] == 'o' )
		sws = 2;
	if ( plg [ 1 ] == 'o' && plg [ 4 ] == 'o' && plg [ 7 ] == 'o' )
		sws = 2;
	if ( plg [ 2 ] == 'o' && plg [ 5 ] == 'o' && plg [ 8 ] == 'o' )
		sws = 2;
	//!===========================================================
	if ( plg [ 0 ] == 'x' && plg [ 3 ] == 'x' && plg [ 6 ] == 'x' )
		sws = 1;
	if ( plg [ 1 ] == 'x' && plg [ 4 ] == 'x' && plg [ 7 ] == 'x' )
		sws = 1;
	if ( plg [ 2 ] == 'x' && plg [ 5 ] == 'x' && plg [ 8 ] == 'x' )
		sws = 1;
	//!===========================================================
	if ( plg [ 0 ] == 'x' && plg [ 4 ] == 'x' && plg [ 8 ] == 'x' )
		sws = 1;
	if ( plg [ 2 ] == 'x' && plg [ 4 ] == 'x' && plg [ 6 ] == 'x' )
		sws = 1;
	//!===========================================================
	if ( plg [ 0 ] == 'o' && plg [ 4 ] == 'o' && plg [ 8 ] == 'o' )
		sws = 2;
	if ( plg [ 2 ] == 'o' && plg [ 4 ] == 'o' && plg [ 6 ] == 'o' )
		sws = 2;
	for ( int i = 0; i < 9; i++ )
		if ( plg [ i ] != 'x' && plg [ i ] != 'o' )
			zp = 1;
	if ( zp == 0 && sws == 0 )
		sws = 3;

	}

void dnk( )//!drukowanie_napisow_koncowych
	{
	if ( sws == 1 )
		cout << "WYGRANA X" << endl;
	if ( sws == 2 )
		cout << "WYGRANA O" << endl;
	if ( sws == 3 )
		cout << "REMIS" << endl;
	}



int main( )
	{
	dpg( );
	while ( sws == 0 )
		{
		cout << azna << endl;
		wpz( );
		dpg( );
		scw( );
		}
	dnk( );
	return 0;
	}
