#include "iostream"
#include "../jssp.model/CHndFile.h"

using namespace std;

void main (void)
{
	CHndFile A;
	int P, M;

	A.SetPath("datafile\\JSSP\\jobshop\\4x4_1.txt");
	A.ReadInstanceSize(&P, &M);	
	cout << "FILE: " << A.GetPath() << endl << endl;

	cout << "METODO DE BUSQUEDA TABU" << endl;
	//system("pause");
}