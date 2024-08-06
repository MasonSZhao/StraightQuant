#include "..\..\include\StraightStock\StraightStockTech.h"

/*
 * @details
 *     https://github.com/catchorg/Catch2/blob/devel/docs/own-main.md
 */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

SCENARIO("TestStraightStockTech", "[StockTech]")
{
    GIVEN("function stockTechLimitCur1")
    {
        GIVEN("sz300313Close")
        {
            std::vector<double> sz300313Close {
                5.83 /* 0*/,
                6.41 /* 1*/,
                7.05 /* 2*/,
                7.76 /* 3*/,
                9.31 /* 4*/,
                11.17 /* 5*/,
                13.40 /* 6*/,
                16.08 /* 7*/,
                19.30 /* 8*/,
                23.16 /* 9*/,
                24.07 /*10*/,
                28.88 /*11*/,
                34.66 /*12*/,
                27.73 /*13*/,
                24.25 /*14*/
            };
            std::vector<double> post {
                std::numeric_limits<double>::quiet_NaN(), // 0
                std::numeric_limits<double>::infinity(), // 1
                std::numeric_limits<double>::infinity(), // 2
                std::numeric_limits<double>::infinity(), // 3
                std::numeric_limits<double>::infinity(), // 4
                std::numeric_limits<double>::infinity(), // 5
                std::numeric_limits<double>::infinity(), // 6
                std::numeric_limits<double>::infinity(), // 7
                std::numeric_limits<double>::infinity(), // 8
                std::numeric_limits<double>::infinity(), // 9
                0.0392919, // 10 // (24.07 - 23.16) / 23.16
                std::numeric_limits<double>::infinity(), // 11
                std::numeric_limits<double>::infinity(), // 12
                -std::numeric_limits<double>::infinity(), // 13
                -0.125496, // 14 (24.25 - 27.73) / 27.73
            };
            WHEN("Calcualtes.")
            {
                THEN("The results should match.")
                {
                    for (size_t i { 0 }; i < 3; ++i) {
                        CHECK(STRAIGHTSTOCK::stockTechLimitCur1(sz300313Close[i], 1.1) == sz300313Close[i + 1]);
                    }
                    for (size_t i { 3 }; i < 9; ++i) {
                        CHECK(STRAIGHTSTOCK::stockTechLimitCur1(sz300313Close[i], 1.2) == sz300313Close[i + 1]);
                    }
                    CHECK(13.40 == STRAIGHTSTOCK::stockTechLimitCur1(11.17, 1.2));
                }
            }
        }
    }
}