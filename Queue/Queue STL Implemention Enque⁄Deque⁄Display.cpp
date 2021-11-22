#include <iostream>
using namespace std;
#include <queue>

queue<int>Queue;
void display(){
    if(Queue.empty()){
        cout << "Queue is empty!" << endl;
    }else{
        while(!Queue.empty()){
            cout << Queue.front() << " <= ";
            Queue.pop();
        }
    }
}
int main(){
    Queue.push(10);
    Queue.push(20);
    Queue.push(30);
    display();
    return 0;
}
