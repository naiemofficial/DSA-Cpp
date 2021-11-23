#include <iostream>
using namespace std;

struct NODE{
    int value;
    NODE *pointer;
};
NODE *start, *last, *newnode;
void inset(int data){
    if( start == 0 ){
        start = new NODE;
        start->value = data;
        start->pointer = 0;
    }else{
        last = start;
        while( last->pointer != 0 ){
            last = last->pointer;
        }

        last->pointer = new NODE;
        last = last->pointer;
        last->value = data;
    }
}

void insertatBeg( int data ){ // Insert at Beginning
    newnode = new NODE;
    newnode->value = data;
    newnode->pointer = start;
    start = newnode;

}

void print(){
    last = start;
    while( last != 0 ){
        cout << last->value << " ---> ";
        last = last->pointer;
    }
}

void insertoSpecific(int position, int data){
    last = start;
    for( int i=1; i<position-1; i++ ){ // Position-1 is because *last is containing pointer of specific location (that means it indicate next node of specific position)
        last = last->pointer;
    }

    newnode = new NODE;
    newnode->pointer = last->pointer;
    newnode->value = data;
    last->pointer = newnode;
}

int main(){
    inset(10); //3
    inset(20);
    insertatBeg(8);
    insertatBeg(5);


    insertoSpecific(3, 30);

    print();
}
