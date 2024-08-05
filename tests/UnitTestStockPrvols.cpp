#include "../../include/StraightStock/StraightStockPrvols.h"

/*
 * @details
 *     https://github.com/catchorg/Catch2/blob/devel/docs/own-main.md
 */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

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
                    STRAIGHTSTOCK::StockPrvolDays dayPrvols("1603530");
                    std::vector<STRAIGHTSTOCK::StockPrvolDay> vecDayPrvol;
                    vecDayPrvol.reserve(100);
                    dayPrvols.read<std::vector>(vecDayPrvol, 0, 100);
                    if (true) {
                        size_t i { 0 };
                        for (const auto& e : vecDayPrvol) {
                            std::cout << i << '\t';
                            e.operator<<(std::cout);
                            std::cout << std::endl;
                            ++i;
                        }
                    }
                    CHECK(100 == vecDayPrvol.size());
                }
            }
        }
    }
}