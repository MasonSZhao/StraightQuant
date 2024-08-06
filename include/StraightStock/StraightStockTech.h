// Copyright (c) 2024-present, Shuai (Mason) Zhao
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#pragma once

namespace STRAIGHTSTOCK {
/**
 * @brief Given the price in the base period, calculate the Limit Up-Limit Down price in the current period.
 * @param val The price in the base period.
 * @param limit
 *     - 1.05: calculates the 5% limit up price.
 *     - 1.1: calculates the 10% limit up price.
 *     - 1.2: calculates the 20% limit up price.
 *     - 0.95: calculates the 5% limit down price.
 *     - 0.90: calculates the 10% limit down price.
 *     - 0.80: calculates the 20% limit down price.
 * @return The Limit Up-Limit Down price in the current period.
 */
[[nodiscard]] double stockTechLimitCur1(double val, double limit);

}
