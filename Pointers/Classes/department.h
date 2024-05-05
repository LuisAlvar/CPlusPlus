#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <iostream>
#include "employee.h"

/*
We will use a pointer to model the fact that the receptionist is optional. 
  - if a particular department has a receptionist, the the pointer will be set to the
    address of an employee object. Otherwise, the pointer will be the special value NULL.
    In the constructor, we set the value to NULL.

Pointers can be used to model optional values (by using a NULL pointer when the value is not present)
Pointers can be used to provide shared access to a common value. 

Note how the pointers are used to express optional and shared objects.
*/

using namespace std;

class Department
{
public:
  Department(string n);
  void set_receptionist(Employee* e);
  void set_secretary(Employee* e);
  void print() const;

private:
  string name;
  Employee* receptionist;
  Employee* secretary;
};

Department::Department(string n)
{
  name = n;
  receptionist = NULL;
  secretary =  NULL;
}

void Department::set_receptionist(Employee* e)
{
  receptionist = e;
}

void Department::set_secretary(Employee* e)
{
  secretary = e;
}

void Department::print() const
{
  cout << "Name: " << name << "\n" << "Receptionist: ";

  if (receptionist == NULL)
  {
    cout << "None";
  }
  else
  {
    cout << receptionist->get_name() << " $" << receptionist->get_salary();
  }

  cout << "\nSecretarry: ";
  if (secretary == NULL)
  {
    cout << "None";
  }
  else if (secretary == receptionist)
  {
    cout << "Same";
  }
  else
  {
    cout << secretary->get_name() << " $" << secretary->get_salary();
  }
  
  cout << "\n";  
}

#endif