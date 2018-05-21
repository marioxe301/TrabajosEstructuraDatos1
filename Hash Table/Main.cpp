#include <iostream>
#include "HashMap.h"

int main() {
	HashMap	*mn = new HashMap;
	mn->put(1, 4);
	mn->put(1, 5);
	mn->put(1, 6);

	std::cout<< mn->get(1);

	return 0;
}