#include <iostream>
#include <string>
#include <iomanip>
#include "travelclock.h"
#include <vector>

using namespace std;

/*
The initial stage of this main function contains a bit of repetitive code.

Next stage we attempt to store all three clocks in a vector, and loop to
prit the clock values.
  - There is a problem here: the vector clocks holds objects of type Clock.
    the compiler realizes that a TravelClock is a special case of a Clock.
    Thus, it permits the assignment from a travel clock to a clock.
  - However, a TravelClock object has three data fields, whereras a Clock object has
    just one field, the military flag/ There is no room to store the derived-class data. 
  - That data simply gets slcied away when you assign a derived-class object to a base-class variable. 
    - Derived-class objects are usually bigger than base-class objects, and objects of different derived classes
      have different sizes. 
  - A vector of objects cannont deal with this variation in sizes. 

Solution:
  - instead, you need to store the actual objects elsewhere and collect their locations in a vector by storing pointers. 
  - a polymorphic vector 
  - the reason for using pointers is simple: Pointers to the variouis clcok objects all have the same size - namely, the 
    size of a memory address - even though the objects themselves may have different sizes. 
  - you simply declare the vector to hold pointers, and allocate all objects by calling new. 

Problem:
  - However, there remains a problem.
  - the compiler generated code only to call the Clock functions, not the functions that are appropriate for each object. 
    - in the compiler's defense, it actually took the correct action. 
    - a member function call is compiled into a call to one particular function. 
    - it is the compiler's job to find the appropriate functions that should be called. 
    - the compiler calls Clock member functions. 
  - You want first to determine the actual type of the object to which clocks[i] points, which can be either a Clcok 
    or a TravelClcok object, and then call the appropriate functions. 
Solution:
  - You must alert the compiler that the function call needs to be preceded by the appropriate function selection, which
    can be a different one for every iteration in the loop. 
  - You use the virtual keywork for this purpose.
  - The virtual keywork must be used in the base class. All functions with the same name
    and parameter types in derived classes are then automatically virtual. 
    However, it is considered good taste to supply the virtual keywork for the derived class function as well. 
    
*/

int main()
{
  /* Stage 1 */
  // Clock clock1(true);
  // TravelClock clock2(true, "Rome", 10);
  // TravelClock clock3(true, "Tokyo", -16);
  // cout << clock1.get_location() << " time is " << clock1.get_hours() << ": " 
  //   << setw(2) << setfill('0') << clock1.get_minutes() << setfill(' ') << ": "
  //   << setw(2) << setfill('0') << clock1.get_seconds() << setfill(' ')
  //   << "\n";

  // cout << clock2.get_location() << " time is " << clock2.get_hours() << ": " 
  // << setw(2) << setfill('0') << clock2.get_minutes() << setfill(' ') << ": "
  // << setw(2) << setfill('0') << clock2.get_seconds() << setfill(' ')
  // << "\n";

  // cout << clock3.get_location() << " time is " << clock3.get_hours() << ": " 
  // << setw(2) << setfill('0') << clock3.get_minutes() << setfill(' ') << ": "
  // << setw(2) << setfill('0') << clock3.get_seconds() << setfill(' ')
  // << "\n";

  /* Stage 2 */
  // vector<Clock> clocks(3);
  // clocks[0] = new Clock(true);
  // clocks[1] = new TravelClock(true, "Rome", 10);
  // clocks[2] = new TravelClock(true, "Tokyo", -16);
  
  // for (size_t i = 0; i < clocks.size(); i++)
  // {
  //   cout << clocks[i].get_location() << " time is " << clocks[i].get_hours() << ": " 
  //   << setw(2) << setfill('0') << clocks[i].get_minutes() << setfill(' ') << ": "
  //   << setw(2) << setfill('0') << clocks[i].get_seconds() << setfill(' ')
  //   << "\n";
  // }
  
  /* Stage 3 */
  vector<Clock*> clocks(3);
  clocks[0] = new Clock(true);
  clocks[1] = new TravelClock(true, "Rome", 10);
  clocks[2] = new TravelClock(true, "Tokyo", -16);
  
  for (size_t i = 0; i < clocks.size(); ++i)
  {
    cout << clocks[i]->get_location() << " time is " << clocks[i]->get_hours() << ": " 
    << setw(2) << setfill('0') << clocks[i]->get_minutes() << setfill(' ') << ": "
    << setw(2) << setfill('0') << clocks[i]->get_seconds() << setfill(' ')
    << "\n";
  }

  return 0;
}