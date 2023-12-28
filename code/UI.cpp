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
	cout << "Current Time(Hour:Min) ==> " << cp->getHour() << ":" << cp->getMinutes() << endl;
	cout << "=================" << "Station #" << cp->getNumberOfStations() << "=================" << endl;

}
