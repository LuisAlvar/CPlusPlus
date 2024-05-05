#include <iostream>
#include <iomanip>
#include <string>

#include "travelclock.h"
using namespace std;


int main()
{
  Clock clock1(true);
  TravelClock clock2(true, "Rome", 10);
  TravelClock clock3(true, "Tokyo", -16);

  cout << clock1.get_location() << " time is " << clock1.get_hours() << ": " 
    << setw(2) << setfill('0') << clock1.get_minutes() << setfill(' ') << ": "
    << setw(2) << setfill('0') << clock1.get_seconds() << setfill(' ')
    << "\n";

  cout << clock2.get_location() << " time is " << clock2.get_hours() << ": " 
  << setw(2) << setfill('0') << clock2.get_minutes() << setfill(' ') << ": "
  << setw(2) << setfill('0') << clock2.get_seconds() << setfill(' ')
  << "\n";

  cout << clock3.get_location() << " time is " << clock3.get_hours() << ": " 
  << setw(2) << setfill('0') << clock3.get_minutes() << setfill(' ') << ": "
  << setw(2) << setfill('0') << clock3.get_seconds() << setfill(' ')
  << "\n";

}