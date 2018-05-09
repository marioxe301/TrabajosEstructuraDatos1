#pragma once

class ProyectMethods {
public:
	ProyectMethods(char *, double, double);
	void Create_Airport();
	void Update_Airport();
	void Display_Airports();
	void Delete_Airport();

private:
	char *name;
	double lat;
	double lon;
};