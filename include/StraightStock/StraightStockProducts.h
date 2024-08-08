// Copyright (c) 2024-present, Shuai (Mason) Zhao
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#pragma once

#include "StraightStockConstChar.h"
#include "StraightStockProduct.h"
#include "StraightStockPrvol.h"
#include <filesystem>
#include <unordered_map>

namespace STRAIGHTSTOCK {
/**
 * @brief Represents the stocks.
 * @details 00????, 30????, 60????, 68????, 43????, 83????, 87????.
 */
class StockProductsStockSzShBj {
private:
    /**
     * @brief Represents the index of the 1st 00???? stock in the file.
     */
    static size_t _fileIdx00;

    /**
     * @brief Represents the index of the 1st 30???? stock in the file.
     */
    static size_t _fileIdx30;

    /**
     * @brief Represents the index of the 1st 60???? stock in the file.
     */
    static size_t _fileIdx60;

    /**
     * @brief Represents the index of the 1st 68???? stock in the file.
     */
    static size_t _fileIdx68;

    /**
     * @brief Represents the index of the 1st 43????, 83???? or 87???? stock in the file.
     */
    static size_t _fileIdx43_83_87;

public:
    /**
     * @brief The vector of the stock blocks.
     */
    static std::vector<StockProduct> _vecProduct;

    /**
     * @brief The exchange limit of the stock blocks.
     */
    static std::vector<double> _vecExLimit;

    /**
     * @brief The look up table of the stock block exchange names.
     */
    static std::unordered_map<const char*, size_t, StockConstCharPtrHasher, StockConstCharPrtComparer<>> _lutExCode;

    /**
     * @brief The vector of the StockPrvolDay collections.
     */
    static std::vector<std::vector<StockPrvolDay>> _vecVecPrvolDay;

    /**
     * @brief The read function.
     */
    class Read {
    private:
        /**
         * @brief Represents the folder path that stores the files.
         */
        static std::filesystem::path _folderPathProductsSzShBj;

    public:
        /**
         * @brief The getter of the folder path.
         * @return The folder path.
         */
        static [[nodiscard]] std::filesystem::path& getFolderPath();

        /**
         * @brief The setter of the folder path.
         * @param val The folder path.
         */
        static void setFolderPath(std::filesystem::path& val);

    private:
    public:
        /**
         * @brief Read 00???? stocks or not.
         */
        bool _read00 { true };

        /**
         * @brief Read 30???? stocks or not.
         */
        bool _read30 { true };

        /**
         * @brief Read 60???? stocks or not.
         */
        bool _read60 { true };

        /**
         * @brief Read 68???? stocks or not.
         */
        bool _read68 { true };

        /**
         * @brief Read 43????, 83???? and 87???? stocks or not.
         */
        bool _read43_83_87 { true };

        /**
         * @brief The default destination.
         */
        std::vector<StockProduct>* _vecBlock = &StockProductsStockSzShBj::_vecProduct;

        /**
         * @brief The default destination.
         */
        std::vector<double>* _vecExLimit = &StockProductsStockSzShBj::_vecExLimit;

        /**
         * @brief The default destination.
         */
        std::unordered_map<const char*, size_t, StockConstCharPtrHasher, StockConstCharPrtComparer<>>* _lutExCode = &StockProductsStockSzShBj::_lutExCode;

        /**
         * @brief The default destination.
         */
        std::vector<std::vector<StockPrvolDay>>* _vecVecPrvolDay = &StockProductsStockSzShBj::_vecVecPrvolDay;

        void operator()();
    };
};

/**
 * @brief Represents the style blocks.
 */
class StockProductsStyle {
private:
    static size_t _fileIdx;

public:
    friend class StockProductsStockSzShBj;
};

/**
 * @brief Represents the district blocks.
 * @details 8802??.
 */
class StockProductsDistrict {
private:
    static size_t _fileIdx;

public:
    friend class StockProductsStockSzShBj;
};

/**
 * @brief Represents the company industry blocks.
 * @details 8803??, 8804??.
 */
class StockProductsIndustryCompany {
private:
    static size_t _fileIdx;

public:
    friend class StockProductsStockSzShBj;
};

/**
 * @brief Represents the concept industry blocks.
 */
class StockProductsConcept {
private:
    static size_t _fileIdx;

public:
    friend class StockProductsStockSzShBj;
};

/**
 * @brief Represents the research industry blocks.
 */
class StockProductsIndustryResearch {
private:
    static size_t _fileIdx;

public:
    friend class StockProductsStockSzShBj;
};

}
