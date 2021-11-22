#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

// Reverse Parenthesis
string reverseParenthesis(string data){
    for(int a=0; a<data.length(); a++){
        if(data[a] == ')'){
            data[a] = '(';
        }else if(data[a] == '('){
            data[a] = ')';
        }
    }
    return data;
}

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

// infix to prefix conversion
string infixToPrefix(string infix){
    string prefix;

    // Reverse infix for scanning
    reverse(infix.begin(), infix.end());

    // Reverse Paranthesis )(
    infix = reverseParenthesis(infix);

    // Create stack STL
    stack<char> stack;

    // Start Scanning
    for(int a=0; a<infix.length(); a++){
        if(isOperand(infix[a])){
            prefix+=infix[a];       // ------------ push operand
        }else if(infix[a] == '('){ // if start bracket
            stack.push(infix[a]);
        }else if(infix[a] == ')'){
            while(stack.top() != '('){ // if closing bracket
                prefix+=stack.top(); // ------------- push bracket
                stack.pop();
            }
            if( stack.top() == '('){
                stack.pop();
            }
        }else if(isOperator(infix[a])){ // if the value is operator
            if(stack.empty()){              // if the stack is empty
                stack.push(infix[a]);       // ---------- push operator
            }else if(!stack.empty()){       // if the stack isn't empty
                if(precedence(infix[a]) > precedence(stack.top()) ){ //  if incoming is greater than stack
                    stack.push(infix[a]);
                }else if(precedence(infix[a]) < precedence(stack.top()) ){ // if incoming is less than stack
                    while(precedence(infix[a]) < precedence(stack.top())){
                        prefix+=stack.top();
                        stack.pop();
                    }
                    stack.push(infix[a]);
                }else if( infix[a] == stack.top() ){
                    if(infix[a] == '^'){
                        while(infix[a] == stack.top()){
                            prefix+=stack.top();
                            stack.pop();
                        }
                        stack.push(infix[a]);
                    }else{
                        stack.push(infix[a]);
                    }
                }
            }
        }
    }
    while(!stack.empty()){
        prefix += stack.top();
        stack.pop();
    }
    reverse(prefix.begin(), prefix.end());
    return prefix;
}


// Main function
int main(){
    string infix, prefix;
    infix = "((a+b-c)*d^e^f)/g";
    cout << "Infix: " << infix << endl;

    prefix = infixToPrefix(infix);
    cout << "Prefix: " << prefix << endl;
}
