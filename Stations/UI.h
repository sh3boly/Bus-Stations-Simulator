#pragma once
#include <iostream>
#include "Company.h"
using namespace std;
class Company;
class UI
{
	Company* cp;
	int mode; // 0 for silent 1 for interavtive.
public:
	UI(Company *c);
	void printSilent();
	void printInteractive();
	int getMode();
	void setMode();
};

