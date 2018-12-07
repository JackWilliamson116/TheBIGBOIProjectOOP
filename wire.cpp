#include "wire.h"

void wire::setGate(gate* gate1) {
	gates.push_back(gate1);
}
void wire::setState(wireValue stat) {
	state = stat;
}
wireValue wire::getState() {
	return state;
}
vector<gate*> wire::getGates() {
	return gates;
}
void wire::addToHistory(int i, wireValue val) {
	history.insert(pair<int, wireValue>(i, val));
}
void wire::print(int fTime) {
	map<int, wireValue>::iterator it= history.begin();
	int totalTime = 0;
	wireValue wv = unknown;
	while(it != history.end()) {
		for (int i = 0; i < it->first; i++) {
			if (wv == unknown) {
				cout << "x";
			}
			else if (wv == low) {
				cout << "_";
			}
			else if (wv == high) {
				cout << "-";
			}
		}
		totalTime = it->first;
		wv = it->second;
		it++;
		
	}
	while((totalTime != fTime)&&(totalTime <=60)){
		if (wv == unknown) {
			cout << "x";
		}
		else if (wv == low) {
			cout << "_";
		}
		else if (wv == high) {
			cout << "-";
		}
		totalTime++;
	}
}