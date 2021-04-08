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
        size++;
    }

    Stack(const Stack &stack){
        Node* newNode = new Node;
        newNode->value = stack.pTop->value;
        newNode->next = stack.pTop->next;
        pTop = newNode;
        while(pTop!=stack.pTop)
        {
            push(*pTop);
            pTop = pTop->next;
        }
    }

    void push(const Node &node){

        size++;
    }

    Node pop(){
        pTop = pTop->next;
        lst->next = pTop;
        size--;
    }

    Node * peek(){
        return pTop;
    }

    ~Stack(){ std::cout << "deleted" << std::endl;}

    friend std::ostream& operator<< (std::ostream &out, const Stack &node) {

        out << node.size;

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