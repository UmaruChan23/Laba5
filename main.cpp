#include <iostream>
#include "Stack.cpp"

using namespace std;

int main() {

    Stack stackList(1);

    Node node{};
    node.value = 2;
    Node node1{};
    node1.value = 3;
    Node node2{};
    node2.value = 4;

    stackList.push(node);
    stackList.push(node1);
    stackList.push(node2);


    Stack listList = stackList;
    Stack tList(3);
    tList = stackList;


    cout << stackList << endl;
    cout << listList << endl;
    cout << tList << endl;

    return 0;
}
