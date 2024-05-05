
#include <iostream>
#include "department.h"
using namespace std;

void raise_salary(Employee* e, double by)
{
  double new_salary = e->get_salary() * (1 + by/100);
  e->set_salary(new_salary);
}

int main()
{
  Department shipping("Shipping");
  Department qc("Quality Control");

  Employee* harry = new Employee("Hacker", "Harry", 45000);
  Employee* tina =  new Employee("Tester", "Tina", 50000);

  shipping.set_secretary(harry);
  qc.set_receptionist(tina);
  qc.set_secretary(tina);

  tina->set_salary(55000);
  raise_salary(harry, 15);

  shipping.print();
  qc.print();

  delete tina;
  delete harry;
  
  return 0;
}