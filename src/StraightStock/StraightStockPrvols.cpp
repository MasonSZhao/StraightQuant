// Copyright (c) 2024-present, Shuai (Mason) Zhao
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include "..\..\include\StraightStock\StraightStockPrvols.h"

namespace STRAIGHTSTOCK {
const std::vector<std::chrono::year_month_day> StockPrvolDays::Festival::_vecSzShBjClose {
    std::chrono::year_month_day { std::chrono::year(2024) / std::chrono::month(1) / std::chrono::day(1) /*Monday*/ }, /*New Year's Day*/
    std::chrono::year_month_day { std::chrono::year(2024) / std::chrono::month(2) / std::chrono::day(9) /*Friday*/ },
    std::chrono::year_month_day { std::chrono::year(2024) / std::chrono::month(2) / std::chrono::day(12) /*Monday*/ },
    std::chrono::year_month_day { std::chrono::year(2024) / std::chrono::month(2) / std::chrono::day(13) /*Tuesday*/ },
    std::chrono::year_month_day { std::chrono::year(2024) / std::chrono::month(2) / std::chrono::day(14) /*Wednesday*/ },
    std::chrono::year_month_day { std::chrono::year(2024) / std::chrono::month(2) / std::chrono::day(15) /*Thursday*/ },
    std::chrono::year_month_day { std::chrono::year(2024) / std::chrono::month(2) / std::chrono::day(16) /*Friday*/ }, /*Spring Festival*/
    std::chrono::year_month_day { std::chrono::year(2024) / std::chrono::month(4) / std::chrono::day(4) /*Thursday*/ },
    std::chrono::year_month_day { std::chrono::year(2024) / std::chrono::month(4) / std::chrono::day(5) /*Friday*/ }, /*Qingming Festival*/
    std::chrono::year_month_day { std::chrono::year(2024) / std::chrono::month(5) / std::chrono::day(1) /*Wednesday*/ },
    std::chrono::year_month_day { std::chrono::year(2024) / std::chrono::month(5) / std::chrono::day(2) /*Thursday*/ },
    std::chrono::year_month_day { std::chrono::year(2024) / std::chrono::month(5) / std::chrono::day(3) /*Friday*/ }, /*Workers' Day*/
    std::chrono::year_month_day { std::chrono::year(2024) / std::chrono::month(6) / std::chrono::day(10) /*Monday*/ }, /*Dragon Boat Day*/
    std::chrono::year_month_day { std::chrono::year(2024) / std::chrono::month(9) / std::chrono::day(16) /*Monday*/ },
    std::chrono::year_month_day { std::chrono::year(2024) / std::chrono::month(9) / std::chrono::day(17) /*Tuesday*/ }, /*Mid-Autumn Festival*/
    std::chrono::year_month_day { std::chrono::year(2024) / std::chrono::month(10) / std::chrono::day(1) /*Tuesday*/ },
    std::chrono::year_month_day { std::chrono::year(2024) / std::chrono::month(10) / std::chrono::day(2) /*Wednesday*/ },
    std::chrono::year_month_day { std::chrono::year(2024) / std::chrono::month(10) / std::chrono::day(3) /*Thursday*/ },
    std::chrono::year_month_day { std::chrono::year(2024) / std::chrono::month(10) / std::chrono::day(4) /*Friday*/ },
    std::chrono::year_month_day { std::chrono::year(2024) / std::chrono::month(10) / std::chrono::day(7) /*Monday*/ }, /*National Day*/

};

const std::vector<std::chrono::year_month_day> StockPrvolDays::Festival::_vecSzShBjReopen {
    std::chrono::year_month_day { std::chrono::year(2024) / std::chrono::month(1) / std::chrono::day(2) /*Monday*/ }, /*New Year's Day*/
    std::chrono::year_month_day { std::chrono::year(2024) / std::chrono::month(2) / std::chrono::day(19) /*Friday*/ },
    std::chrono::year_month_day { std::chrono::year(2024) / std::chrono::month(2) / std::chrono::day(19) /*Monday*/ },
    std::chrono::year_month_day { std::chrono::year(2024) / std::chrono::month(2) / std::chrono::day(19) /*Tuesday*/ },
    std::chrono::year_month_day { std::chrono::year(2024) / std::chrono::month(2) / std::chrono::day(19) /*Wednesday*/ },
    std::chrono::year_month_day { std::chrono::year(2024) / std::chrono::month(2) / std::chrono::day(19) /*Thursday*/ },
    std::chrono::year_month_day { std::chrono::year(2024) / std::chrono::month(2) / std::chrono::day(19) /*Friday*/ }, /*Spring Festival*/
    std::chrono::year_month_day { std::chrono::year(2024) / std::chrono::month(4) / std::chrono::day(8) /*Thursday*/ },
    std::chrono::year_month_day { std::chrono::year(2024) / std::chrono::month(4) / std::chrono::day(8) /*Friday*/ }, /*Qingming Festival*/
    std::chrono::year_month_day { std::chrono::year(2024) / std::chrono::month(5) / std::chrono::day(6) /*Wednesday*/ },
    std::chrono::year_month_day { std::chrono::year(2024) / std::chrono::month(5) / std::chrono::day(6) /*Thursday*/ },
    std::chrono::year_month_day { std::chrono::year(2024) / std::chrono::month(5) / std::chrono::day(6) /*Friday*/ }, /*Workers' Day*/
    std::chrono::year_month_day { std::chrono::year(2024) / std::chrono::month(6) / std::chrono::day(11) /*Monday*/ }, /*Dragon Boat Day*/
    std::chrono::year_month_day { std::chrono::year(2024) / std::chrono::month(9) / std::chrono::day(18) /*Monday*/ },
    std::chrono::year_month_day { std::chrono::year(2024) / std::chrono::month(9) / std::chrono::day(18) /*Tuesday*/ }, /*Mid-Autumn Festival*/
    std::chrono::year_month_day { std::chrono::year(2024) / std::chrono::month(10) / std::chrono::day(8) /*Tuesday*/ },
    std::chrono::year_month_day { std::chrono::year(2024) / std::chrono::month(10) / std::chrono::day(8) /*Wednesday*/ },
    std::chrono::year_month_day { std::chrono::year(2024) / std::chrono::month(10) / std::chrono::day(8) /*Thursday*/ },
    std::chrono::year_month_day { std::chrono::year(2024) / std::chrono::month(10) / std::chrono::day(8) /*Friday*/ },
    std::chrono::year_month_day { std::chrono::year(2024) / std::chrono::month(10) / std::chrono::day(8) /*Monday*/ }, /*National Day*/
};

std::filesystem::path StockPrvolDays::Read::_folderPath { "C:/new_tdx/vipdoc/" };

[[nodiscard]] std::filesystem::path& StockPrvolDays::Read::getFolderPath()
{
    return _folderPath;
}

void StockPrvolDays::Read::setFolderPath(std::filesystem::path& val)
{
    _folderPath = val;
}

size_t StockPrvolDays::Read::getFileCount()
{
    return _fileCount;
}

StockPrvolDays::Read::Read(const char* exCode)
{
    _filePath = _folderPath;
    if ('1' == exCode[0]) {
        _filePath += "sh/lday/sh";
        _filePath += &exCode[1];
        _filePath += ".day";
    } else if ('0' == exCode[0]) {
        _filePath += "sz/lday/sz";
        _filePath += &exCode[1];
        _filePath += ".day";
    } else if ('2' == exCode[0]) {
        _filePath += "bj/lday/bj";
        _filePath += &exCode[1];
        _filePath += ".day";

    } else {
        throw std::invalid_argument("invalid_argument-exCode.");
    }
    if (!std::filesystem::exists(_filePath)) {
        _fileCount = 0;
    } else {
        const uintmax_t fileSize { std::filesystem::file_size(_filePath) };
        _fileCount = fileSize / 32;
    }
}

}
