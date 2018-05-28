#include "Header.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
	ProyectMethods pm;
	string a = "hola";
	char *ab = new char[300];

	pm.Read_Airport(ab, 1);

	cout << ab << endl;
	
	////pm.Delete_Airport("TGS");

	
	/*cout << pm.Read_Airport(1)<<endl;*/
	//pm.Create_Airport(m, 23, 45);

	//cout << pm.Read_Airport(2);
	//cout << pm.Lenght_Arch();
	
	/*string buffer("46.45 904.45");
	size_t sz;

	double nombre = stod(buffer, &sz);
	double nm = stod(buffer.substr(sz));

	cout << nombre << "\t" << nm;
	*/
	system("pause");
}