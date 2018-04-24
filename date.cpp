#include "date.h"

#include <ctime>
#include <sstream>

namespace mc {
    namespace utils {

        date_t::date_t() 
            :   _year(2017), 
                _month(1), 
                _day(1), 
                _format("Y-m-d") {
        }

        date_t::date_t(const date_t& date) 
            :   _year(date._year), 
                _month(date._month),
                _day(date._day), 
                _format(date._format) {
        }

        date_t::date_t(year_t year, month_t month, day_t day) {
            // TODO #: check parameters
            _day = day;
            _month = month;
            _year = year;
            _format = "Y-m-d";
        }

        date_t date_t::current() {
            time_t rawtime;
            tm * timeinfo;

            time(&rawtime);
            timeinfo = localtime(&rawtime);

            return date_t(timeinfo->tm_year, timeinfo->tm_mon + 1, timeinfo->tm_mday);
        }

        std::string date_t::toString() const {
            std::ostringstream strout;
            strout << _year << "-" << _month << "-" << _day;
            return strout.str();
        }

        std::string date_t::format() const {
            return _format;
        }

        void date_t::format(const std::string& format) {
            _format = format;
        }

        year_t date_t::year() const {
            return _year;
        }

        month_t date_t::month() const {
            return _month;
        }

        day_t date_t::day() const {
            return _day;
        }

        date_t date_t::operator=(const date_t& date) {
            _year = date._year;
            _month = date._month;
            _day = date._day;
            _format = date._format;
            return *this;
        }

        bool operator==(const date_t& lvalue, const date_t& rvalue) {
            return lvalue.year() == rvalue.year() &&
                    lvalue.month() == rvalue.month() &&
                    lvalue.day() == rvalue.day();
        }

        bool operator<(const date_t& lvalue, const date_t& rvalue) {
            return (lvalue.year() < rvalue.year()) ||
                    (lvalue.year() == rvalue.year() && lvalue.month() < rvalue.month()) ||
                    (lvalue.year() == rvalue.year() && lvalue.month() == rvalue.month() && lvalue.day() < rvalue.day());
        }

        std::istream& operator>>(std::istream& in, date_t& date) {
            // TODO #: use format for reading
            year_t year;
            month_t month;
            day_t day;
            char chr;
            in >> year >> chr >> month >> chr >> day;
            return in;
        }

        std::ostream& operator<<(std::ostream& out, const date_t& date) {
            out << date.toString();
            return out;
        }
    }
}