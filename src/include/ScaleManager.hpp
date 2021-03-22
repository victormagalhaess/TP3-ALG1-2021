#ifndef H_SCALEMANAGER
#define H_SCALEMANAGER
#include <vector>
#include "Scale.hpp"

using namespace std;

class ScaleManager
{
private:
    vector<vector<double>> costMatrix;
    int numberOfScales, maxScales, timeWindowLimit;
    vector<double> discountList;
    vector<Scale> Scales;

public:
    ScaleManager(int _numberOfScales, int _maxScales, int _timeWindowLimit);
    void getTotalCostForStretch();
    double getSmallerCost(int);
    void generateCostMatrix();
    ~ScaleManager();
};

#endif