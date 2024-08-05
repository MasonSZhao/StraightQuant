// Copyright (c) 2024-present, Shuai (Mason) Zhao
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#pragma once

#include <chrono>
#include <iostream>

namespace STRAIGHTSTOCK {
/**
 * @brief Represents the stock candlestick.
 */
class StockPrvol {
private:
    /**
     * @brief Represents the open price of the candlestick.
     */
    double _open { 0 };

    /**
     * @brief Represents the high price of the candlestick.
     */
    double _high { 0 };

    /**
     * @brief Represents the low price of the candlestick.
     */
    double _low { 0 };

    /**
     * @brief Represents the close price of the candlestick.
     */
    double _close { 0 };

    /**
     * @brief Represents the amount of the candlestick.
     */
    double _amount { 0 };

    /**
     * @brief Represents the volume of the canldestick.
     */
    double _volume { 0 };

    /**
     * @brief Represents the turnover of the candlestick.
     */
    double _turnover { 0 };

public:
    /**
     * @brief The default constructor.
     */
    StockPrvol() = default;

    /**
     * @brief The constructor.
     * @param open The open price to initialize to.
     * @param high The high price to initialize to.
     * @param low The low price to initialize to.
     * @param close The close price to initialize to.
     * @param volume The volume to initialize to.
     * @param amount The amount to initialize to.
     * @param turnover The turnover to initialize to.
     */
    StockPrvol(const double open, const double high, const double low, const double close, const double volume, const double amount, const double turnover) noexcept;

    /**
     * @brief The setter of the open price.
     * @param val The value to set to.
     */
    void setOpen(const double val) noexcept;

    /**
     * @brief The setter of the high price.
     * @param val The value to set to.
     */
    void setHigh(const double val) noexcept;

    /**
     * @brief The setter of the low price.
     * @param val The value to set to.
     */
    void setLow(const double val) noexcept;

    /**
     * @brief The setter of the close price.
     * @param val The value to set to.
     */
    void setClose(const double val) noexcept;

    /**
     * @brief The setter of the volume.
     * @param val The value to set to.
     */
    void setVolume(const double val) noexcept;

    /**
     * @brief The setter of the amount.
     * @param val The value to set to.
     */
    void setAmount(const double val) noexcept;

    /**
     * @brief The setter of the turnover.
     * @param val The value to set to.
     */
    void setTurnover(const double val) noexcept;

    std::ostream& operator<<(std::ostream& os) const noexcept;

    /**
     * @brief The getter of the open price.
     * @return The open price.
     */
    [[nodiscard]] double getOpen() const noexcept;

    /**
     * @brief The getter of the high price.
     * @return The high price.
     */
    [[nodiscard]] double getHigh() const noexcept;

    /**
     * @brief The getter of the low price.
     * @return The low price.
     */
    [[nodiscard]] double getLow() const noexcept;

    /**
     * @brief The getter of the close price.
     * @return The close price.
     */
    [[nodiscard]] double getClose() const noexcept;

    /**
     * @brief The getter of the volume.
     * @return The volume.
     */
    [[nodiscard]] double getVolume() const noexcept;

    /**
     * @brief The getter of the amount.
     * @return The amount.
     */
    [[nodiscard]] double getAmount() const noexcept;

    /**
     * @brief The getter of the turnover.
     * @return The turnover.
     */
    [[nodiscard]] double getTurnover() const noexcept;
};

/**
 * @brief Represents the stock candlestick of one minute.
 */
class StockPrvolMinute : public StockPrvol {
private:
    /**
     * @brief Represents the minute timepoint of the candlestick.
     */
    std::chrono::time_point<std::chrono::system_clock, std::chrono::minutes> _timePoint {};

public:
    /**
     * @brief The default constructor.
     */
    StockPrvolMinute() = default;

    /**
     * @brief The constructor.
     * @param open The open price to initialize to.
     * @param high The high price to initialize to.
     * @param low The low price to initialize to.
     * @param close The close price to initialize to.
     * @param volume The volume to initialize to.
     * @param amount The amount to initialize to.
     * @param turnover The turnover to initialize to.
     * @param timePoint The timePoint to initialize to.
     */
    StockPrvolMinute(const double open, const double high, const double low, const double close, const double volume, const double amount, const double turnover, const std::chrono::time_point<std::chrono::system_clock, std::chrono::minutes>& timePoint) noexcept;

    /**
     * @brief The setter of the time point.
     * @param timePoint The value to set to.
     */
    void setTimePoint(const std::chrono::time_point<std::chrono::system_clock, std::chrono::minutes>& timePoint) noexcept;

    std::ostream& operator<<(std::ostream& os) const noexcept;

    /**
     * @brief The getter of the time point.
     * @return The time point.
     */
    [[nodiscard]] const std::chrono::time_point<std::chrono::system_clock, std::chrono::minutes>& getTimePoint() const noexcept;
};
/**
 * @brief Represents the stock candlestick of one day.
 */
class StockPrvolDay : public StockPrvol {
private:
    /**
     * @brief Represents the day timepoint of the candlestick.
     */
    std::chrono::year_month_day _timePoint {};

public:
    /**
     * @brief The default constructor.
     */
    StockPrvolDay() = default;

