#include <iostream>
using namespace std;

struct NODE{
    NODE *prev;
    int data;
    NODE *next;
};
NODE *head=0, *temp, *prevnode;
void add( int input ){

    if( head == 0 ){
        head = new NODE;
        head->prev = 0;
        head->data = input;
        head->next = 0;

        prevnode = temp = head;
    }else{
        temp->next = new NODE;
        temp = temp->next;
        temp->prev = prevnode;
        temp->data = input;
        temp->next = 0;
        prevnode = temp;
    }
}
void display(){
    temp = head;
    while( temp != 0 ){
        cout << temp->prev << " --> ";
        cout << temp->data << " --> ";
        cout << temp->next << " --> " << endl;
        temp = temp->next;
    }
}
int main(){
    add(10);
    add(20);
    add(30);
    add(40);
    display();
}
