#include <iostream>
using namespace std;
struct node {
  int data;
  node *next;
};
node *head, *temp;
void add(int value){
    if(head == NULL){
        head = new node;
        head->data = value;
        head->next = 0;
    }else{
        temp = head;
        while( temp->next != 0 ){
            temp = temp->next;
        }
        temp->next = new node;
        temp = temp->next;
        temp->data = value;
        temp->next = NULL;
    }
}
void display(){
    temp = head;
    while( temp !=0 ){
        cout << temp->data << "       ";
        temp = temp->next;
    }
}


int main()
{

    add(62);
    add(43);
    add(65);
    display();



    cout << endl << endl;
}
