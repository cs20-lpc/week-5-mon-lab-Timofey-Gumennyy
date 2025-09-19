#include "DoublyList.hpp"

template <typename T>
DoublyList<T>::DoublyList()
: header(new Node), trailer(new Node) {
    header->next  = trailer;
    trailer->prev = header;
    this->length = 0;
}

template <typename T>
DoublyList<T>::DoublyList(const DoublyList<T>& copyObj)
: header(new Node), trailer(new Node) {
    copy(copyObj);
}

template <typename T>
DoublyList<T>& DoublyList<T>::operator=(const DoublyList<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
DoublyList<T>::~DoublyList() {
    clear();
    delete header;
    delete trailer;
    header = trailer = nullptr;
}

template <typename T>
void DoublyList<T>::append(const T& elem) {
    // insert new node before trailer sentinel
    Node* n = new Node(elem, trailer, trailer->prev);
    trailer->prev->next = n;
    trailer->prev = n;
    this->length++;
}

template <typename T>
void DoublyList<T>::clear() {
    for (Node* curr = nullptr; header->next != trailer; ) {
        curr = header->next->next;
        delete header->next;
        header->next = curr;
    }

    trailer->prev = header;
    this->length  = 0;
}

template <typename T>
void DoublyList<T>::copy(const DoublyList<T>& copyObj) {
    this->length   = copyObj.length;
    Node* myCurr   = header;
    Node* copyCurr = copyObj.header->next;

    while (copyCurr != copyObj.trailer) {
        Node* n      = new Node(copyCurr->value);
        myCurr->next = n;
        n->prev      = myCurr;
        myCurr       = n;
        copyCurr     = copyCurr->next;
    }

    myCurr->next  = trailer;
    trailer->prev = myCurr;
}

template <typename T>
T DoublyList<T>::getElement(int position) const {
    // TO DO: Implent code for getElement at position
    return GetNode(position)->value;
}

template <typename T>
int DoublyList<T>::getLength() const {
    return this->length;
}


template <typename T>
void DoublyList<T>::insert(int position, const T& elem) {
  // TO DO: Implement code to insert an element to list
    Node* temp = GetNode(position);
    Node* newNode = new Node(elem, temp, temp->prev);
    temp->prev->next = newNode;
    temp->prev = newNode;
    this->length++;
}

template <typename T>
bool DoublyList<T>::isEmpty() const {
    return this->length  == 0
        && header->next  == trailer
        && trailer->prev == header;
}

template <typename T>
void DoublyList<T>::remove(int position) {
    // TO DO: Implement code to remove element at given position
    Node* temp = GetNode(position);
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    this->length--;
    delete temp;
}

template <typename T>
bool DoublyList<T>::search(const T& elem) const {
    Node* curr = header->next;
    while (curr != trailer) {
        if (curr->value == elem) return true;
        curr = curr->next;
    }
    return false;
}



template <typename T>
void DoublyList<T>::replace(int position, const T& elem) {
    // TO DO: Add code for replace method
    Node* temp = GetNode(position);
    temp->value = elem;
}

template <typename T>
ostream& operator<<(ostream& outStream, const DoublyList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }
    else {
        typename DoublyList<T>::Node* curr = myObj.header->next;
        while (curr != myObj.trailer) {
            outStream << curr->value;
            if (curr->next != myObj.trailer) {
                outStream << " <--> ";
            }
            curr = curr->next;
        }
        outStream << endl;
    }

    return outStream;
}

template <typename T>
typename DoublyList<T>::Node* DoublyList<T>::GetNode(int position) const {
    if (position >= this->length || position < 0)
        throw string("Position out of bounds");

    if (isEmpty())
        throw string("List is empty");

    Node* temp = header->next; // start at first real node
    for (int i = 0; i < position; i++)
        temp = temp->next;

    return temp;
}
