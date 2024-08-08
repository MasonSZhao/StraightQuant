// Copyright (c) 2024-present, Shuai (Mason) Zhao
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#pragma once

#include "StraightStockPrvol.h"
#include <chrono>
#include <filesystem>
#include <fstream>
#include <vector>

namespace STRAIGHTSTOCK {
/**
 * @brief Provides functionalities (festival, read, decode) about a collection of all the StockPrvolDay objects.
 */
class StockPrvolDays {
private:
public:
    class Festival {
    private:
    public:
        /**
         * @brief Represents the dates which Shenzhen, Shanghai and Beijing exchange start to close.
         */
        static const std::vector<std::chrono::year_month_day> _vecSzShBjClose;

        /**
         * @brief Represents the dates which Shenzhen, Shanghai and Beijing exchange start to reopen.
         */
        static const std::vector<std::chrono::year_month_day> _vecSzShBjReopen;
    };

    class Read {
    private:
        /**
         * @brief Represents the folder path which stores all different files. Each file stores a collection of StockPrvolDay data.
         * @details The data is stored by exchange code rather than by date. Each file stores the StockPrvolDay data of the same exchagne code with different dates.
         */
        static std::filesystem::path _folderPath;

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
        /**
         * @brief Represents how many data dates are stored in the file.
         */
        size_t _fileCount { 0 };

        /**
         * @brief Represents the file path.
         */
        std::filesystem::path _filePath {};

    public:
        /**
         * @brief The default constructor is deleted.
         */
        Read() = delete;

        /**
         * @brief Find the disk file of the given exchange code.
         * @param exCode The exchange code.
         */
        Read(const char* exCode);

        /**
         * @brief The getter of the file count.
         * @return The count.
         */
        size_t getFileCount();

        /**
         * @brief Read a collection of StockPrvolDay objects according to the user requests from the disk file as possible as the program can.
         * @param des The destionation to read to.
         * @param start Represents how many StockPrvolDay objects the user wants to shift. 0 means the last will be the latest date on the disk, 1 means the last will be the date before the latest, and so on.
         * @param count Represents how many StockPrvolDay objects the user wants to read in.
         * @return The actual count of the StockPrvolDay objects.
         * @details This function doesn't take advantage of destination container's reserve, like:
         *     - 'template <template <typename> typename SeqOut, typename Enable = void> struct Read {...};'
         *     - 'template <template <typename> typename SeqOut> struct reader_DayPrvol<SeqOut, typename std::enable_if<std::is_same<SeqOut<StockPrvolDay>, std::vector<StockPrvolDay>>::value>::type> {...}'
         */
        template <template <typename> typename SeqOut>
        size_t operator()(SeqOut<StockPrvolDay>& des, const size_t start, const size_t count)
        {
            if (0 == _fileCount) {
                return 0;
            } else {
                if (_fileCount <= start) {
                    return 0;
                } else {
                    size_t actualCount { 0 };
                    size_t itForward { 0 };
                    if (0 == count || (_fileCount <= (start + count))) { // return the elements from the earliest index to the start index
                        actualCount = _fileCount - start;
                        itForward = 0;
                    } else { // return the elements from the start - count index to the start index
                        actualCount = count;
                        itForward = _fileCount - start - count;
                    }
                    std::ifstream ifs(_filePath, std::ifstream::in | std::ifstream::binary);
                    if (itForward > 0)
                        ifs.seekg(itForward * 32 /*bytes*/, std::ifstream::beg);
                    std::vector<int> intBuffer(actualCount * 8);
                    ifs.read(reinterpret_cast<char*>(&intBuffer[0]), actualCount * 32 /*bytes*/);
                    ifs.close();

                    for (size_t i { 0 }; i < actualCount; ++i) {
                        int dateInt { intBuffer[i * 8 + 0] };
                        int monthDayInt { (dateInt % 10000) };
                        des.push_back(StockPrvolDay(
                            intBuffer[i * 8 + 1] / 100., // open
                            intBuffer[i * 8 + 2] / 100., // high
                            intBuffer[i * 8 + 3] / 100., // low
                            intBuffer[i * 8 + 4] / 100., // close
                            intBuffer[i * 8 + 6] / 100., // volume
                            *(float*)&intBuffer[i * 8 + 5], // amount
                            std::numeric_limits<double>::quiet_NaN(), // turnover
                            std::chrono::year_month_day { std::chrono::year(dateInt / 10000) / std::chrono::month(monthDayInt / 100) / std::chrono::day(monthDayInt % 100) }));
                    }
                    return actualCount;
                }
            }
        }

    };

};

}
