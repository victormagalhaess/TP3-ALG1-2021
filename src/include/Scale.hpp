#ifndef H_SCALE
#define H_SCALE

class Scale
{
private:
  int scaleTime;
  int cost;

public:
  Scale();
  Scale(int _scaleTime, int _cost);
  int getCost();
  int getScaleTime();
  double getCostWithDiscount(double discount);
  ~Scale();
};

#endif
