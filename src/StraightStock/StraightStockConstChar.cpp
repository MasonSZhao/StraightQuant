// Copyright (c) 2024-present, Shuai (Mason) Zhao
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include "..\..\include\StraightStock\StraightStockConstChar.h"

namespace STRAIGHTSTOCK {
int StockConstCharPtr::Hash::operator()(const char* a) const
{
    const static int seed { 131 };
    int hash { 0 };
    hash = (hash * seed) + (*a);
    while (*(++a)) {
        hash = (hash * seed) + (*a);
    }
    return hash & (0x7FFFFFFF);
}

}
