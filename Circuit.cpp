#include "Circuit.h"

void circuit::insertWire(char c, wire* w1) {
	wireMap.insert(pair<char,wire*>(c, w1));
}