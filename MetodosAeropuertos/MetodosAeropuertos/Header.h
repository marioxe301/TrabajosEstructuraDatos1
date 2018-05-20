#pragma once

class ProyectMethods {
public:
	ProyectMethods(char *, double, double);
	int Create_Airport();
	int Update_Airport();
	int Display_Airports();
	int Delete_Airport();
	bool Exist_Airport();


private:
	char *name;
	double lat;
	double lon;
};