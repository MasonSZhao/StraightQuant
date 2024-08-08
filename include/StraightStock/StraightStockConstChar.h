// Copyright (c) 2024-present, Shuai (Mason) Zhao
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#pragma once
#include <string>

namespace STRAIGHTSTOCK {
/**
 * @brief Hasher for const char pointer.
 */
struct StockConstCharPtrHasher {
    [[nodiscard]] int operator()(const char* a) const;
};

/**
 * @brief Comparer for const char pointer.
 */
template <typename unsigned short n = 8>
struct StockConstCharPrtComparer {
    [[nodiscard]] bool operator()(const char* a, const char* b) const
    {
        return memcmp(a, b, n) == 0;
    }
};

}
