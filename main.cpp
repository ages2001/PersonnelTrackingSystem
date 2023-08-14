#include "CircularLinkedList.h"
#include "CircularDoublyLinkedList.h"

int main() {

    int operation;
    CircularLinkedList *singlyList = new CircularLinkedList();
    CircularDoublyLinkedList *doublyList = new CircularDoublyLinkedList();

    cout << "\nWelcome to the personnel tracking system!\n";
    cout << "*****************************************\n\n";
    cout << " 0 - Exiting from program\n";
    cout << " 1 - Appointment of a first-time personnel to the organization\n";
    cout << " 2 - Appointment of a personnel transferred from another institution to the institution\n";
    cout << " 3 - Updating the title and salary coefficient of a personnel\n";
    cout << " 4 - Deleting a personnel\n";
    cout << " 5 - Listing the information of a personnel\n";
    cout << " 6 - Listing of all personnel in order of personnel number\n";
    cout << " 7 - Listing of all personnel in order of date of appointment to the organization\n";
    cout << " 8 - Listing of personnel assigned to the organization after a certain appointment date\n";
    cout << " 9 - Listing of personnel appointed to the organization in a given year\n";
    cout << "10 - Listing of personnel born before a certain birthdate\n";
    cout << "11 - Listing of personnel born in a specific month\n";
    cout
            << "12 - Listing the information of the last personnel appointed to the organization from the personnel with a specific title\n\n";

    while (true) {
        cout << "\nEnter the operation (0 - 12): ";
        cin >> operation;

        switch (operation) {
            case 0: {
                singlyList->freeList();
                doublyList->freeList();

                cout << "\nLists have been freed!\nExiting...\n\n";
                return 0;
            }

            case 1: {
                int number;
                string name, surname, title, bDateStr, aDateStr;
                double salaryCoefficient;
                Date *birthDate = new Date(), *appointmentDate = new Date();

                Personnel *newPersonnel = new Personnel();

                cout << "\nEnter the new personnel number: ";
                cin >> number;
                if (singlyList->isNumberExist(number)) {
                    cout << "This personnel number is already exists in one of the other personnel!\n";
                    break;
                }

                cin.ignore();
                cout << "Enter the new personnel name: ";
                getline(cin, name);
                cout << "Enter the new personnel surname: ";
                getline(cin, surname);
                cout << "Enter the new personnel title: ";
                getline(cin, title);
                cout << "Enter the new personnel salary coefficient: ";
                cin >> salaryCoefficient;

                cin.ignore();
                cout << "Enter the new personnel birthdate (MM/DD/YYYY): ";
                getline(cin, bDateStr);
                Date::splitString(bDateStr, '/', birthDate);

                cout << "Enter the new personnel appointment date (MM/DD/YYYY): ";
                getline(cin, aDateStr);
                Date::splitString(aDateStr, '/', appointmentDate);

                newPersonnel->setNumber(number);
                newPersonnel->setName(name);
                newPersonnel->setSurname(surname);
                newPersonnel->setTitle(title);
                newPersonnel->setSalaryCoefficient(salaryCoefficient);
                newPersonnel->setBirthDate(birthDate);
                newPersonnel->setAppointmentDate(appointmentDate);
                newPersonnel->setServiceDays(0);

                singlyList->add(newPersonnel);
                doublyList->add(newPersonnel);

                break;
            }

            case 2: {
                int number, serviceDays;
                string name, surname, title, bDateStr, aDateStr;
                double salaryCoefficient;
                Date *birthDate = new Date(), *appointmentDate = new Date();

                Personnel *newPersonnel = new Personnel();

                cout << "\nEnter the transferred personnel number: ";
                cin >> number;
                if (singlyList->isNumberExist(number)) {
                    cout << "This personnel number is already exists in one of the other personnel!\n";
                    break;
                }

                cin.ignore();
                cout << "Enter the transferred personnel name: ";
                getline(cin, name);
                cout << "Enter the transferred personnel surname: ";
                getline(cin, surname);
                cout << "Enter the transferred personnel title: ";
                getline(cin, title);
                cout << "Enter the transferred personnel salary coefficient: ";
                cin >> salaryCoefficient;

                cin.ignore();
                cout << "Enter the new personnel birthdate (MM/DD/YYYY): ";
                getline(cin, bDateStr);
                Date::splitString(bDateStr, '/', birthDate);

                cout << "Enter the new personnel appointment date (MM/DD/YYYY): ";
                getline(cin, aDateStr);
                Date::splitString(aDateStr, '/', appointmentDate);

                cout << "Enter the transferred personnel's total service days: ";
                cin >> serviceDays;

                newPersonnel->setNumber(number);
                newPersonnel->setName(name);
                newPersonnel->setSurname(surname);
                newPersonnel->setTitle(title);
                newPersonnel->setSalaryCoefficient(salaryCoefficient);
                newPersonnel->setBirthDate(birthDate);
                newPersonnel->setAppointmentDate(appointmentDate);
                newPersonnel->setServiceDays(serviceDays);

                singlyList->add(newPersonnel);
                doublyList->add(newPersonnel);

                break;
            }

            case 3: {
                int number;
                cout << "\nEnter the personnel number to update personnel: ";
                cin >> number;

                singlyList->update(number);
                break;
            }

            case 4: {
                int number;
                cout << "\nEnter the personnel number to delete personnel: ";
                cin >> number;

                singlyList->remove(number);
                doublyList->remove(number);

                break;
            }

            case 5: {
                int number;
                cout << "\nEnter the personnel number to find personnel: ";
                cin >> number;

                singlyList->findPersonnel(number);

                break;
            }

            case 6: {
                cout << *singlyList;
                break;
            }

            case 7: {
                doublyList->printList();
                break;
            }

            case 8: {
                string aDateStr;
                Date *aDate = new Date();

                cin.ignore();
                cout << "\nEnter the appointment date: ";
                getline(cin, aDateStr);

                Date::splitString(aDateStr, '/', aDate);

                doublyList->printAfterADate(aDate);
                break;
            }

            case 9: {
                int year;
                cout << "\nEnter the year: ";
                cin >> year;

                doublyList->printSpecYearInfo(year);
                break;
            }

            case 10: {
                string bDateStr;
                Date *bDate = new Date();

                cin.ignore();
                cout << "\nEnter the birthdate: ";
                getline(cin, bDateStr);

                Date::splitString(bDateStr, '/', bDate);

                singlyList->printBeforeBDate(bDate);
                break;
            }

            case 11: {
                int month;
                cout << "\nEnter the birth month: ";
                cin >> month;

                singlyList->printSpecifiedBMonth(month);
                break;
            }

            case 12: {
                string title;

                cin.ignore();
                cout << "\nEnter the title: ";
                getline(cin, title);

                doublyList->printLatestTitlePersonnel(title);
                break;
            }

            default:
                cout << "\nInvalid operation!\n";
        }
    }
}
