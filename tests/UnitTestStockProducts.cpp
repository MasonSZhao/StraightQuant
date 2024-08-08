#include "..\..\include\StraightStock\StraightStockProducts.h"

/*
 * @details
 *     https://github.com/catchorg/Catch2/blob/devel/docs/own-main.md
 */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

SCENARIO("UnitTestStockPrvols", "[StockPrvols]")
{
    GIVEN("class StockProductsSzShBj")
    {
        GIVEN("function Read()")
        {
            WHEN("Reads.")
            {
                THEN("All datas should be read.")
                {
                    STRAIGHTSTOCK::StockProductsStockSzShBj::Read op;
                    op.operator()();
                    for (size_t i { 0 }; i < STRAIGHTSTOCK::StockProductsStockSzShBj::_vecProduct.size(); ++i) {
                        std::cout << STRAIGHTSTOCK::StockProductsStockSzShBj::_vecProduct[i] << '\t' << STRAIGHTSTOCK::StockProductsStockSzShBj ::_vecExLimit[i] << std::endl;
                    }
                }
            }
        }
    }
}