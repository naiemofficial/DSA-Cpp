#include <iostream>
using namespace std;

struct NODE{
    int value;
    NODE *pointer;
};
NODE *start, *last, *temp;
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


void deleteatLast(){
    NODE *previous;
    last = start;
    while( last->pointer != 0 ){
        previous = last;
        last = last->pointer;
    }
        previous->pointer=0;
        delete last;


}


void print(){
    last = start;
    while( last != 0 ){
        cout << last->value << " ---> ";
        last = last->pointer;
    }

    cout << endl;
}





int main(){
    inset(10);
    deleteatLast();

    print();
}
