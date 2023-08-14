#include "Date.h"

int Date::getMonth() const {
    return this->month;
}

int Date::getDay() const {
    return this->day;
}

int Date::getYear() const {
    return this->year;
}

void Date::setMonth(int month) {
    Date::month = month;
}

void Date::setDay(int day) {
    Date::day = day;
}

void Date::setYear(int year) {
    Date::year = year;
}

Date::Date() {
    setMonth(1);
    setDay(1);
    setYear(1970);
}

Date::~Date() {

}

void Date::splitString(const string &input, char delimiter, Date *date) {
    string::size_type start = 0;
    string::size_type end = input.find(delimiter, start);
    int index = 0;

    string output[3];

    while (end != string::npos && index < 2) {
        output[index++] = input.substr(start, end - start);
        start = end + 1;
        end = input.find(delimiter, start);
    }

    if (start < input.length())
        output[index] = input.substr(start);

    int monthInt, dayInt, yearInt;

    istringstream iss1(output[0]);
    iss1 >> monthInt;
    date->setMonth(monthInt);

    istringstream iss2(output[1]);
    iss2 >> dayInt;
    date->setDay(dayInt);

    istringstream iss3(output[2]);
    iss3 >> yearInt;
    date->setYear(yearInt);
}

ostream &operator<<(ostream &out, const Date &date) {
    out << date.getMonth() << "/" << date.getDay() << "/" << date.getYear();
    return out;
}

bool Date::operator==(const Date &other) const {
    return month == other.month && day == other.day && year == other.year;
}

bool Date::operator<(const Date &other) const {
    if (year != other.year)
        return year < other.year;
    if (month != other.month)
        return month < other.month;
    return day < other.day;
}

bool Date::operator>(const Date &other) const {
    return other < *this;
}

bool Date::operator<=(const Date &other) const {
    return !(other < *this);
}

bool Date::operator>=(const Date &other) const {
    return !(*this < other);
}
