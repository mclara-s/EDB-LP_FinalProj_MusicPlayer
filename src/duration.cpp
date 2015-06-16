#include "duration.h"

Duration::Duration(int s)
  : seconds(s) {}

int Duration::getSeconds()
{
  return (seconds % 60);
}

int Duration::getMinutes()
{
  return ((seconds - getSeconds()) / 60);
}

int Duration::getTotalSeconds()
{
  return seconds;
}

QString Duration::toString()
{
  return QString::number(getMinutes()) + ":" + QString::number(getSeconds());
}