#include <ostream>
#include "Node.h"

template<typename T>
class Stack {
    Node<T> *pTop, *lst;
    int size = 0;
public:

    void init(T value);

    void copy(const Stack &source);

    Stack();

    Stack(T value);

    Stack(const Stack &source);

    Stack(Stack &&other);

    void push(const T &value);

    T pop();

    T peek();

    int getSize() const;

    ~Stack();

    void assignValue(const Stack &source);

    Stack &operator=(const Stack &source) const;

    Stack &operator=(Stack &&source) const;

    template<typename T1> friend std::ostream &operator<<(std::ostream &out, const Stack<T1> &source);
};

template<typename T>
Node<T> *pTop;
template<typename T>
Node<T> *lst;
int size;

template<typename T>
void Stack<T>::init(T value) {
    auto *root = new Node<T>;
    root->value = value;
    root->next = root;
    pTop = root;
    lst = root;
    lst->next = pTop;
    size++;
}

template<typename T>
void Stack<T>::copy(const Stack &source) {
    Node<T> *temp = source.pTop->next;
    do {
        push(temp->value);
        temp = temp->next;
    } while (size < source.getSize());
}

template<typename T>
Stack<T>::Stack() {
    pTop = nullptr;
    lst = nullptr;
}

template<typename T>
Stack<T>::Stack(T value) {
    init(value);
}

template<typename T>
Stack<T>::Stack(const Stack &source) {
    Stack temp;
    temp.init(source.pTop->value);
    temp.copy(source);
    init(temp.pTop->value);
    copy(temp);
}

template<typename T>
Stack<T>::Stack(Stack &&other) {
    pTop = other.pTop;
    lst = other.lst;
    size = other.size;
    other.pTop = nullptr;
    other.lst = nullptr;
    other.size = 0;
}

template<typename T>
void Stack<T>::push(const T &value) {
    Node<T> *newNode = new Node<T>;
    newNode->value = value;
    newNode->next = pTop;
    pTop = newNode;
    lst->next = pTop;
    size++;
}

template<typename T>
T Stack<T>::pop() {
    if (size <= 0) {
        delete this;
        pTop = lst = nullptr;
    } else {
        T value = pTop->value;
        Node<T> *temp;
        temp = pTop->next;
        delete pTop;
        pTop = temp;
        lst->next = pTop;
        size--;
        return value;
    }
}

template<typename T>
T Stack<T>::peek() {
    return pTop->value;
}

template<typename T>
int Stack<T>::getSize() const {
    return this->size;
}

template<typename T>
Stack<T>::~Stack() {
    int value = size;
    for (int i = 0; i < value - 1; i++) {
        pop();
    }
}

template<typename T>
void Stack<T>::assignValue(const Stack &source) {
    this->~Stack();
    pTop = nullptr;
    lst = nullptr;
    size = 0;
    Stack temp;
    temp.init(source.pTop->value);
    temp.copy(source);
    init(temp.pTop->value);
    copy(temp);
}

template<typename T>
Stack<T> &Stack<T>::operator=(const Stack &source) const {
    if (this == &source) {
        return *this;
    }
    assignValue(source);
    return *this;
}

template<typename T>
Stack<T> &Stack<T>::operator=(Stack &&source) const{
    if (this == &source) {
        return *this;
    }
    assignValue(source);
    source.size = 0;
    source.pTop = nullptr;
    source.lst = nullptr;
    return *this;
}

template<typename T>
std::ostream &operator<<(std::ostream &out, const Stack<T> &node) {
    if (node.size > 0) {
        Node<T> *temp;
        temp = node.pTop;
        do {
            out << temp->value << " ";
            temp = temp->next;
        } while (temp != node.pTop);
        return out;
    } else {
        out << "The list does not exist";
        return out;
    }
}