#include "Company.h"
#include <iostream>
int main() {
	Company* c = new Company;
	c->Simulate();
	delete c;
}