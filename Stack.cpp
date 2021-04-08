#include <iostream>
#include "Node.h"

class Stack {

    Node *pTop, *lst;
    int size = 0;
public:

    void init(int value) {
        Node *root = new Node;
        root->value = value;
        root->next = root;
        pTop = root;
        lst = root;
        lst->next = pTop;
        size++;
    }

    void copy(const Stack &source) {
        Node *temp = source.pTop->next;
        do {
            push(*temp);
            temp = temp->next;
        } while (size < source.getSize());
    }

    Stack() {
        pTop = nullptr;
        lst = nullptr;
    }

    Stack(int value) {
        init(value);
    }

    Stack(const Stack &source) {
        Stack temp;
        temp.init(source.pTop->value);
        temp.copy(source);
        init(temp.pTop->value);
        copy(temp);
    }

    Stack(Stack &&other) {
        pTop = other.pTop;
        lst = other.lst;
        size = other.size;
        other.pTop = nullptr;
        other.lst = nullptr;
        other.size = 0;
    }

    void push(const Node &node) {
        Node *newNode = new Node;
        newNode->value = node.value;
        newNode->next = pTop;
        pTop = newNode;
        lst->next = pTop;
        size++;
    }

    int pop() {
        if (size <= 0) {
            delete this;
            pTop = lst = nullptr;
        } else {
            int value = pTop->value;
            Node *temp;
            temp = pTop->next;
            delete pTop;
            pTop = temp;
            lst->next = pTop;
            size--;
            return value;
        }
    }

    int peek() {
        return pTop->value;
    }

    int getSize() const {
        return this->size;
    }

    ~Stack() {
        for (int i = 0; i < size; i++) {
            pop();
        }
    }

    void assignValue(const Stack &source) {
        pTop = nullptr;
        lst = nullptr;
        size = 0;
        Stack temp;
        temp.init(source.pTop->value);
        temp.copy(source);
        init(temp.pTop->value);
        copy(temp);
    }


    Stack &operator=(const Stack &source) {
        if (this == &source) {
            return *this;
        }
        assignValue(source);
        return *this;
    }

    Stack &operator=(Stack &&source) {
        if (this == &source) {
            return *this;
        }
        assignValue(source);
        source.pTop = nullptr;
        source.lst = nullptr;
        source.size = 0;
        return *this;
    }


    friend std::ostream &operator<<(std::ostream &out, const Stack &node) {
        if (node.size > 0) {
            Node *temp;
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

};