#include <iostream>
using namespace std;

struct NODE{
    int data;
    NODE *left;
    NODE *right;
};
NODE *createNode(string dominate){
    // Case

    NODE *newnode;
    int data=NULL;
    if(dominate == "root"){
        cout << "Enter the data for the root: ";
        cin >> data;
    }else{
        cin >> data; // Go for -> Left child
    }

    if(data == -1){
        return NULL;
    }

    newnode = new NODE;
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    // " << dominate << "
    cout << "Enter the data for [" << data << "] left child: ";
    newnode->left = createNode("left"); // 0 ->

    cout << "Enter the data for [" << data << "] right child: ";
    newnode->right = createNode("right"); //

    return newnode;
}
int main(){
    NODE *root;
    root = createNode("root");
    return 0;
}
