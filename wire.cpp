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
