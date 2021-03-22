#include <iostream>
#include "include/ScaleManager.hpp"
using namespace std;

int main()
{
    ScaleManager *manager = new ScaleManager(0, 0, 0);
    manager->getTotalCostForStretch();
    return 0;
}