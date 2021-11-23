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
        head->next = head;

        prevnode = temp = head;
    }else{
        temp->next = 0;
        temp->next = new NODE;
        temp = temp->next;
        temp->prev = prevnode;
        temp->data = input;

        temp->next = head;
        head->prev = temp;

        prevnode = temp;
    }
}

// Insert
void insertEndDCLL( int value ){
    NODE *newnode, *lastnode;
    lastnode = temp = head;
    while( lastnode->next != head ){
        lastnode = lastnode->next;
    }
    lastnode->next = new NODE;
    newnode = lastnode->next;
    newnode->prev = lastnode;
    newnode->data = value;
    newnode->next = head;
    head->prev = newnode;
}

void display(string param){
    temp = head;
    do{
        if(param == "prev"){
            cout << temp->prev << " --> ";
        }else if( param == "data" ){
            cout << temp->data << " --> ";
        }else if( param == "next" ){
            cout << temp->next << " --> ";
        }
        temp = temp->next;
    }while( temp != head );

    cout << endl;
}
int main(){
    add(10);
    add(20);
    display("data");
    insertEndDCLL(30);
    display("data");
}
