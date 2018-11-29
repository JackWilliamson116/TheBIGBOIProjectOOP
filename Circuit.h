#pragma once
#include <iostream>
#include <map>
#include "wire.h"

using namespace std;

class circuit {
public:
	void insertWire(char c, wire* w1);
private:
	map<char, wire*> wireMap;
};