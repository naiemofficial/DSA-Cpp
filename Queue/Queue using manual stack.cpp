#include <iostream>
using namespace std;

#define Size 5
int Stack_1[Size], Stack_2[Size], Top=-1, tempTop=-1;

void enqueue(int data){
    if(Top >= Size-1){
        cout << "Queue(stack) is full!" << endl;
    }else{
        Top++;
        Stack_1[Top] = data;
    }
}
void dequeue(){
    if(Top < 0){
        cout << "Queue(stack) is emtpy! - Ref: Deque" << endl;
    }else{
        while(Top>=0){
            tempTop++;
            Stack_2[tempTop] = Stack_1[Top];
            Top--;
        }
        tempTop--;
        while(tempTop >= 0){
            Top++;
            Stack_1[Top] = Stack_2[tempTop];
            tempTop--;
        }
    }
}
void display(){
    if(Top < 0){
        cout << "Queue(stack) is emtpy! - Ref: Display" << endl;
    }else{
        while(Top >= 0){
            cout << " => " << Stack_1[Top];
            Top--;
        }
    }
}
int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();
    return 0;
}
