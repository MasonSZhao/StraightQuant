// Copyright (c) 2024-present, Shuai (Mason) Zhao
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include "..\..\include\StraightStock\StraightStockProduct.h"

namespace STRAIGHTSTOCK {
std::ostream& operator<<(std::ostream& os, const StockProduct& a)
{
    return os << &a._exCode[0] << '\t' << a._exName << '\t' << a._exChar << '\t' << a._exBase;
}

std::array<char, 8> StockProduct::getExCode()
{
    return _exCode;
}

const std::string& StockProduct::getExName()
{
    return _exName;
}

const std::string& StockProduct::getExChar()
{
    return _exChar;
}

double StockProduct::getExBase()
{
    return _exBase;
}

}
