#include "UI.h"

UI::UI(Company* c)
{
	cp = c;
}

void UI::printSilent()
{
	cout << "Silent Mode" << endl << "Simulation Starts..." << endl << "Simulation ends, Output file created" << endl;
	
}

void UI::printInteractive()
{
	char c;
	int numberOfStations;
	numberOfStations = cp->getNumberOfStations();
	
	for (int i = 0; i < numberOfStations; i++) {
		cout << "Current Time(Hour:Min) ==> " << cp->getHour() << ":" << cp->getMinutes() << endl;
		cout << "=================" << "Station #" << i << "=================" << endl;
		cout << cp->getStation(i);
		cout << "Press any key to continue...." << endl;
		cin >> c;
	}

}

int UI::getMode()
{
	return mode;
}

void UI::setMode()
{
	cout << "Please choose the printing mode(0 for silent / 1 for interactive): " << endl;
	cin >> mode;
}
