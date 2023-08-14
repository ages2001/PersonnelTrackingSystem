#include <iostream>
#include <string>
#include "Date.h"

#pragma once

using namespace std;

class Personnel {
private:
    int number;
    string name;
    string surname;
    string title;
    double salaryCoefficient;
    Date *birthDate;
    Date *appointmentDate;
    int serviceDays;

public:
    const string &getName() const;

    const string &getSurname() const;

    const string &getTitle() const;

    double getSalaryCoefficient() const;

    Date * getBirthDate() const;

    Date * getAppointmentDate() const;

    int getServiceDays() const;

    int getNumber() const;

    void setNumber(int number);

    void setName(const string &name);

    void setSurname(const string &surname);

    void setTitle(const string &title);

    void setSalaryCoefficient(double salaryCoefficient);

    void setBirthDate(Date *birthDate);

    void setAppointmentDate(Date *appointmentDate);

    void setServiceDays(int serviceDays);

    Personnel(); // constructor

    ~Personnel(); // destructor

    friend ostream &operator<<(ostream &out, const Personnel &personnel); // overriding toString() method
};
