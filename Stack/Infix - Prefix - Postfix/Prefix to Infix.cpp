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
string prefixToInfix(string prefix){
    // Create stack STL
    stack<string> stack;
    // Start Scanning
    string op, A, B;
    string sum;
    for(int a=prefix.size()-1; a>=0 ; a--){
        if(isOperator(prefix[a])){
            // Pop out last two element from the stack
            A = stack.top(); stack.pop();
            B = stack.top(); stack.pop();
            sum = A+prefix[a]+B;
            stack.push(sum);
        }else{
            stack.push(string(1, prefix[a]));
        }
    }
    return stack.top();
}


// Main function
int main(){
    string infix, prefix;
    //prefix = "/*-+abc^^defg";
    prefix = "*+ab/ef";
    cout << "Prefix: " << prefix << endl;

    infix = prefixToInfix(prefix);
    cout << "Infix: " << infix << endl;
    return 0;
}
