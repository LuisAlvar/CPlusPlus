#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <ctime>

using namespace std;

class Time {
public:

  Time();
  Time(int h, int m, int s);

  int get_seconds() const;
  int get_minutes() const;
  int get_hours() const;

  void add_seconds(int n);

  int seconds_from(int t) const;

private: 
  int hours;
  int minutes;
  int seconds;
  time_t now;
};

Time::Time() {
  now = time(0);
  tm* ltm = localtime(&now);

  hours = ltm->tm_hour; 
  minutes = ltm->tm_min;
  seconds = ltm->tm_sec;
}

Time::Time(int h, int m, int s)
{
  hours = h;
  minutes = m;
  seconds = s;
}

int Time::get_hours() const
{
  return hours;
}

int Time::get_minutes() const
{
  return minutes;
}

int Time::get_seconds() const
{
  return seconds;
}

void Time::add_seconds(int n)
{
  seconds += n;
}

int Time::seconds_from(int t) const 
{
  return seconds - t;
}

#endif
