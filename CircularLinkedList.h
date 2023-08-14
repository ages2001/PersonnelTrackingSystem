#include "Personnel.h"

class Node {
private:
    Personnel *data;
    Node *next;

public:
    void setData(Personnel *data);

    void setNext(Node *next);

    Personnel *getData() const;

    Node *getNext() const;

    Node(); // null constructor

    Node(Personnel *data, Node *next); // constructor

    ~Node(); // destructor
};


class CircularLinkedList {
private:
    Node *head;

public:
    Node *getHead() const;

    void setHead(Node *head);

    CircularLinkedList();

    ~CircularLinkedList();

    bool isEmpty() const;

    bool isNumberExist(int number);

    void add(Personnel *data);

    void remove(int number);

    void findPersonnel(int number);

    friend ostream &operator<<(ostream &out, CircularLinkedList &list); // overriding toString() method

    void update(int number);

    void printBeforeBDate(Date *date) const;

    void printSpecifiedBMonth(int month) const;

    void freeList();
};
