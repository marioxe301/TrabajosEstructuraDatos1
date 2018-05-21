#include"HashMap.h"

HashMap::HashMap() {
	table = new HashEntry*[TABLE_SIZE];
	for (int i = 0; i < TABLE_SIZE; i++) {
		table[i] = 0;
	}
}

int HashMap::get(int key) {
	int hash = (key % TABLE_SIZE);
	while (table[hash] != 0 && table[hash]->getKey() != key) {
		hash = (hash + 1) % TABLE_SIZE;
	}

	if (table[hash] == 0) {
		return -1;
	}
	else {
		return table[hash]->getValue();
	}

}

void HashMap::put(int key, int value) {
	int hash = (key % TABLE_SIZE);
	while (table[hash] != 0 && table[hash]->getKey() != key) {
		hash = (hash + 1) % TABLE_SIZE;
	}

	if (table[hash] != 0) {
		delete table[hash];
	}

	table[hash] = new HashEntry(key, value);
}

