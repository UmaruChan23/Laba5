#include <iostream>
#include "Stack.h"
using namespace std;

int main() {

    Stack<int> stackList(1);

    stackList.push(2);
    stackList.push(3);
    stackList.push(4);

    Stack<int> listList = stackList;
    Stack<int> tList(3);
    tList = stackList;

    listList.push(5);
    tList.pop();

    cout << stackList << endl;
    cout << listList << endl;
    cout << tList << endl;

    return 0;
}
