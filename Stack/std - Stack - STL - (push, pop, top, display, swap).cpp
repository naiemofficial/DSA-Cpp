#include <iostream>
#include <stack>
using namespace std;
int main(){
    stack<int> myStack, yourStack;
    yourStack.push(1);
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    myStack.push(50);
    cout << "Stack size is: " << myStack.size() << endl; // Get the stack size or total elements
    cout << "Stack top is: " << myStack.top() << endl; // Get top most element form the stack

    swap(myStack, yourStack); // Swapped to yourStack
    yourStack.pop(); // POP - delete top most element [50] now the stack has 4 elements
    // 40 <== 30 <== 20 <== 10
    while(!yourStack.empty()){
        cout <<"["<< yourStack.top() <<"]  <==  ";
        yourStack.pop();
    }
    return 0;
}
