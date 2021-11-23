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
NODE *reverseDCLLR(NODE *node){

    if( node == NULL ){
        return NULL;
    }
    if( node->next == head ){
        NODE *prevnode = node->prev; // 100
        head = node;
        return node; // 400
    }
    NODE *rverse = reverseDCLLR(node->next); // 400
    rverse->next = node; // 300
    rverse->prev = prevnode;
    node->next = head;
    prevnode = node;
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
    reverseDCLLR(head);
    display("data");
}
