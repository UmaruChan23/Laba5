#include <iostream>
#include "Node.cpp"

class StackList{
    Node *head, *tail;
    int size = 0;
public:
    StackList(): size(0){
        head = new Node;
        tail = head;
    }

    StackList(int value){
        Node* root = new Node;
        root->value = value;
        root->next = root;
        head = root;
        tail = root;
        size++;
        delete(root);
    }

    void push(const Node &node){
        Node* temp = head;
        head = (Node *) &node;
        //node.next = tail;
    }


    ~StackList(){ std::cout << "deleted";}

    friend std::ostream& operator<< (std::ostream &out, const StackList &node) {

            out << node.size << " " << node.head << " " << node.tail;

        return out;
    }

    friend std::istream& operator>> (std::istream &in, StackList &node){
        in >> node.size;
        return in;
    }
};