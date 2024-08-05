// Copyright (c) 2024-present, Shuai (Mason) Zhao
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include "..\..\include\StraightStock\StraightStockPrvol.h"

namespace STRAIGHTSTOCK {
StockPrvol::StockPrvol(const double open, const double high, const double low, const double close, const double volume, const double amount, const double turnover) noexcept
    : _open(open)
    , _high(high)
    , _low(low)
    , _close(close)
    , _volume(volume)
    , _amount(amount)
    , _turnover(turnover)
{
}

void StockPrvol::setOpen(const double open) noexcept { _open = open; }

void StockPrvol::setHigh(const double high) noexcept { _high = high; }

void StockPrvol::setLow(const double low) noexcept { _low = low; }

void StockPrvol::setClose(const double close) noexcept { _close = close; }

void StockPrvol::setVolume(const double volume) noexcept { _volume = volume; }

void StockPrvol::setAmount(const double amount) noexcept { _amount = amount; }

void StockPrvol::setTurnover(const double turnover) noexcept { _turnover = turnover; }

std::ostream& StockPrvol::operator<<(std::ostream& os) const noexcept
{
    return os << std::fixed
              << std::setprecision(2) << _open << ',' << _high << ',' << _low << ',' << _close << ','
              << std::setprecision(0) << _volume << ',' << _amount << ','
              << std::setprecision(2) << _turnover;
}

[[nodiscard]] double StockPrvol::getOpen() const noexcept { return _open; }

[[nodiscard]] double StockPrvol::getHigh() const noexcept { return _high; }

[[nodiscard]] double StockPrvol::getLow() const noexcept { return _low; }

[[nodiscard]] double StockPrvol::getClose() const noexcept { return _close; }

[[nodiscard]] double StockPrvol::getVolume() const noexcept { return _volume; }

[[nodiscard]] double StockPrvol::getAmount() const noexcept { return _amount; }

[[nodiscard]] double StockPrvol::getTurnover() const noexcept { return _turnover; }

StockPrvolMinute::StockPrvolMinute(const double open, const double high, const double low, const double close, const double volume, const double amount, const double turnover, const std::chrono::time_point<std::chrono::system_clock, std::chrono::minutes>& timePoint) noexcept
    : StockPrvol(open, high, low, close, volume, amount, turnover)
    , _timePoint(timePoint)
{
}

void StockPrvolMinute::setTimePoint(const std::chrono::time_point<std::chrono::system_clock, std::chrono::minutes>& timePoint) noexcept
{
    _timePoint = timePoint;
}

std::ostream& StockPrvolMinute::operator<<(std::ostream& os) const noexcept
{
    StockPrvol::operator<<(os);
    return os << ',' << _timePoint;
}

const std::chrono::time_point<std::chrono::system_clock, std::chrono::minutes>& StockPrvolMinute::getTimePoint() const noexcept
{
    return _timePoint;
}

StockPrvolDay::StockPrvolDay(const double open, const double high, const double low, const double close, const double volume, const double amount, const double turnover, const std::chrono::year_month_day& timePoint) noexcept
    : StockPrvol(open, high, low, close, volume, amount, turnover)
    , _timePoint(timePoint)
{
}

void StockPrvolDay::setTimePoint(const std::chrono::year_month_day& timePoint) noexcept
{
    _timePoint = timePoint;
}

std::ostream& StockPrvolDay::operator<<(std::ostream& os) const noexcept
{
    StockPrvol::operator<<(os);
    return os << ',' << _timePoint;
}

const std::chrono::year_month_day& StockPrvolDay::getTimePoint() const noexcept
{
    return _timePoint;
}

StockPrvolWeek::StockPrvolWeek(const double open, const double high, const double low, const double close, const double volume, const double amount, const double turnover, const std::chrono::year_month_day& timePoint) noexcept
    : StockPrvol(open, high, low, close, volume, amount, turnover)
    , _timePoint(timePoint)
{
}

void StockPrvolWeek::setTimePoint(const std::chrono::year_month_day& timePoint) noexcept
{
    _timePoint = timePoint;
}

std::ostream& StockPrvolWeek::operator<<(std::ostream& os) const noexcept
{
    StockPrvol::operator<<(os);
    return os << ',' << _timePoint;
}

const std::chrono::year_month_day& StockPrvolWeek::getTimePoint() const noexcept
{
    return _timePoint;
}

StockPrvolMonth::StockPrvolMonth(const double open, const double high, const double low, const double close, const double volume, const double amount, const double turnover, const std::chrono::year_month_day& timePoint) noexcept
    : StockPrvol(open, high, low, close, volume, amount, turnover)
    , _timePoint(timePoint)
{
}

void StockPrvolMonth::setTimePoint(const std::chrono::year_month_day& timePoint) noexcept
{
    _timePoint = timePoint;
}

std::ostream& StockPrvolMonth::operator<<(std::ostream& os) const noexcept
{
    StockPrvol::operator<<(os);
    return os << ',' << _timePoint;
}

const std::chrono::year_month_day& StockPrvolMonth::getTimePoint() const noexcept
{
    return _timePoint;
}

StockPrvolYear::StockPrvolYear(const double open, const double high, const double low, const double close, const double volume, const double amount, const double turnover, const std::chrono::year_month_day& timePoint) noexcept
    : StockPrvol(open, high, low, close, volume, amount, turnover)
    , _timePoint(timePoint)
{
}

void StockPrvolYear::setTimePoint(const std::chrono::year_month_day& timePoint) noexcept
{
    _timePoint = timePoint;
}

std::ostream& StockPrvolYear::operator<<(std::ostream& os) const noexcept
{
    StockPrvol::operator<<(os);
    return os << ',' << _timePoint;
}

const std::chrono::year_month_day& StockPrvolYear::getTimePoint() const noexcept
{
    return _timePoint;
}

}
