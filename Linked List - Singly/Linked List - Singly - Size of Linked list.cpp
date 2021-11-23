#include <iostream>
using namespace std;


struct NODE{
    int data;
    NODE *pointer;
};
NODE *root, *temp;
void add(int value){
    if( root == 0){
        root = new NODE;
        root->data = value;
        root->pointer = NULL;
    }else{
        temp = root;
        while( temp->pointer != 0){
            temp = temp->pointer;
        }
        temp->pointer = new NODE;
        temp = temp->pointer;
        temp->data = value;
        temp->pointer = NULL;
    }
}


void display(string param){
    temp = root;
    if( param == "list" ){
        while( temp != 0 ){
            cout << temp->data << " ---> ";
            temp = temp->pointer;
        }
        cout << endl;
    }else if( param == "size" ){
        int listsize = 0;
        while( temp != 0 ){
            listsize++;
            temp = temp->pointer;
        }
        cout << "List size is: " << listsize << endl;
    }
}


int main(){
    add(10);
    add(20);
    add(30);
    add(40);
    add(50);
    display("list");
    display("size");
    return 0;
}