    /**
     * @brief The constructor.
     * @param open The open price to initialize to.
     * @param high The high price to initialize to.
     * @param low The low price to initialize to.
     * @param close The close price to initialize to.
     * @param volume The volume to initialize to.
     * @param amount The amount to initialize to.
     * @param turnover The turnover to initialize to.
     * @param timePoint The timePoint to initialize to.
     */
    StockPrvolDay(const double open, const double high, const double low, const double close, const double volume, const double amount, const double turnover, const std::chrono::year_month_day& timePoint) noexcept;

    /**
     * @brief The setter of the time point.
     * @param timePoint The value to set to.
     */
    void setTimePoint(const std::chrono::year_month_day& timePoint) noexcept;

    std::ostream& operator<<(std::ostream& os) const noexcept;

    /**
     * @brief The getter of the time point.
     * @return The time point.
     */
    [[nodiscard]] const std::chrono::year_month_day& getTimePoint() const noexcept;
};

/**
 * @brief Represents the stock candlestick of one week.
 */
class StockPrvolWeek : public StockPrvol {
private:
    /**
     * @brief Represents the week timepoint of the candlestick.
     */
    std::chrono::year_month_day _timePoint {};

public:
    /**
     * @brief The default constructor.
     */
    StockPrvolWeek() = default;

    /**
     * @brief The constructor.
     * @param open The open price to initialize to.
     * @param high The high price to initialize to.
     * @param low The low price to initialize to.
     * @param close The close price to initialize to.
     * @param volume The volume to initialize to.
     * @param amount The amount to initialize to.
     * @param turnover The turnover to initialize to.
     * @param timePoint The timePoint to initialize to.
     */
    StockPrvolWeek(const double open, const double high, const double low, const double close, const double volume, const double amount, const double turnover, const std::chrono::year_month_day& timePoint) noexcept;

    /**
     * @brief The setter of the time point.
     * @param timePoint The value to set to.
     */
    void setTimePoint(const std::chrono::year_month_day& timePoint) noexcept;

    std::ostream& operator<<(std::ostream& os) const noexcept;

    /**
     * @brief The getter of the time point.
     * @return The time point.
     */
    [[nodiscard]] const std::chrono::year_month_day& getTimePoint() const noexcept;
};

/**
 * @brief Represents the stock candlestick of one month.
 */
class StockPrvolMonth : public StockPrvol {
private:
    /**
     * @brief Represents the month timepoint of the candlestick.
     */
    std::chrono::year_month_day _timePoint {};

public:
    /**
     * @brief The default constructor.
     */
    StockPrvolMonth() = default;

    /**
     * @brief The constructor.
     * @param open The open price to initialize to.
     * @param high The high price to initialize to.
     * @param low The low price to initialize to.
     * @param close The close price to initialize to.
     * @param volume The volume to initialize to.
     * @param amount The amount to initialize to.
     * @param turnover The turnover to initialize to.
     * @param timePoint The timePoint to initialize to.
     */
    StockPrvolMonth(const double open, const double high, const double low, const double close, const double volume, const double amount, const double turnover, const std::chrono::year_month_day& timePoint) noexcept;

    /**
     * @brief The setter of the time point.
     * @param timePoint The value to set to.
     */
    void setTimePoint(const std::chrono::year_month_day& timePoint) noexcept;

    std::ostream& operator<<(std::ostream& os) const noexcept;

    /**
     * @brief The getter of the time point.
     * @return The time point.
     */
    [[nodiscard]] const std::chrono::year_month_day& getTimePoint() const noexcept;
};

/**
 * @brief Represents the stock candlestick of one year.
 */
class StockPrvolYear : public StockPrvol {
private:
    /**
     * @brief Represents the year timepoint of the candlestick.
     */
    std::chrono::year_month_day _timePoint {};

public:
    /**
     * @brief The default constructor.
     */
    StockPrvolYear() = default;

    /**
     * @brief The constructor.
     * @param open The open price to initialize to.
     * @param high The high price to initialize to.
     * @param low The low price to initialize to.
     * @param close The close price to initialize to.
     * @param volume The volume to initialize to.
     * @param amount The amount to initialize to.
     * @param turnover The turnover to initialize to.
     * @param timePoint The timePoint to initialize to.
     */
    StockPrvolYear(const double open, const double high, const double low, const double close, const double volume, const double amount, const double turnover, const std::chrono::year_month_day& timePoint) noexcept;

    /**
     * @brief The setter of the time point.
     * @param timePoint The value to set to.
     */
    void setTimePoint(const std::chrono::year_month_day& timePoint) noexcept;

    std::ostream& operator<<(std::ostream& os) const noexcept;

    /**
     * @brief The getter of the time point.
     * @return The time point.
     */
    [[nodiscard]] const std::chrono::year_month_day& getTimePoint() const noexcept;
};

}
