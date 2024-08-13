#include "../../include/StraightStock/StraightStockPrvols.h"

/*
 * @details
 *     https://github.com/catchorg/Catch2/blob/devel/docs/own-main.md
 */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <algorithm>

SCENARIO("UnitTestStockPrvols", "[StockPrvols]")
{
    GIVEN("class StockPrvolsDay")
    {
        GIVEN("function read()")
        {
            WHEN("100 == count")
            {
                THEN("100 == size()")
                {
                    if (true) {
                        STRAIGHTSTOCK::StockPrvolDays::Read op("1603530");
                        std::vector<STRAIGHTSTOCK::StockPrvolDay> vecPrvolDay;
                        vecPrvolDay.reserve(100);
                        op.operator()<std::vector>(vecPrvolDay, 0, 100);
                        if (true) {
                            size_t i { 0 };
                            for (const auto& e : vecPrvolDay) {
                                std::cout << i << '\t';
                                e.operator<<(std::cout);
                                std::cout << std::endl;
                                ++i;
                            }
                        }
                        CHECK(100 == vecPrvolDay.size());
                    }
                }
            }
        }

        GIVEN("vecDateLess and vecDateGreater")
        {
            if (true) {
                STRAIGHTSTOCK::StockPrvolDays::Read op("1999999");
                std::vector<STRAIGHTSTOCK::StockPrvolDay> vecPrvolDay;
                vecPrvolDay.reserve(300);
                op.operator()<std::vector>(vecPrvolDay, 0, 300);

                std::vector<std::chrono::year_month_day> vecDateLess;
                vecDateLess.reserve(vecPrvolDay.size());
                std::vector<std::chrono::year_month_day> vecDateGreater;
                vecDateGreater.reserve(vecPrvolDay.size());

                if (true) {
                    for (size_t i { 0 }; i < vecPrvolDay.size(); ++i) {
                        vecDateLess.push_back(vecPrvolDay[i].getTimePoint());
                        vecDateGreater.push_back(vecPrvolDay[vecPrvolDay.size() - 1 - i].getTimePoint());
                    }
                }
                // if and else have the same effects.
                else {
                    for (size_t i { 0 }; i < vecPrvolDay.size(); ++i) {
                        vecDateLess.push_back(vecPrvolDay[i].getTimePoint());
                        vecDateGreater.push_back(vecPrvolDay[i].getTimePoint());
                    }
                    std::sort(std::begin(vecDateGreater), std::end(vecDateGreater), std::greater<std::chrono::year_month_day>());
                }

                WHEN("Search for the right bound of a given exchange date.")
                {
                    THEN("The result should be equal to.")
                    {
                        const auto val = vecDateLess[vecDateLess.size() - 1 - 2];
                        std::cout << val << std::endl;
                        auto idx = std::upper_bound /*Search for the 1st element that the value is less than or equal to the element.*/ (std::begin(vecDateLess), std::end(vecDateLess), val, std::less_equal<std::chrono::year_month_day>());
                        std::cout << vecDateLess[idx - std::begin(vecDateLess)] << std::endl
                                  << std::endl;
                        CHECK(val == vecDateLess[idx - std::begin(vecDateLess)]);
                    }
                }
                WHEN("Search for the right bound of a given non-exchange date.")
                {
                    THEN("The result should be later.")
                    {
                        const auto val = std::chrono::year_month_day { vecDateLess.back().year() / std::chrono::month(1) / std::chrono::day(1) };
                        std::cout << val << std::endl;
                        auto idx = std::upper_bound /*Search for the 1st element that the value is less than the element.*/ (std::begin(vecDateLess), std::end(vecDateLess), val, std::less<std::chrono::year_month_day>());
                        std::cout << vecDateLess[idx - std::begin(vecDateLess)] << std::endl
                                  << std::endl;
                        CHECK(val < vecDateLess[idx - std::begin(vecDateLess)]);
                    }
                }
                WHEN("Search for the left bound of a given exchange date.")
                {
                    THEN("The result should be equal to.")
                    {
                        const auto val = vecDateGreater[vecDateGreater.size() - 1 - 2];
                        std::cout << val << std::endl;
                        auto idx = std::upper_bound /*Search for the 1st element that the value is greater than or equal to the element.*/ (std::begin(vecDateGreater), std::end(vecDateGreater), val, std::greater_equal<std::chrono::year_month_day>());
                        std::cout << vecDateGreater[idx - std::begin(vecDateGreater)] << '\t' << vecDateLess[std::end(vecDateGreater) - 1 - idx] << std::endl
                                  << std::endl;
                        CHECK(val == vecDateLess[std::end(vecDateGreater) - 1 - idx]);
                    }
                }
                WHEN("Search for the left bound of a given non-exchange date.")
                {
                    THEN("The result should be earlier.")
                    {

                        const auto val = std::chrono::year_month_day { vecDateLess.back().year() / std::chrono::month(1) / std::chrono::day(1) };
                        std::cout << val << std::endl;
                        auto idx = std::upper_bound /*Search for the 1st element that the value is greater than the element.*/ (std::begin(vecDateGreater), std::end(vecDateGreater), val, std::greater<std::chrono::year_month_day>());
                        std::cout << vecDateGreater[idx - std::begin(vecDateGreater)] << '\t' << vecDateLess[std::end(vecDateGreater) - 1 - idx] << std::endl
                                  << std::endl;
                        CHECK(val > vecDateLess[std::end(vecDateGreater) - 1 - idx]);
                    }
                }
            }
        }
    }
}