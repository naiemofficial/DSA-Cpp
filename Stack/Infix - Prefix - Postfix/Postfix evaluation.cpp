#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

// Check the value is operator or not
bool isOperator(char data){
    if( data == '^' || data == '/' || data == '*' || data == '+' || data == '-' ){
        return true;
    }else{
        return false;
    }
}
bool isNumber(int data){
    return isdigit(data);
}

double postfixEvaluation(string postfix){
    stack<double> stack;
    for(int a=0; a<postfix.size(); a++ ){
        if(isNumber(postfix[a])){
            stack.push(postfix[a]-'0'); // Must use minus ('-'), because incoming char will get ASCII. So char '0' will reduce 48 from the main value
        }else if(isOperator(postfix[a])){
            double A, B, sum;
            A = stack.top(); stack.pop();
            B = stack.top(); stack.pop();
            switch(postfix[a]){
                case '^':
                    sum = pow(B, A);
                    break;
                case '/':
                    sum = B/A;
                    break;
                case '*':
                    sum = B*A;
                    break;
                case '+':
                    sum = B+A;
                    break;
                case '-':
                    sum = B-A;
                break;
            }
            stack.push(sum);
        }
    }
    return stack.top();
}
int main(){
    string postfix = "234*+823^/-"; // 13
    cout << postfixEvaluation(postfix) << endl;
}
