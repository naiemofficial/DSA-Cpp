#include <iostream>
using namespace std;

void array_insertion_user_input(){
    int Size, Loop, Position, Value;

    cout << "Enter the size of array: ";
    cin >> Size;
    int Array[Size];
    for( int x=0; x<Size; x++ ){
        cout << endl << "Enter a number for the position [" << x+1 << "]: ";
        cin >> Array[x];
    }

    cout << endl << "How many values you want to in the array: ";
    cin >> Loop;
    for( int y=0; y<Loop; y++ ){
        cout << endl << "[Loop-"<<y+1<<"] Enter the Postion: " ;
        cin >> Position;
        if( Position < 1 || Position > Size+y+1 ){
            cout << "Invalid position" << endl << endl;
            break;
        }else{
            cout << endl << "Enter the Value of Postion [" << Position <<"]: " ;
            cin >> Value;
            Position = Position-1; // Convert the position to index
            for( int z=(Size+Loop)-1; z>=Position; z--){
                Array[z] = Array[z-1];
            }
        }
        Array[Position] = Value;
    }


    // Print final array
    if( Position >= 0 ){ // Here zero allowed because previously it's converted to index Ref line: 26
        for( int i=0; i<Size+Loop; i++ ){
            cout << Array[i] << endl;
        }
    }
}

int main(){
    array_insertion_user_input();
}
