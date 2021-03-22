#include "../include/Scale.hpp"

Scale::Scale(int _scaleTime, int _cost)
{
  this->scaleTime = _scaleTime;
  this->cost = _cost;
}

Scale::Scale()
{
}

int Scale::getScaleTime()
{
  return scaleTime;
}

int Scale::getCost()
{
  return this->cost;
}

double Scale::getCostWithDiscount(double discount)
{
  return ((double)cost - ((double)cost * discount));
}

Scale::~Scale()
{
}