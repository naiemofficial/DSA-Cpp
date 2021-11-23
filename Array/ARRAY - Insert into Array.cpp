#include <iostream>
using namespace std;
// Array Insertion - coded by @Naiem
void array_insertion(int Array[], int Size, int Position, int Value){
    Position = Position-1; // Position converted to INDEX
    for( int i=Size-1; Position<=i; i-- ){
        Array[i+1] = Array[i];
    }
    Array[Position] = Value;
    for( int x=0; x<Size; x++ ){
        cout << Array[x] << endl;
    }
}


int main()
{
    int Array[100] = {5,   27,    8,    45,    35,    50,     12,    40,     1,    17};
    // Ref: array_insertion(ARRAY, SIZE, POSITION, VALUE);
    array_insertion(Array, 10, 5, 6);
    cout << endl << endl; return 0;
}
