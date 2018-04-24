#ifndef DATE_H
#define DATE_H

#include <istream>
#include <string>
#include <cstdint>

namespace mc {
    namespace utils {

        typedef std::int64_t year_t;
        typedef std::uint8_t month_t;
        typedef std::uint8_t day_t;

        class date_t {
            year_t _year;
            month_t _month;
            day_t _day;
            
            std::string _format;
        public:
            date_t();
            date_t(const date_t&);
            date_t(year_t, month_t, day_t);
            static date_t current();
            std::string toString() const;
            std::string format() const;
            void format(std::string);

            year_t year() const;
            month_t month() const;
            day_t day() const;
            
            date_t operator = (const date_t&);
        };

        bool operator == (const date_t&, const date_t&);
        bool operator < (const date_t&, const date_t&);
        
        std::istream& operator>>(std::istream&, date_t&);
        std::ostream& operator<<(std::ostream&, const date_t&);
    }
}

#endif /* DATE_H */

