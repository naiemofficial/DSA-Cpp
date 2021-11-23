#include <iostream>
using namespace std;

void array_deletion(){
    int Size, Loop, Position, Value;

    cout << "Enter the size of array: ";
    cin >> Size;
    int Array[Size];
    for( int x=0; x<Size; x++ ){
        cout << "Enter a number for the position [" << x+1 << "]: ";
        cin >> Array[x];
    }

    cout << endl << "Array is => ";
    for( int i=0; i<Size; i++ ){
        cout << Array[i] << "   ";
    }
    cout << endl;

    cout << "How many values you want to delete form this ARRAY: ";
    cin >> Loop;

    for( int y=0; y<Loop; y++ ){
        cout << endl << "[Delete-"<<y+1<<"] Enter the Postion: " ;
        cin >> Position;
        if( Position < 1 || Position > Size ){
            cout << "Invalid position";
            break;
        }else{
            Position = Position-1;
            for( int z=Position; z<Size-(y+1); z++ ){
                Array[z] = Array[z+1];
            }

            cout << "Array is => ";
            for(int a=0; a<Size-(y+1); a++){
                cout << Array[a] << "   ";
            }
            cout << endl;
        }
    }








}

int main(){
    array_deletion();
}
