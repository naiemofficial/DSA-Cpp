#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

// Check the value is operand or not
bool isOperand(char data){
    if(data >= 'a' && data <= 'z' || data >= 'A' && data <= 'Z'){
        return true;
    }else{
        return false;
    }
}

// Check the value is operator or not
bool isOperator(char data){
    if( data == '^' || data == '/' || data == '*' || data == '+' || data == '-' ){
        return true;
    }else{
        return false;
    }
}

// Check precedence
int precedence(char data){
    if(data == '^'){
        return 3;
    }else if(data == '/' || data == '*'){
        return 2;
    }else if(data == '+' || data == '-'){
        return 1;
    }else{
        return -1;
    }
}

// infix to postfix conversion
string infixToPostfix(string infix){
    string postfix;

    // Create stack STL
    stack<char> stack;

    // Start Scanning
    for(int a=0; a<infix.length(); a++ ){
        if(isOperand(infix[a])){
            postfix+=infix[a];
        }else if(infix[a] == '('){
            stack.push(infix[a]);
        }else if(infix[a] == ')'){
            while(stack.top() != '('){
                postfix+=stack.top();
                stack.pop();
            }
            if(stack.top() == '('){
                stack.pop();
            }
        }else if(isOperator(infix[a])){
            if(stack.empty()){
                stack.push(infix[a]);
            }else if(!stack.empty()){
                if(precedence(infix[a]) > precedence(stack.top())){
                    stack.push(infix[a]);
                }else if(precedence(infix[a]) < precedence(stack.top())){
                    while(precedence(infix[a]) < precedence(stack.top())){
                        postfix+=stack.top();
                        stack.pop();
                    }
                    stack.push(infix[a]);
                }else if(precedence(infix[a]) == precedence(stack.top())){
                    if(infix[a] == '^'){
                        stack.push(infix[a]);
                    }else{
                        while(precedence(infix[a]) == precedence(stack.top())){
                            postfix += stack.top();
                            stack.pop();
                        }
                        stack.push(infix[a]);
                    }
                }
            }
        }
    }
    while(!stack.empty()){
        postfix+=stack.top();
        stack.pop();
    }
    return postfix;
}


// Main function
int main(){
    string infix, postfix;
    infix = "((a+b-c)*d^e^f)/g";
    cout << "Infix: " << infix << endl;

    postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;
}
