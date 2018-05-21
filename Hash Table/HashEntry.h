#pragma once
class HashEntry {
private:
	int key;
	int value;
public:
	HashEntry(int, int);

	int getKey();

	int getValue();
};