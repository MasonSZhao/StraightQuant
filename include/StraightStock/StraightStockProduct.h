// Copyright (c) 2024-present, Shuai (Mason) Zhao
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#pragma once

#include <array>
#include <iostream>
#include <string>

namespace STRAIGHTSTOCK {
/**
 * @brief Represents the exchange product.
 * @details The exchange product may represent one stock or one block that contains more than one stock.
 */
class StockProduct {
private:
    /**
     * @brief The exchange code of the exchange product.
     */
    std::array<char, 8> _exCode {};

    /**
     * @brief The exchange name of the exchange product.
     */
    std::string _exName { "" };

    /**
     * @brief The exchange abbreviation of the exchange product.
     */
    std::string _exChar { "" };

    /**
     * @brief The exchange base of the exchagne product.
     */
    double _exBase { 0 };

public:
    friend std::ostream& operator<<(std::ostream& os, const StockProduct& a);

    /**
     * @brief The getter of the exchange code.
     * @return The exchange code.
     */
    std::array<char, 8> getExCode();

    /**
     * @brief The getter of the exchange name.
     * @return The exchange name.
     */
    const std::string& getExName();

    /**
     * @brief The getter of the exchange abbreviation.
     * @return The exchange abbreviation.
     */
    const std::string& getExChar();

    /**
     * @brief The getter of the exchange base.
     * @return The exchange base.
     */
    double getExBase();

    friend class StockProductsStockSzShBj;
};

}
