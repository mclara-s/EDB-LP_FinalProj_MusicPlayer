#include "duration.h"

Duration::Duration(int s)
  : seconds(s) {}

int Duration::getTotalSeconds()
{
  return seconds;
}

QString Duration::toString()
{
  int mm = seconds / 60;
  int ss = (seconds % 60) * 60;

  return QString(mm) + ":" + QString(ss);
}