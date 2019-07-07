#include <map>
#include <cstring>
#include <iostream>
#include "CTerminator.h"
#include "CStatistics.h"
#include "CGrasp_PR.h"
#include "CGraspBasic.h"
#include "CPathRelinking.h"
#include "../jssp.model/CHndFile.h"
#include "../jssp.model/CPieceCollection.h"
#include "../jssp.model/CMachineCollection.h"
#include "../jssp.heuristics/CSetOperator.h"
#include "../jssp.heuristics/CLocalSearch.h"
#include "../jssp.heuristics/CNeighborhood.h"
#include "../jssp.heuristics/CRestrictedNeighbor.h"
#include "../chm.utilities/CustomConsole.h"
#include "../chm.utilities/PrecisionClock.h"

using namespace std;

map<char *, char *> instances = {										 // +----------------------+------------------+------------------+------------------+
	/*** Complexidade baixa ***/											 // | -- INSTANTCE_SIZE -- | --LOWER_BOUND -- | --UPPER_BOUND -- | -- BEST FOUND -- |
	{"ft06", "..\\datafile\\JSSP\\jobshop\\ft06.txt"}, // |				 6 x 6				 |			  *55				|				----			 |			  *55				|
	{"la01", "..\\datafile\\JSSP\\jobshop\\la01.txt"}, // |				10 x 5				 |			 ----				|				----			 |			 *666		 		|
	{"la02", "..\\datafile\\JSSP\\jobshop\\la02.txt"}, // |				10 x 5				 |			 ----				|				----			 |			 *655				|
	{"la03", "..\\datafile\\JSSP\\jobshop\\la03.txt"}, // |				10 x 5				 |			 ----				|				----			 |			 *597				|
	{"la04", "..\\datafile\\JSSP\\jobshop\\la04.txt"}, // |				10 x 5				 |			 ----				|				----			 |			 *590				|
	{"la05", "..\\datafile\\JSSP\\jobshop\\la05.txt"}, // |				10 x 5				 |			 ----				|				----			 |			 *593				|
	{"la06", "..\\datafile\\JSSP\\jobshop\\la06.txt"}, // |				15 x 5				 |			 ----				|				----			 |			 *926				|
	/*** Complexidade media ***/											 // +----------------------+------------------+------------------+------------------+
	{"ft20", "..\\datafile\\JSSP\\jobshop\\ft20.txt"}, // |				20 x 5				 |		  *1165				|				----			 |			*1165				|
	{"la15", "..\\datafile\\JSSP\\jobshop\\la15.txt"}, // |				20 x 5				 |			 ----				|				----			 |			*1207				|
	{"la16", "..\\datafile\\JSSP\\jobshop\\la16.txt"}, // |				10 x 10				 |			 ----				|				----			 |			 *945				|
	{"la17", "..\\datafile\\JSSP\\jobshop\\la17.txt"}, // |				10 x 10				 |			 ----				|				----			 |			 *784				|
	{"la18", "..\\datafile\\JSSP\\jobshop\\la18.txt"}, // |				10 x 10				 |			 ----				|				----			 |			 *848				|
	{"la19", "..\\datafile\\JSSP\\jobshop\\la19.txt"}, // |				10 x 10				 |			 ----				|				----			 |			 *842				|
	{"la20", "..\\datafile\\JSSP\\jobshop\\la20.txt"}, // |				10 x 10				 |			 ----				|				----			 |			 *902				|
	/*** Complexidade alta ***/												 // +----------------------+------------------+------------------+------------------+
	{"ft10", "..\\datafile\\JSSP\\jobshop\\ft10.txt"}, // |				10 x 10				 |			 *930				|				----			 |			 *930				|
	{"la38", "..\\datafile\\JSSP\\jobshop\\la38.txt"}, // |				15 x 15				 |			 1196				|				----			 |			 1209				|
	{"la39", "..\\datafile\\JSSP\\jobshop\\la39.txt"}, // |				15 x 15				 |			 ----				|				----			 |			 1233				|
	{"la40", "..\\datafile\\JSSP\\jobshop\\la40.txt"}, // |				15 x 15				 |			 1222				|				----			 |			*1222				|
	{"abz7", "..\\datafile\\JSSP\\jobshop\\abz7.txt"}, // |				20 x 15				 |			  656				|				 656			 |			----				|
	{"abz8", "..\\datafile\\JSSP\\jobshop\\abz8.txt"}, // |				20 x 15				 |			  646				|				 665			 |			----				|
	{"abz9", "..\\datafile\\JSSP\\jobshop\\abz9.txt"}  // |				20 x 15				 |			  662				|				 679			 |			----				|
};																								 // +----------------------+------------------+------------------+------------------+

int main (void)
{
	CustomConsole::ForegroundColor(ColorDarkCyan);
	cout << "+------------------------------------------------------+" << endl
			 << "| PROJETO: Metaheuristica GRASP aplicada ao Scheduling |" << endl
			 << "+------------------------------------------------------+" << endl << endl;
	CustomConsole::LastState();
	
	try
	{

	}
	catch (std::exception e) {
		CustomConsole::ForegroundColor(ColorRed);
		cout << "EXCEPTION CAPTURADA: " << endl << " - " << e.what() << endl;
		CustomConsole::LastState();
	}
	
	cout << endl << endl;
	system("pause");

	return 0;
}
