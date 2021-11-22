#include <iostream>
using namespace std;

// Create NODE
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

void inOrder(NODE *root){
    if(root==0){
        return;
    }else{
        inOrder(root->left);
        cout << root->data << " => ";
        inOrder(root->right);
    }
}

int main(){
    NODE *root;
    root = createNode("root");

    cout << "inOrder::: ";
    inOrder(root);
    return 0;
}
