#pragma once
#include <iostream>
#include "Company.h"
using namespace std;
class Company;
class UI
{
	Company* cp;
public:
	UI(Company *c);
	void printSilent();
	void printInteractive();
};

