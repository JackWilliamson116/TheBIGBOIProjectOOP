#include "gate.h"
#include "wire.h"

wireValue gate::eval() {
	switch (type) {
		case AND : 
			if (in1->getState() == unknown || in2->getState() == unknown) {
				return unknown;
			}
			if (in1->getState() == in2->getState()) {
				if (in1->getState() == high) {
					return high;
				}
				return low;
			}
			else {
				return low;
			}
		case NAND:
			if (in1->getState() == in2->getState()) {
				if (in1->getState() == unknown) {
					return unknown;
				}
				if (in1->getState() == high) {
					return low;
				}
			}
			return high;
		case OR:
			if (in1->getState() == in2->getState()) {
				if (in1->getState() == unknown) {
					return unknown;
				}
				else if (in1->getState() == low) {
					return low;
				}
				return high;
			}
			if (in1->getState() == high || in2->getState() == high) {
				return high;
			}
			else {
				return unknown;
			}
		case NOR:
			if (in1->getState() == unknown || in2->getState() == unknown) {
				return unknown;
			}
			if (in1->getState() == in2->getState()) {
				if (in1->getState() == low) {
					return high;
				}
			}
			return low;
		case XOR:
			if (in1->getState() == unknown || in2->getState() == unknown) {
				return unknown;
			}
			if (in1->getState() != in2->getState()) {
				return low;
			}
			return high;
		case XNOR:
			if (in1->getState() == unknown || in2->getState() == unknown) {
				return unknown;
			}
			if (in1->getState() == in2->getState()) {
				return high;
			}
			return low;
		case NOT:
			if (in1->getState() == unknown) {
				return unknown;
			}
			if (in1->getState() == low) {
				return low;
			}
			return high;
	}
}
void gate::setDelay(int del) {
	delay = del;
}
int gate::getDelay() {
	return delay;
}