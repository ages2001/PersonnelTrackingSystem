#include "Personnel.h"

class DoubleNode {
private:
    Personnel *data;
    DoubleNode *next;
    DoubleNode *prev;

public:
    void setData(Personnel *data);

    void setNext(DoubleNode *next);

    void setPrev(DoubleNode *prev);

    Personnel *getData() const;

    DoubleNode *getNext() const;

    DoubleNode *getPrev() const;

    DoubleNode(); // null constructor

    DoubleNode(Personnel *data, DoubleNode *next, DoubleNode *prev); // constructor

    ~DoubleNode(); // destructor
};


class CircularDoublyLinkedList {
private:
    DoubleNode *head;

public:
    DoubleNode *getHead() const;

    void setHead(DoubleNode *head);

    CircularDoublyLinkedList();

    ~CircularDoublyLinkedList();

    bool isEmpty() const;

    void add(Personnel *data);

    void remove(int number);

    void printList() const;

    void printAfterADate(Date *date) const;

    void printSpecYearInfo(int year) const;

    void printLatestTitlePersonnel(const string &title) const;

    void freeList();
};
