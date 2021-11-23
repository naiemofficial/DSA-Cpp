#include <iostream>
using namespace std;
struct node {
  int data;
  node *next;
};


int main()
{
    node *head, *nexthelper;
    head = new node;
    head->data = 62;
    head->next = 0;

    nexthelper = head;

    if( nexthelper != 0 ){
        while( nexthelper->next != 0 ){
            nexthelper = nexthelper->next;
        }
    }

    nexthelper->next = new node;
    nexthelper = nexthelper->next;
    nexthelper->data = 43;

    nexthelper->next = new node;
    nexthelper = nexthelper->next;
    nexthelper->data = 65;



    nexthelper = head;
    while( nexthelper !=0 ){
        cout << nexthelper->data << "       ";
        nexthelper = nexthelper->next;
    }
    cout << endl << endl;
}
