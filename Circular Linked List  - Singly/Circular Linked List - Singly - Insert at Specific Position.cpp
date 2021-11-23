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
void insertatSpecific(int input, int position){
    NODE *newnode;
    temp = head;
    for( int i=1; i<position-1; i++){
        temp = temp->next;
    }
    newnode = new NODE;
    newnode->data = input;
    newnode->next = temp->next;
    temp->next= newnode;
}
void display(){
    temp = head;
    do{
        cout << temp->data << "     ";
        temp = temp->next;
    }
    while( temp != head ); // first then while

}
int main()
{
    add(62);
    add(43);
    add(65);
    add(68);
    add(69);
    add(70);
    insertatSpecific(5, 2); // value, position
    insertatSpecific(10, 3);
    display();
    cout << endl << endl;
}
