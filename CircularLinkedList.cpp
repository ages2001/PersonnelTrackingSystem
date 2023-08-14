#include "Personnel.h"
#include "CircularLinkedList.h"

Personnel *Node::getData() const {
    return this->data;
}

Node *Node::getNext() const {
    return this->next;
}

void Node::setData(Personnel *data) {
    Node::data = data;
}

void Node::setNext(Node *next) {
    Node::next = next;
}

Node::Node() {
    Personnel *personnel = new Personnel();
    setData(personnel);
    setNext(NULL);
}

Node::Node(Personnel *data, Node *next) {
    setData(data);
    setNext(next);
}

Node::~Node() {

}


Node *CircularLinkedList::getHead() const {
    return this->head;
}

void CircularLinkedList::setHead(Node *head) {
    CircularLinkedList::head = head;
}

CircularLinkedList::CircularLinkedList() {
    setHead(NULL);
}

CircularLinkedList::~CircularLinkedList() {

}

bool CircularLinkedList::isEmpty() const {
    return getHead() == NULL;
}

bool CircularLinkedList::isNumberExist(int number) {
    if (isEmpty())
        return false;

    Node *current = head;

    do {
        if (current->getData()->getNumber() == number)
            return true;

        current = current->getNext();
    } while (current != head);

    return false;
}

void CircularLinkedList::add(Personnel *data) {
    if (isEmpty()) {
        Node *newNode = new Node(data, NULL);
        newNode->setNext(newNode);
        setHead(newNode);

        return;
    }

    Node *current = head, *newNode;

    do {
        if (data->getNumber() < current->getData()->getNumber())
            break;

        current = current->getNext();
    } while (current->getNext() != head);

    if (current == head) {
        if (data->getNumber() < head->getData()->getNumber()) {
            newNode = new Node(data, head);
            Node *prevNode = head;

            while (prevNode->getNext() != head)
                prevNode = prevNode->getNext();

            prevNode->setNext(newNode);
            setHead(newNode);
        } else {
            newNode = new Node(data, head->getNext());
            head->setNext(newNode);
        }
    } else {
        if (current->getNext() == head && data->getNumber() > current->getData()->getNumber()) {
            newNode = new Node(data, head);
            current->setNext(newNode);
        } else {
            newNode = new Node(data, current);
            Node *prevNode = head;

            while (prevNode->getNext() != current)
                prevNode = prevNode->getNext();

            prevNode->setNext(newNode);
        }
    }
}

void CircularLinkedList::remove(int number) {
    if (isEmpty()) {
        cout << "\nList is empty!\n";
        return;
    }

    Node *current = head;
    bool found = false;

    do {
        if (current->getData()->getNumber() == number) {
            found = true;
            break;
        }
        current = current->getNext();
    } while (current != head);

    if (!found)
        return;

    if (current == head && current->getNext() == head) {
        head->setNext(NULL);
        delete head;

        setHead(NULL);
        return;
    }

    Node *prevNode = head;

    while (prevNode->getNext() != current)
        prevNode = prevNode->getNext();

    if (current == head)
        setHead(current->getNext());

    prevNode->setNext(current->getNext());

    current->setNext(NULL);
    delete current;
}

void CircularLinkedList::findPersonnel(int number) {
    if (isEmpty()) {
        cout << "\nList is empty!\n";
        return;
    }

    Node *current = head;
    bool found = false;

    do {
        if (current->getData()->getNumber() == number) {
            found = true;
            break;
        }

        current = current->getNext();
    } while (current != head);

    if (!found) {
        cout << "\nCouldn't find personnel with given number!\n";
        return;
    }

    Personnel *personnel = current->getData();
    cout << *personnel;
}

ostream &operator<<(ostream &out, CircularLinkedList &list) {
    int count = 0;
    Node *current = list.getHead();

    if (list.isEmpty())
        out << "\nList is empty!\n";

    else {
        do {
            Personnel *personnel = current->getData();

            out << "\nPersonnel " << ++count << "\n***********\n";
            out << *personnel;

            current = current->getNext();
        } while (current != list.getHead());
    }

    return out;
}

void CircularLinkedList::update(int number) {
    if (isEmpty()) {
        cout << "\nList is empty!\n";
        return;
    }

    Node *current = head;
    bool found = false;

    do {
        if (current->getData()->getNumber() == number) {
            found = true;
            break;
        }

        current = current->getNext();
    } while (current != head);

    if (!found) {
        cout << "\nCouldn't find personnel with given number!\n";
        return;
    }

    string newTitle;
    double newCoefficient;

    cin.ignore();
    cout << "\nEnter the new personnel title: ";
    getline(cin, newTitle);
    cout << "Enter the new salary coefficient: ";
    cin >> newCoefficient;

    current->getData()->setTitle(newTitle);
    current->getData()->setSalaryCoefficient(newCoefficient);

    cout << "\nUpdated successfully!\n";
}

void CircularLinkedList::printBeforeBDate(Date *date) const {
    if (isEmpty()) {
        cout << "\nList is empty!\n";
        return;
    }

    Node *current = getHead();
    int count = 0;

    do {
        if (*(current->getData()->getBirthDate()) < *date) {
            cout << "\nPersonnel " << ++count << "\n***********\n";
            cout << *(current->getData());
        }

        current = current->getNext();
    } while (current != getHead());

    if (count == 0)
        cout << "\nCouldn't find personnel information before entered birthdate!\n";
}

void CircularLinkedList::printSpecifiedBMonth(int month) const {
    if (isEmpty()) {
        cout << "\nList is empty!\n";
        return;
    }

    Node *current = getHead();
    int count = 0;

    do {
        if (current->getData()->getBirthDate()->getMonth() == month) {
            cout << "\nPersonnel " << ++count << "\n***********\n";
            cout << *(current->getData());
        }

        current = current->getNext();
    } while (current != getHead());

    if (count == 0)
        cout << "\nCouldn't find personnel information with specified birth month!\n";
}

void CircularLinkedList::freeList() {
    if (isEmpty())
        return;

    Node *current = getHead();
    Node *nextNode;

    do {
        nextNode = current->getNext();

        current->setNext(NULL);
        delete current;

        current = nextNode;
    } while (current != getHead());

    setHead(NULL);
}
