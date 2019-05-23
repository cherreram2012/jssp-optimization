#include <iostream>
#include "../jssp.model/CHndFile.h"

using namespace std;

int main (void)
{
	int P, M;
	CHndFile A;

	A.SetPath("datafile\\JSSP\\jobshop\\4x4_1.txt");
	A.ReadInstanceSize(&P, &M);

	cout << "FILE: " << A.GetPath() << endl << endl;

	cout << "METODO GRASP" << endl;
	
	return 0;
}