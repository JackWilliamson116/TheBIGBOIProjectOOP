#include "Circuit.h"
#include <iomanip>
#include <string>
#include <ctime>
#include <queue>




void circuit::insertWire(string c, wire* w1) {
	wireMap.insert(pair<string,wire*>(c, w1));
	wv.push_back(w1);
}
void circuit::makeExtraWire(wire* w1) {
	wv.push_back(w1);
}
wire* circuit::getWire(int wnum) {
	/*map<char, wire*>::iterator it;
	for (it = wireMap.begin(); it->second->getWireNumber() != wnum; ++it)
	{
		//This function is left blank intentionally.
	}
	return it->second;*/
	return wv.at(wnum - 1);
}
wire* circuit::getWire(string wnam) {
	return wireMap[wnam];
}
bool circuit::doesNotExist(int wnum) {
	/*for (map<char, wire*>::iterator it = wireMap.begin(); it != wireMap.end(); ++it) {
		if (it->second->getWireNumber() == wnum) {
			return false;
		}
	}
	return true;*/
	for (int i = wv.size()-1; i > 0; i--) {
		if (wv.at(i)->getWireNumber() == wnum) {
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

event circuit::makeEvent(wire* w1, int time, wireValue val) {
	event e(w1, time, val, pqTB);
	++pqTB;
	q.push(e);
	return e;
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
void circuit::simulate() {
	while (!q.empty()) {//goes through each event
		event tempEvent = q.top();//takes the top event in the queue and makes it a temp event
		cout << tempEvent.getTime() << endl;
		vector<gate*> g = tempEvent.getWire()->getGates();
		time = tempEvent.getTime();
		for (int i = tempEvent.getWire()->getGates().size()-1; i >= 0; i--) {//goes through each gate
			wireValue wv1 = g.at(i)->eval();//sets wirevalue 1 (output before the change)
			cout << "iteration " << i << endl << "wv1 = " << wv1 << endl;
			tempEvent.getWire()->setState(tempEvent.getVal());//changes the wires value
			tempEvent.getWire()->addToHistory(tempEvent.getTime(), tempEvent.getVal());
			cout << "wire state " << tempEvent.getWire()->getState();
			wireValue wv2 = g.at(i)->eval();//sets wirevalue 2 (output after the change)
			cout << "wv2 = " << wv2 << endl;
			if (wv1 != wv2) {//if the outputs are different
				cout << "made a new event!" << endl;
				q.push(makeEvent(g.at(i)->getOUT(), g.at(i)->getDelay() + time, wv2));//add a new event to the pq
			}
		}
		finalTime = tempEvent.getTime();
		cout << finalTime << endl << endl << endl;
		q.pop();
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


