#pragma once
#include <iostream>
#include <map>
#include "wire.h"
#include "gate.h"
#include <iomanip>
#include <ctime>
#include <queue>

using namespace std;
class event;
class circuit {
public:
	void insertWire(string c, wire* w1);
	wire* getWire(int wnum);
	wire* getWire(string wnam);
	bool doesNotExist(int wnum);
	void createGateConnection(wire* in1, wire* in2, wire* out, int delay, gateType type);
	event makeEvent(wire* w1, int time, wireValue val);
	wireValue setWireValue(char c);
	void makeExtraWire(wire* w1);
	void simulate();
	priority_queue<event> getQ() { return q; }
	int getFinalTime() { return finalTime; }
private:
	map<string, wire*> wireMap;
	int pqTB = 0;
	//map<char, wire*>::iterator it;
	vector<wire*> wv;
	int time = 0;
	priority_queue<event> q;
	int finalTime;
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