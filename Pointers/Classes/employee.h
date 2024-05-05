
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

using namespace std;

class Employee
{
public:
  Employee(string lastName, string firstName, double salary);

  string get_name();
  double get_salary();

  void set_salary(double value);

private:
  string firstName;
  string lastName;
  double salary;
};

Employee::Employee(string lastName, string firstName, double salary){
  this->lastName = lastName;
  this->firstName = firstName;
  this->salary = salary;
}

string Employee::get_name()
{
  return lastName + ", " + firstName;
}

double Employee::get_salary()
{
  return salary;
}

void Employee::set_salary(double value)
{
  salary = value;
}

#endif 