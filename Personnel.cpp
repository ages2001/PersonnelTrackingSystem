#include "Personnel.h"

int Personnel::getNumber() const {
    return this->number;
}

const string &Personnel::getName() const {
    return this->name;
}

const string &Personnel::getSurname() const {
    return this->surname;
}

const string &Personnel::getTitle() const {
    return this->title;
}

double Personnel::getSalaryCoefficient() const {
    return this->salaryCoefficient;
}

Date *Personnel::getBirthDate() const {
    return this->birthDate;
}

Date *Personnel::getAppointmentDate() const {
    return this->appointmentDate;
}

int Personnel::getServiceDays() const {
    return this->serviceDays;
}

void Personnel::setNumber(int number) {
    Personnel::number = number;
}

void Personnel::setName(const string &name) {
    Personnel::name = name;
}

void Personnel::setSurname(const string &surname) {
    Personnel::surname = surname;
}

void Personnel::setTitle(const string &title) {
    Personnel::title = title;
}

void Personnel::setSalaryCoefficient(double salaryCoefficient) {
    Personnel::salaryCoefficient = salaryCoefficient;
}

void Personnel::setBirthDate(Date *birthDate) {
    Personnel::birthDate = birthDate;
}

void Personnel::setAppointmentDate(Date *appointmentDate) {
    Personnel::appointmentDate = appointmentDate;
}

void Personnel::setServiceDays(int serviceDays) {
    Personnel::serviceDays = serviceDays;
}

Personnel::Personnel() {
    setNumber(NULL);
    // setName(NULL);
    // setSurname(NULL);
    // setTitle(NULL);
    setSalaryCoefficient(NULL);

    Date *birthDate = new Date();
    Date *appointmentDate = new Date();
    setBirthDate(birthDate);
    setAppointmentDate(appointmentDate);

    setServiceDays(NULL);
}

Personnel::~Personnel() {

}

ostream &operator<<(ostream &out, const Personnel &personnel) {
    out << "\nPersonnel number: " << personnel.getNumber() << "\n";
    out << "Personnel name: " << personnel.getName() << "\n";
    out << "Personnel surname: " << personnel.getSurname() << "\n";
    out << "Personnel title: " << personnel.getTitle() << "\n";
    out << "Personnel salary coefficient: " << personnel.getSalaryCoefficient() << "\n";
    out << "Personnel birthdate: " << *personnel.getBirthDate() << "\n";
    out << "Personnel appointment date: " << *personnel.getAppointmentDate() << "\n";
    out << "Personnel service days: " << personnel.getServiceDays() << "\n";

    return out;
}

