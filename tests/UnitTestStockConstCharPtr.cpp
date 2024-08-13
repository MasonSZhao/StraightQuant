#include "..\..\include\StraightStock\StraightStockConstChar.h"

/*
 * @details
 *     https://github.com/catchorg/Catch2/blob/devel/docs/own-main.md
 */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <array>

SCENARIO("UnitTestStockConstCharPtr", "[StockConstCharPtr]")
{
    GIVEN("class StockConstCharPtr")
    {
        GIVEN("function Read()")
        {
            std::cout << "const char ptr" << std::endl;
            std::array<char, 8> lhs { "1999999" };
            std::cout << &lhs[0] << std::endl;
            std::array<char, 8> rhs { "1999999" };
            std::cout << &rhs[0] << std::endl;
            std::cout << std::endl;

            WHEN("hash")
            {
                THEN("Same contents' hash values should be the same.")
                {
                    std::cout << "hash:" << std::endl;
                    std::cout << std::hash<const char*> {}(&lhs[0]) << std::endl;
                    std::cout << std::hash<const char*> {}(&rhs[0]) << std::endl;
                    std::cout << STRAIGHTSTOCK::StockConstCharPtr::Hash {}(&lhs[0]) << std::endl;
                    std::cout << STRAIGHTSTOCK::StockConstCharPtr::Hash {}(&rhs[0]) << std::endl;
                    CHECK(STRAIGHTSTOCK::StockConstCharPtr::Hash {}(&lhs[0]) == STRAIGHTSTOCK::StockConstCharPtr::Hash {}(&rhs[0]));
                    std::cout << std::endl;
                }
            }

            WHEN("equal_to")
            {
                THEN("Same contents' should be equal to each other.")
                {
                    std::cout << "equal_to:" << std::endl;
                    std::cout << std::boolalpha << std::equal_to<const char*> {}(&lhs[0], &rhs[0]) << std::endl;
                    std::cout << std::boolalpha << STRAIGHTSTOCK::StockConstCharPtr::EqualTo<> {}(&lhs[0], &rhs[0]) << std::endl;
                    CHECK(true == STRAIGHTSTOCK::StockConstCharPtr::EqualTo<> {}(&lhs[0], &rhs[0]));
                    std::cout << std::endl;
                }
            }
        }
    }
}