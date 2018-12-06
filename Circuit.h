#pragma once
#include <iostream>
#include <map>
#include "wire.h"
#include "gate.h"

using namespace std;
class event;
class circuit {
public:
	void insertWire(char c, wire* w1);
	wire* getWire(int wnum);
	wire* getWire(char wnam);
	bool doesNotExist(int wnum);
	void createGateConnection(wire* in1, wire* in2, wire* out, int delay, gateType type);
	event makeEvent(wire* w1, int time, wireValue val);
	wireValue setWireValue(char c);
	int eWC() { return extrawirecount++; }
	void makeExtraWire(wire* w1);
	
private:
	map<char, wire*> wireMap;
	int pqTB = 0;
	//map<char, wire*>::iterator it;
	int extrawirecount = 1;
	vector<wire*> wv;
};

class event {
public:
	event(wire* w1, int time, wireValue val, int pqTieBreaker) : w1(w1), time(time), val(val), pqTieBreaker(pqTieBreaker) {};
	int getTieBreaker() { return pqTieBreaker; }
	int getTime() { return time; }
	wire* getWire() { return w1; }
	wireValue getVal() { return val; }
	friend bool operator<(event e1, event e2);

private:
	wire* w1;
	int time;
	wireValue val;
	int pqTieBreaker;
};