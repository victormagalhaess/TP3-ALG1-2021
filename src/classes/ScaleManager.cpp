#include "../include/Scale.hpp"
#include "../include/ScaleManager.hpp"
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

ScaleManager::ScaleManager(int _numberOfScales, int _maxScales, int _timeWindowLimit)
{
    this->numberOfScales = _numberOfScales;
    this->maxScales = _maxScales;
    this->timeWindowLimit = _timeWindowLimit;
}

//busca linear
double ScaleManager::getSmallerCost(int col)
{
    double smallerCost = this->costMatrix.at(0).at(col);
    for (int row = 1; row < this->numberOfScales; row++)
    {
        double cost = costMatrix.at(row).at(col);
        if (cost < smallerCost && cost > 0)
        {
            smallerCost = cost;
        }
    }
    return smallerCost;
}

void ScaleManager::generateCostMatrix()
{
    for (int i = 0; i < this->numberOfScales; i++)
    {
        int currentTime = 0;
        int currentDiscount = 0;
        int countScales = 0;
        double smallerCost;
        if (i == 0)
        {
            smallerCost = 0;
        }
        else
        {
            smallerCost = getSmallerCost(i - 1);
        }
        for (int j = i; j < this->numberOfScales; j++)
        {
            Scale Scale = this->Scales.at(j);
            if (countScales < this->maxScales)
            {
                currentDiscount += this->discountList.at(countScales);
            }
            else
            {
                currentDiscount = 0;
            }
            countScales++;
            currentTime += Scale.getScaleTime();
            this->costMatrix.at(i).at(j) = smallerCost + Scale.getCostWithDiscount(currentDiscount / 100.0);
            smallerCost = this->costMatrix.at(i).at(j);
            if (currentTime >= this->timeWindowLimit)
            {
                currentDiscount = 0;
                currentTime = 0;
                countScales = 0;
            }
        }
    }
}

void ScaleManager::getTotalCostForStretch()
{
    vector<double> auxcol;
    int discount, time, price;
    cin >> this->numberOfScales >> this->maxScales >> this->timeWindowLimit;
    for (int i = 0; i < this->maxScales; i++)
    {
        cin >> discount;
        this->discountList.push_back(discount);
    }
    for (int i = 0; i < this->numberOfScales; i++)
    {
        cin >> time >> price;
        this->Scales.push_back(Scale(time, price));
        auxcol.push_back(0);
    }
    for (int i = 0; i < numberOfScales; i++)
    {
        costMatrix.push_back(auxcol);
    }
    generateCostMatrix();
    double smallerCost = getSmallerCost(this->numberOfScales - 1);
    cout << fixed << setprecision(2) << smallerCost << endl;
}

ScaleManager::~ScaleManager()
{
}