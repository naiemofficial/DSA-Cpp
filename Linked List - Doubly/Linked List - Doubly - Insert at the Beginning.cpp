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
void insertatBeg(int value){
    temp = 0;
    if( head->prev == 0 ){
        temp = new NODE;
        temp->prev = 0;
        temp->data = value;
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void display(string param){
    temp = head;
    while( temp != 0 ){
        if(param == "prev"){
            cout << temp->prev << " --> ";
        }else if( param == "data" ){
            cout << temp->data << " --> ";
        }else if( param == "next" ){
            cout << temp->next << " --> ";
        }
        temp = temp->next;
    }
    cout << endl;
}
int main(){
    add(20);
    add(30);
    add(40);
    insertatBeg(5);
    display("prev");
    cout << "-----------------------------------------------------------------" << endl;
    display("data");
    cout << "-----------------------------------------------------------------" << endl;
    display("next");
}
