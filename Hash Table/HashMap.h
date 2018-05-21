#pragma once
#include "HashEntry.h"
#define TABLE_SIZE 90

class HashMap {
private:
	HashEntry **table;
public:
	HashMap();
	int get(int key);
	void put(int key, int value);
	~HashMap();

};



