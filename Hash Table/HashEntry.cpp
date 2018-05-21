#include "HashEntry.h"

HashEntry::HashEntry(int key, int value) {
	this->key = key;
	this->value = value;
}

int HashEntry::getKey() {
	return this->key;
}

int HashEntry::getValue() {
	return this->value;
}

