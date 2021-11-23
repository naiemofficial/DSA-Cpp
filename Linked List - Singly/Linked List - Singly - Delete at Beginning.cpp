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


void deleteatBeg(){
    temp = start;
    start = start->pointer;
    delete temp;
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
    inset(20);
    inset(30);
    deleteatBeg();

    print();
}
