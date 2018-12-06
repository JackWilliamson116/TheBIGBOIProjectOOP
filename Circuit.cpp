#include "Circuit.h"
#include <iomanip>
#include <string>
#include <ctime>
#include <queue>




void circuit::insertWire(char c, wire* w1) {
	wireMap.insert(pair<char,wire*>(c, w1));
}
wire* circuit::getWire(int wnum) {
	map<char, wire*>::iterator it;
	for (it = wireMap.begin(); it->second->getWireNumber() != wnum; ++it){	
	}
	return it->second;
}
bool circuit::doesNotExist(int wnum) {
	for (map<char, wire*>::iterator it = wireMap.begin(); it != wireMap.end(); ++it) {
		if (it->second->getWireNumber() == wnum) {
			return false;
		}
	}
	return true;
}
void circuit::createGateConnection(wire* in1, wire* in2, wire* out, int delay, gateType type) {
	
	gate* ga= new gate(in1, in2, out, delay, type);
	in1->setGate(ga);
	in2->setGate(ga);
}
event* circuit::makeEvent(wire w1, int time, wireValue val) {
	event e(w1, time, val, pqTB);
	++pqTB;
	return &e;
}

wireValue circuit::setWireValue(char c) {
	if (c == '0') {
		return low;
	}
	else if (c == '1') {
		return high;
	}
	else if (c == 'x') {
		return unknown;
	}
}
bool operator<(event e1, event e2) {

	// by default the queue is a MAX queue, so we reverse the comparison
	// from '<' to '>' (see the return statements) to make it a MIN queue
	if (e1.getTime() == e2.getTime()) {
		return e1.getTieBreaker() > e2.getTieBreaker();
	}

	return e1.getTime() > e2.getTime();
}



/*int main() {
	circuit c;
	priority_queue<event*> q;
	wire w(1);

	q.push(c.makeEvent(w, 2, high));


	return 0;
}*/
