#include <iostream>
#include <sstream>

using namespace std;

class Date {
private:
    int month;
    int day;
    int year;

public:
    int getMonth() const;

    int getDay() const;

    int getYear() const;

    void setMonth(int month);

    void setDay(int day);

    void setYear(int year);

    Date(); // constructor

    ~Date(); // destructor

    static void splitString(const std::string &input, char delimiter, Date *date); // split string

    friend ostream &operator<<(ostream &out, const Date &date); // overriding toString() method

    /* overriding compare operators */
    bool operator==(const Date &other) const;

    bool operator<(const Date &other) const;

    bool operator>(const Date &other) const;

    bool operator<=(const Date &other) const;

    bool operator>=(const Date &other) const;
};
