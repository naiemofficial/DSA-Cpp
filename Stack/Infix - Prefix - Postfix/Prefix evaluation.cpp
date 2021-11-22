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

double prefixEvaluation(string prefix){
    stack<double> stack;
    for(int a=prefix.size()-1; a>=0; a-- ){
        if(isNumber(prefix[a])){
            stack.push(prefix[a]-'0'); // Must use minus ('-'), because incoming char will get ASCII. So char '0' will reduce 48 from the main value
        }else if(isOperator(prefix[a])){
            double A, B, sum;
            A = stack.top(); stack.pop();
            B = stack.top(); stack.pop();
            switch(prefix[a]){
                case '^':
                    sum = pow(A, B);
                    break;
                case '/':
                    sum = A/B;
                    break;
                case '*':
                    sum = A*B;
                    break;
                case '+':
                    sum = A+B;
                    break;
                case '-':
                    sum = A-B;
                break;
            }
            stack.push(sum);
        }
    }
    return stack.top();
}
int main(){
    string prefix = "-+2*34/8^23"; // 13
    cout << prefixEvaluation(prefix) << endl;
}
