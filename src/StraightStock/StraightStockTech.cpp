// Copyright (c) 2024-present, Shuai (Mason) Zhao
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

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

}
