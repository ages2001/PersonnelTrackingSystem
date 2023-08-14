#include "CircularDoublyLinkedList.h"

void DoubleNode::setData(Personnel *data) {
    this->data = data;
}

void DoubleNode::setNext(DoubleNode *next) {
    this->next = next;
}

void DoubleNode::setPrev(DoubleNode *prev) {
    this->prev = prev;
}

Personnel *DoubleNode::getData() const {
    return this->data;
}

DoubleNode *DoubleNode::getNext() const {
    return this->next;
}

DoubleNode *DoubleNode::getPrev() const {
    return this->prev;
}

DoubleNode::DoubleNode() {
    Personnel *personnel = new Personnel();
    setData(personnel);
    setNext(NULL);
    setPrev(NULL);
}

DoubleNode::DoubleNode(Personnel *data, DoubleNode *next, DoubleNode *prev) {
    setData(data);
    setNext(next);
    setPrev(prev);
}

DoubleNode::~DoubleNode() {

}


DoubleNode *CircularDoublyLinkedList::getHead() const {
    return this->head;
}

void CircularDoublyLinkedList::setHead(DoubleNode *head) {
    this->head = head;
}

CircularDoublyLinkedList::CircularDoublyLinkedList() {
    setHead(NULL);
}

CircularDoublyLinkedList::~CircularDoublyLinkedList() {

}

bool CircularDoublyLinkedList::isEmpty() const {
    return getHead() == NULL;
}

void CircularDoublyLinkedList::add(Personnel *data) {
    if (isEmpty()) {
        DoubleNode *newNode = new DoubleNode(data, NULL, NULL);
        newNode->setNext(newNode);
        newNode->setPrev(newNode);

        setHead(newNode);
        return;
    }

    DoubleNode *current = getHead(), *newNode;

    do {
        if (*(data->getAppointmentDate()) < *(current->getData()->getAppointmentDate()))
            break;

        current = current->getNext();
    } while (current->getNext() != getHead());

    if (current == getHead()) {
        if (*(data->getAppointmentDate()) < *(getHead()->getData()->getAppointmentDate())) {
            newNode = new DoubleNode(data, getHead(), getHead()->getPrev());
            getHead()->getPrev()->setNext(newNode);
            getHead()->setPrev(newNode);

            setHead(newNode);
        } else {
            newNode = new DoubleNode(data, getHead()->getNext(), getHead());
            getHead()->getNext()->setPrev(newNode);
            getHead()->setNext(newNode);
        }
    } else {
        if (current->getNext() == getHead() &&
            *(data->getAppointmentDate()) > *(current->getData()->getAppointmentDate())) {
            newNode = new DoubleNode(data, getHead(), getHead()->getPrev());
            getHead()->getPrev()->setNext(newNode);
            getHead()->setPrev(newNode);
        } else {
            newNode = new DoubleNode(data, current, current->getPrev());
            current->getPrev()->setNext(newNode);
            current->setPrev(newNode);
        }
    }
}

void CircularDoublyLinkedList::remove(int number) {
    if (isEmpty()) {
        cout << "\nList is empty!\n";
        return;
    }

    DoubleNode *current = getHead();
    bool found = false;

    do {
        if (current->getData()->getNumber() == number) {
            found = true;
            break;
        }
        current = current->getNext();
    } while (current != getHead());

    if (!found) {
        cout << "\nCouldn't find personnel with given number!\n";
        return;
    }

    if (current == getHead() && current->getNext() == getHead()) {
        getHead()->setNext(NULL);
        getHead()->setPrev(NULL);

        delete getHead()->getData();
        delete getHead();

        setHead(NULL);

        cout << "\nPersonnel deleted successfully!\n";
        return;
    }

    if (current == getHead())
        setHead(current->getNext());

    current->getPrev()->setNext(current->getNext());
    current->getNext()->setPrev(current->getPrev());

    current->setNext(NULL);
    current->setPrev(NULL);
    delete current->getData();
    delete current;

    cout << "\nPersonnel deleted successfully!\n";
}

void CircularDoublyLinkedList::printList() const {
    if (isEmpty()) {
        cout << "\nList is empty!\n";
        return;
    }

    DoubleNode *current = getHead();
    int count = 0;

    do {
        cout << "\nPersonnel " << ++count << "\n***********\n";
        cout << *(current->getData());

        current = current->getNext();
    } while (current != getHead());
}

void CircularDoublyLinkedList::printAfterADate(Date *date) const {
    if (isEmpty()) {
        cout << "\nList is empty!\n";
        return;
    }

    DoubleNode *current = getHead()->getPrev();
    int count = 0;

    do {
        if (*(current->getData()->getAppointmentDate()) > *date) {
            cout << "\nPersonnel " << ++count << "\n***********\n";
            cout << *(current->getData());
        }

        current = current->getPrev();
    } while (current != getHead()->getPrev());

    if (count == 0)
        cout << "\nCouldn't find personnel information after entered appointment date!\n";
}

void CircularDoublyLinkedList::printSpecYearInfo(int year) const {
    if (isEmpty()) {
        cout << "\nList is empty!\n";
        return;
    }

    DoubleNode *current = getHead();
    int count = 0;

    do {
        if (current->getData()->getAppointmentDate()->getYear() == year) {
            cout << "\nPersonnel " << ++count << "\n***********\n";
            cout << *(current->getData());
        }

        current = current->getNext();
    } while (current != getHead());

    if (count == 0)
        cout << "\nCouldn't find personnel information in entered year!\n";
}

void CircularDoublyLinkedList::printLatestTitlePersonnel(const string &title) const {
    if (isEmpty()) {
        cout << "\nList is empty!\n";
        return;
    }

    DoubleNode *current = getHead();
    DoubleNode *foundNode = NULL;

    do {
        if (current->getData()->getTitle() == title &&
            (foundNode == NULL ||
             *(current->getData()->getAppointmentDate()) > *(foundNode->getData()->getAppointmentDate())))

            foundNode = current;

        current = current->getNext();
    } while (current != getHead());

    if (foundNode == NULL)
        cout << "\nCouldn't find the personnel with entered title!\n";

    else
        cout << *(foundNode->getData());
}

void CircularDoublyLinkedList::freeList() {
    if (isEmpty())
        return;

    DoubleNode *current = getHead();
    DoubleNode *nextNode;

    do {
        nextNode = current->getNext();

        current->setNext(NULL);
        current->setPrev(NULL);

        delete current->getData();
        delete current;

        current = nextNode;
    } while (current != getHead());

    setHead(NULL);
}
