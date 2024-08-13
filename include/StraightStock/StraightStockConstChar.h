// Copyright (c) 2024-present, Shuai (Mason) Zhao
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#pragma once
#include <string>

namespace STRAIGHTSTOCK {
/**
 * @brief Provides hash() and key_eq() for std::unordered_map<const char*>.
 * @details
 *     https://en.cppreference.com/w/cpp/container/unordered_map
 *
 *     https://en.cppreference.com/w/cpp/container/unordered_map/hash_function
 *
 *     https://en.cppreference.com/w/cpp/container/unordered_map/key_eq
 * @warning
 *     Don't use std::hash<const char*> and std::equal_to<const char*>, these functions examine the pointer (the memory address) rather than the content\n
 *     UnitTestStockConstChar.cpp has given some examples to show the differences.
 */
struct StockConstCharPtr {
    /**
     * @brief hash() for std::unordered_map<const char*>.
     */
    struct Hash {
        [[nodiscard]] int operator()(const char* a) const;
    };

    /**
     * @brief key_eq() for std::unordered_map<const char*>.
     */
    template <typename unsigned short count = 8>
    struct EqualTo {
        [[nodiscard]] bool operator()(const char* lhs, const char* rhs) const
        {
            // https://en.cppreference.com/w/cpp/string/byte/memcmp
            return 0 == memcmp /*return 0 if all count bytes of lhs and rhs are equal.*/ (lhs, rhs, count);
        }
    };
};

}
