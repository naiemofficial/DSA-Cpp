#include <iostream>
using namespace std;
struct node {
  int data;
  node *next;
};


int main()
{
    node *head, *temp;

    head = new node;
    head->data = 62;
    head->next = 0;

    // Add more nodes in linked list
    temp = head; // Initialize *temp as *head for traverse in the list

    temp->next = new node;
    temp = temp->next;
    temp->data = 43;
    temp->next = 0;

    temp->next = new node;
    temp = temp->next;
    temp->data = 65;
    temp->next = 0;


    temp = head;
    while( temp !=0 ){
        cout << temp->data << "       ";
        temp = temp->next;
    }
    cout << endl << endl;
}
