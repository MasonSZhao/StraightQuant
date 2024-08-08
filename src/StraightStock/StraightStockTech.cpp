// Copyright (c) 2024-present, Shuai (Mason) Zhao
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include "..\..\include\StraightStock\StraightStockTech.h"
#include <cmath>

namespace STRAIGHTSTOCK {
double stockTechLimitCur1(double val, double limit)
{
    if (1.3 == limit) {
        return std::floor(val * limit * 100) / 100;
    } else if (0.7 == limit) {
        return std::ceil(val * limit * 100) / 100;
    } else {
        return std::round(val * limit * 100) / 100;
    }
}

double stockTechLimit0(const char* exCode)
{
    if (('4' == exCode[1]) && ('3' == exCode[2])) {
        return 0.3;
    } else if (('8' == exCode[1]) && ('3' == exCode[2])) {
        return 0.3;
    } else if (('8' == exCode[1]) && ('7' == exCode[2])) {
        return 0.3;
    } else if (('6' == exCode[1]) && ('8' == exCode[2])) {
        return 0.2;
    } else if (('3' == exCode[1]) && ('0' == exCode[2])) {
        return 0.2;
    } else if (('6' == exCode[1]) && ('0' == exCode[2])) {
        return 0.1;
    } else if (('0' == exCode[1]) && ('0' == exCode[2])) {
        return 0.1;
    } else {
        return std::numeric_limits<double>::quiet_NaN();
    }
}

}
