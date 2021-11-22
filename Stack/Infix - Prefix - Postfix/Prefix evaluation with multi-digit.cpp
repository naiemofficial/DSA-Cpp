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

int prefixEvaluation(string prefix){
    stack<int> stack;

    string combinder;
    for(int a=prefix.size()-1; a>=0; a-- ){
        if(isspace(prefix[a]) && stack.top() != 0.0){

            // when incoming is space
            while(stack.top() != 0.0){
                combinder += to_string(stack.top());
                stack.pop();
            }
            if(stack.top() == 0.0){
                stack.pop();
            }
            // Combind

            // reverse(combinder.begin(), combinder.end()); Reverse is applicable for prefix only
            stack.push(stoi(combinder));
            stack.push(0.0);
            combinder="";


        }else if(isNumber(prefix[a])){
            if(stack.empty()){
                stack.push(0.0);
            }
            stack.push(prefix[a]-'0'); // Must use minus ('-'), because incoming char will get ASCII. So char '0' will reduce 48 from the main value
        }else if(isOperator(prefix[a])){
            if(stack.top() == 0.0){
                stack.pop();
            }

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
            stack.push(0.0);
        }
    }
    stack.pop();
    return stack.top();

    //return stack.top();
}
int main(){
    string prefix = "- + 2 * 3 4 / 16 ^ 2 3"; // 12
    cout << prefixEvaluation(prefix) << endl;
}
