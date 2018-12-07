#pragma once
#include <iostream>
#include "enums.h"
using namespace std;

class wire;
class gate {
public:
	gate(wire* in1, wire* in2, wire* out, int delay, gateType type) :in1(in1), in2(in2), out(out), delay(delay), type(type) {};
	wireValue eval();
	void setDelay(int del);
	int getDelay();
	wire* getOUT(){return out;}
protected:
	wire* in1;
	wire* in2;
	wire* out;
	int delay;
	gateType type;
};