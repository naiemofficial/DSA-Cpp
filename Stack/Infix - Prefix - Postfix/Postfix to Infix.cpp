#include <iostream>
#include <stack>
using namespace std;

// Check the value is operator or not
bool isOperator(char data){
    if( data == '^' || data == '/' || data == '*' || data == '+' || data == '-' ){
        return true;
    }else{
        return false;
    }
}

// infix to postfix conversion
string postfixToInfix(string postfix){
    // Create stack STL
    stack<string> stack;
    // Start Scanning
    string op, A, B;
    string sum;
    for(int a=0; a<postfix.size(); a++){
        if(isOperator(postfix[a])){
            // Pop out last two element from the stack
            A = stack.top(); stack.pop();
            B = stack.top(); stack.pop();
            sum = B+postfix[a]+A;
            stack.push(sum);
        }else{
            stack.push(string(1, postfix[a]));
        }
    }
    return stack.top();
}


// Main function
int main(){
    string infix, postfix;
    //prefix = "/*-+abc^^defg";
    postfix = "ab+ef/*";
    cout << "Postfix: " << postfix << endl;

    infix = postfixToInfix(postfix);
    cout << "Infix: " << infix << endl;
    return 0;
}

