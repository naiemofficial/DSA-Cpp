#include <iostream>
using namespace std;
struct NODE {
  int data;
  NODE *next;
};
NODE *head, *temp;
void add(int value){
    NODE *last;
    if(head == NULL){
        head = new NODE;
        head->data = value;
        head->next = head;
    }else{
        temp = head;
        while( temp->next != head ){
            temp = temp->next;
        }
        temp->next = 0; // set last pointer->next = 0. because pointer->next is already assigned head node ref: last=head
        temp->next = new NODE;
        temp = temp->next;
        temp->data = value;
        temp->next = head; // last=head
    }
}
void circularLLR(){
    NODE *prevnode=0, *nextnode;
    temp = head;
    do{
        nextnode = temp->next;
        temp->next = prevnode;
        prevnode = temp;
        temp = nextnode;
    }while( temp != head );
    head->next = prevnode;
    head = prevnode;
}
void display(){
    temp = head;
    do{
        cout << temp->data << "     ";
        temp = temp->next;
    }
    while( temp != head ); // first then while
}
int main(){
    add(62);
    add(43);
    add(65);
    add(68);
    add(69);
    add(70);
    circularLLR();
    display();
    cout << endl << endl;
}
