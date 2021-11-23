#include <iostream>
using namespace std;

struct NODE{
    int value;
    NODE *pointer;
};
NODE *start, *last;
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
    NODE *first;
    first = new NODE;
    first->value = data;
    first->pointer = start;
    start = first;

}
void print(){
    last = start;
    while( last != 0 ){
        cout << last->value << " ---> ";
        last = last->pointer;
    }
}

int main(){
    inset(10);
    inset(20);
    insertatBeg(8);
    insertatBeg(5);
    print();
}
