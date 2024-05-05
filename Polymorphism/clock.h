#ifndef CLOCK_H
#define CLOCK_H

#include <iostream>
#include "time.h"

using namespace std;

class Clock {

public:
  Clock() {};

  Clock(bool use_military);

  virtual string get_location() const;

  virtual int get_hours() const;

  virtual int get_minutes() const;

  virtual int get_seconds() const;


  bool is_military() const;

private:
  bool military;

};

Clock::Clock(bool use_military)
{
  military = use_military;
}

string Clock::get_location() const 
{
  return "Local";
}

int Clock::get_hours() const
{
  Time now;
  int hours = now.get_hours();

  if (military) return hours;

  if (hours == 0)
  {
    return 12;
  }
  else if (hours > 12)
  {
    return hours - 12;
  }
  else
  {
    return hours;
  }
}

int Clock::get_minutes() const
{
  Time now;
  return now.get_minutes();
}

int Clock::get_seconds() const
{
  Time now;
  return now.get_seconds();
}

bool Clock::is_military() const
{
  return military;
}
#endif