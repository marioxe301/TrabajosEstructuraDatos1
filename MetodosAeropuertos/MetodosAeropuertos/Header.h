#pragma once
#include <string>

class ProyectMethods {
public:
	ProyectMethods();
	void Create_Airport(const char *,double,double);
	void Read_Airport(char*,int);
	int Lenght_Arch();
	void Delete_Airport(const char *);
	void Update_Airport(const char*, const char*, double, double);
	bool Exist_Airport(const char *);

	int Create_Route(const char *, const char *, double);
	void Read_Route(char *, int);
	int Lenght_R();
	void Delete_Route(const char *,const char*);
	void Update_Route(const char*, const char *, const char *, double);
	void Update_IDroute(const char *,const char *);
};