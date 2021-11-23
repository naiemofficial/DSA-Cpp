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
void deleteOfSpcDCLL( int position ){
    NODE *prevnode, *newnode, *nextnode;
    temp=head;

    for( int i=1; i<position; i++){ // 3
        prevnode = temp;
        temp = temp->next;
        nextnode = temp->next;
    }
    delete temp;
    prevnode->next = nextnode;
    nextnode->prev = prevnode;
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
    add(30);
    add(40);
    add(50);
    add(60);
    display("data");
    deleteOfSpcDCLL(3);
    display("data");
}
