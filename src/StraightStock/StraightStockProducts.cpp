// Copyright (c) 2024-present, Shuai (Mason) Zhao
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include "..\..\include\StraightStock\StraightStockProducts.h"
#include "..\..\include\StraightStock\StraightStockTech.h"
#include <filesystem>
#include <fstream>

namespace STRAIGHTSTOCK {

size_t StockProductsStockSzShBj::_fileIdx00 { 0 };

size_t StockProductsStockSzShBj::_fileIdx30 { 0 };

size_t StockProductsStockSzShBj::_fileIdx60 { 0 };

size_t StockProductsStockSzShBj::_fileIdx68 { 0 };

size_t StockProductsStockSzShBj::_fileIdx43_83_87 { 0 };

std::vector<StockProduct> StockProductsStockSzShBj::_vecProduct {};

std::vector<double> StockProductsStockSzShBj::_vecExLimit {};

std::unordered_map<const char*, size_t, StockConstCharPtrHasher, StockConstCharPrtComparer<>> StockProductsStockSzShBj::_lutExCode {};

std::vector<std::vector<StockPrvolDay>> StockProductsStockSzShBj::_vecVecPrvolDay {};

std::filesystem::path StockProductsStockSzShBj::Read::_folderPathProductsSzShBj { "C:/new_tdx/T0002/hq_cache/" };

[[nodiscard]] std::filesystem::path& StockProductsStockSzShBj::Read::getFolderPath()
{
    return _folderPathProductsSzShBj;
}

void StockProductsStockSzShBj::Read::setFolderPath(std::filesystem::path& val)
{
    _folderPathProductsSzShBj = val;
}

void StockProductsStockSzShBj::Read::operator()()
{
    if ((true == _read00) || (true == _read30)) {
        if (!std::filesystem::exists(_folderPathProductsSzShBj))
            throw std::runtime_error("runtime_error-NOT_exist:T0002.");
        std::filesystem::path _filePath_szm_tnf { _folderPathProductsSzShBj };
        _filePath_szm_tnf.concat("szm.tnf");
        std::ifstream ifs_szm_tnf(_filePath_szm_tnf, std::ifstream::in | std::ifstream::binary);
        ifs_szm_tnf.ignore(50); // ignores 50 bytes in the beginning.
        // char buf[314]; // Each product takes 314 bytes.
        size_t fileIdx { 0 };
        while (!ifs_szm_tnf.eof()) {
            StockProduct product {};
            ifs_szm_tnf.read(reinterpret_cast<char*>(&product._exCode[1]), 6);
            product._exCode[0] = '0';
            product._exCode[7] = '\0';
            bool isExCode { false };
            if (('0' == product._exCode[1]) && ('0' == product._exCode[2])) {
                if (0 == StockProductsStockSzShBj::_fileIdx00) {
                    StockProductsStockSzShBj::_fileIdx00 = fileIdx;
                }
                if (true == _read00) {
                    isExCode = true;
                }
            } else if (('3' == product._exCode[1]) && ('0' == product._exCode[2])) {
                if (0 == StockProductsStockSzShBj::_fileIdx30) {
                    StockProductsStockSzShBj::_fileIdx30 = fileIdx;
                }
                if (true == _read30) {
                    isExCode = true;
                }
            }
            ifs_szm_tnf.ignore(2); // 0 exCode
            ifs_szm_tnf.ignore(1 /*unsigned char*/); // unknown byte
            ifs_szm_tnf.ignore(2 /*unsigned short*/); // unknown word
            ifs_szm_tnf.ignore(4 /*float*/); // unknown single precision float
            ifs_szm_tnf.ignore(4 /*unsigned int*/); // unknown integer
            ifs_szm_tnf.ignore(4 /*unsigned int*/); // unknown integer
            std::array<char, 19> exName {};
            ifs_szm_tnf.read(reinterpret_cast<char*>(&exName[0]), 18);
            float exBase = 0;
            ifs_szm_tnf.ignore(235);
            ifs_szm_tnf.read(reinterpret_cast<char*>(&exBase), 4);
            ifs_szm_tnf.ignore(1 /*unsigned char*/); // unknown byte
            ifs_szm_tnf.ignore(4 /*unsigned float*/); // unknown single precision float
            std::array<char, 10> exChar {};
            ifs_szm_tnf.read(reinterpret_cast<char*>(&exChar[0]), 9);
            ifs_szm_tnf.ignore(20);
            if (true == isExCode) {
                product._exName = std::string { &exName[0] };
                product._exBase = exBase;
                product._exChar = std::string { &exChar[0] };
                _vecBlock->push_back(product);
                _vecExLimit->push_back(stockTechLimit0(&product._exCode[0]));
            }
            ++fileIdx;
        }
        ifs_szm_tnf.close();
    }
    if ((true == _read60) || (true == _read68)) {
        if (!std::filesystem::exists(_folderPathProductsSzShBj))
            throw std::runtime_error("runtime_error-NOT_exist:T0002.");
        std::filesystem::path _filePath_shm_tnf { _folderPathProductsSzShBj };
        _filePath_shm_tnf.concat("shm.tnf");
        std::ifstream ifs_shm_tnf(_filePath_shm_tnf, std::ifstream::in | std::ifstream::binary);
        ifs_shm_tnf.ignore(50); // ignores 50 bytes in the beginning.
        // char buf[314]; // Each product takes 314 bytes.
        size_t fileIdx { 0 };
        while (!ifs_shm_tnf.eof()) {
            StockProduct product {};
            ifs_shm_tnf.read(reinterpret_cast<char*>(&product._exCode[1]), 6);
            product._exCode[0] = '1';
            product._exCode[7] = '\0';
            bool isExCode { false };
            if (('8' == product._exCode[1]) && ('8' == product._exCode[2]) && ('0' == product._exCode[3])) {
                if ('0' == product._exCode[4]) {
                    if (0 == StockProductsStyle::_fileIdx) {
                        StockProductsStyle::_fileIdx = fileIdx;
                    }
                } else if ('2' == product._exCode[4]) {
                    if (0 == StockProductsDistrict::_fileIdx) {
                        StockProductsDistrict::_fileIdx = fileIdx;
                    }
                } else if (('3' == product._exCode[4]) || ('4' == product._exCode[4])) {
                    if (0 == StockProductsIndustryCompany::_fileIdx) {
                        StockProductsIndustryCompany::_fileIdx = fileIdx;
                    }
                } else if ('5' == product._exCode[4]) {
                    if (0 == StockProductsConcept::_fileIdx) {
                        StockProductsConcept::_fileIdx = fileIdx;
                    }
                }
            } else if (('8' == product._exCode[1]) && ('8' == product._exCode[2]) && ('1' == product._exCode[3])) {
                if (0 == StockProductsIndustryResearch::_fileIdx) {
                    StockProductsIndustryResearch::_fileIdx = fileIdx;
                }
            } else if (('6' == product._exCode[1]) && ('0' == product._exCode[2])) {
                if (0 == _fileIdx60) {
                    _fileIdx60 = fileIdx;
                }
                if (true == _read60) {
                    isExCode = true;
                }
            } else if (('6' == product._exCode[1]) && ('8' == product._exCode[2])) {
                if (0 == _fileIdx68) {
                    _fileIdx68 = fileIdx;
                }
                if (true == _read68) {
                    isExCode = true;
                }
            }
            ifs_shm_tnf.ignore(2); // 0 exCode
            ifs_shm_tnf.ignore(1 /*unsigned char*/); // unknown byte
            ifs_shm_tnf.ignore(2 /*unsigned short*/); // unknown word
            ifs_shm_tnf.ignore(4 /*float*/); // unknown single precision float
            ifs_shm_tnf.ignore(4 /*unsigned int*/); // unknown integer
            ifs_shm_tnf.ignore(4 /*unsigned int*/); // unknown integer
            std::array<char, 19> exName {};
            ifs_shm_tnf.read(reinterpret_cast<char*>(&exName[0]), 18);
            float exBase = 0;
            ifs_shm_tnf.ignore(235);
            ifs_shm_tnf.read(reinterpret_cast<char*>(&exBase), 4);
            ifs_shm_tnf.ignore(1 /*unsigned char*/); // unknown byte
            ifs_shm_tnf.ignore(4 /*unsigned float*/); // unknown single precision float
            std::array<char, 10> exChar {};
            ifs_shm_tnf.read(reinterpret_cast<char*>(&exChar[0]), 9);
            ifs_shm_tnf.ignore(20);
            if (true == isExCode) {
                product._exName = std::string { &exName[0] };
                product._exBase = exBase;
                product._exChar = std::string { &exChar[0] };
                _vecBlock->push_back(product);
                _vecExLimit->push_back(stockTechLimit0(&product._exCode[0]));
            }
            ++fileIdx;
        }
        ifs_shm_tnf.close();
    }
    if (true == _read43_83_87) {
        if (!std::filesystem::exists(_folderPathProductsSzShBj))
            throw std::runtime_error("runtime_error-NOT_exist:T0002.");
        std::filesystem::path _filePath_bjm_tnf { _folderPathProductsSzShBj };
        _filePath_bjm_tnf.concat("bjm.tnf");
        std::ifstream ifs_bjm_tnf(_filePath_bjm_tnf, std::ifstream::in | std::ifstream::binary);
        ifs_bjm_tnf.ignore(50); // ignores 50 bytes in the beginning.
        // char buf[314]; // Each product takes 314 bytes.
        size_t fileIdx { 0 };
        while (!ifs_bjm_tnf.eof()) {
            StockProduct product {};
            ifs_bjm_tnf.read(reinterpret_cast<char*>(&product._exCode[1]), 6);
            product._exCode[0] = '2';
            product._exCode[7] = '\0';
            bool isExCode { false };
            if (('4' == product._exCode[1]) && ('3' == product._exCode[2])) {
                if (0 == _fileIdx43_83_87) {
                    _fileIdx43_83_87 = fileIdx;
                }
                isExCode = true;
            } else if (('8' == product._exCode[1]) && ('3' == product._exCode[2])) {
                isExCode = true;
            } else if (('8' == product._exCode[1]) && ('7' == product._exCode[2])) {
                isExCode = true;
            }
            ifs_bjm_tnf.ignore(2); // 0 exCode
            ifs_bjm_tnf.ignore(1 /*unsigned char*/); // unknown byte
            ifs_bjm_tnf.ignore(2 /*unsigned short*/); // unknown word
            ifs_bjm_tnf.ignore(4 /*float*/); // unknown single precision float
            ifs_bjm_tnf.ignore(4 /*unsigned int*/); // unknown integer
            ifs_bjm_tnf.ignore(4 /*unsigned int*/); // unknown integer
            std::array<char, 19> exName {};
            ifs_bjm_tnf.read(reinterpret_cast<char*>(&exName[0]), 18);
            float exBase = 0;
            ifs_bjm_tnf.ignore(235);
            ifs_bjm_tnf.read(reinterpret_cast<char*>(&exBase), 4);
            ifs_bjm_tnf.ignore(1 /*unsigned char*/); // unknown byte
            ifs_bjm_tnf.ignore(4 /*unsigned float*/); // unknown single precision float
            std::array<char, 10> exChar {};
            ifs_bjm_tnf.read(reinterpret_cast<char*>(&exChar[0]), 9);
            ifs_bjm_tnf.ignore(20);
            if (true == isExCode) {
                product._exName = std::string { &exName[0] };
                product._exBase = exBase;
                product._exChar = std::string { &exChar[0] };
                _vecBlock->push_back(product);
                _vecExLimit->push_back(0.3);
            }
            ++fileIdx;
        }
        ifs_bjm_tnf.close();
    }
    if ((true == _read00) || (true == _read30) || (true == _read60) || (true == _read68) || (true == _read43_83_87)) {
        for (size_t i { 0 }; i < _vecBlock->size(); ++i) {
            _lutExCode->insert(std::unordered_map<const char*, size_t, StockConstCharPtrHasher, StockConstCharPrtComparer<>>::value_type(&(((*_vecBlock)[i])._exCode)[0], i));
        }
    }
    _vecVecPrvolDay->resize(_vecBlock->size());
}

size_t StockProductsDistrict::_fileIdx { 0 };

size_t StockProductsIndustryCompany::_fileIdx { 0 };

size_t StockProductsConcept::_fileIdx { 0 };

size_t StockProductsIndustryResearch::_fileIdx { 0 };

size_t StockProductsStyle::_fileIdx { 0 };

}
