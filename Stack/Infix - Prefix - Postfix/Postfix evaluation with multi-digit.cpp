#include <iostream>
#include <stack>
#include <cmath>
#include <algorithm>
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

int postfixEvaluation(string postfix){
    stack<int> stack;

    string combinder;
    for(int a=0; a<postfix.size(); a++ ){
        if(isspace(postfix[a]) && stack.top() != 0.0){

            // when incoming is space
            while(stack.top() != 0.0){
                combinder += to_string(stack.top());
                stack.pop();
            }
            if(stack.top() == 0.0){
                stack.pop();
            }
            // Combind
            reverse(combinder.begin(), combinder.end());

            stack.push(stoi(combinder));
            stack.push(0.0);
            combinder="";


        }else if(isNumber(postfix[a])){
            if(stack.empty()){
                stack.push(0.0);
            }
            stack.push(postfix[a]-'0'); // Must use minus ('-'), because incoming char will get ASCII. So char '0' will reduce 48 from the main value
        }else if(isOperator(postfix[a])){
            if(stack.top() == 0.0){
                stack.pop();
            }

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
            stack.push(0.0);
        }
    }
    stack.pop();
    return stack.top();

    //return stack.top();
}
int main(){
    string postfix = "2 3 4 * + 16 2 3 ^ / -"; // 12
    cout << postfixEvaluation(postfix) << endl;
}
