#include <iostream>
using namespace std;

struct NODE{
    int value;
    NODE *pointer;
};
NODE *start, *last, *temp;
void add(int data){
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

void deleteofSpecific(int position){
    last = start;
    for( int i=1; i<position; i++ ){
        temp = last;
        last = last->pointer;
    }
    temp->pointer = last->pointer;
    cout << "Before delete: " << last->value << endl;
    delete last;
    cout << "After delete: "  << last->value << endl;
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
    add(10);
    add(20);
    add(30);
    add(40);
    deleteofSpecific(3);

    print();
}
