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
void inserttoSpecific(int position, int value){
    NODE *newnode;
    temp = head;
    for( int i=1; i<position; i++ ){
        newnode = prevnode = temp;
        temp = temp->next;
    }
    newnode->next = new NODE;
    newnode = newnode->next;
    newnode->prev = prevnode;
    newnode->data = value;
    newnode->next = temp;

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
    add(10);
    add(20);
    add(30);
    inserttoSpecific(3, 25);
    display("prev");
    cout << "-----------------------------------------------------------------" << endl;
    display("data");
    cout << "-----------------------------------------------------------------" << endl;
    display("next");
}
