#include <iostream>
#include "Node.cpp"

class Stack {
    Node *pTop, *lst;
    int size = 0;
public:

    Stack(int value){
        Node* root = new Node;
        root->value = value;
        root->next = root;
        pTop = root;
        lst = root;
        lst->next = pTop;
        size++;
    }

    Stack(const Stack &stack){
        Node* temp = stack.pTop;
        size = stack.getSize();
        pTop = temp;
        lst = temp;
        while(temp->next != pTop){
            temp = temp->next;
        }
    }

    void push(const Node &node){
        Node* newNode = new Node;
        newNode->value = node.value;
        newNode->next = pTop;
        pTop = newNode;
        lst->next = pTop;
        size++;
    }

    Node pop(){
        Node* temp;
        temp = pTop->next;
        delete(pTop);
        pTop = temp;
        lst->next = pTop;
        size--;
    }

    Node * peek(){
        return pTop;
    }

    ~Stack(){
        for(int i =0; i < size; i++){
            pop();
        }
    }

    friend std::ostream& operator<< (std::ostream &out, const Stack &node) {

        Node *temp;
        temp = node.pTop;
        do {
            out << temp->value << " "; // вывод значения узла p
            temp = temp->next; // переход к следующему узлу
        } while (temp != node.pTop); // условие окончания обхода
        return out;
    }

    friend std::istream& operator>> (std::istream &in, Node &node){
        in >> node.value;
        return in;
    }

    int getSize() const {
        return this->size;
    }
};