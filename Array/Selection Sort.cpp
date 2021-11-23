#include <iostream>
using namespace std;

void selection_sort( int Array[], int Size ){
    for( int x=0; x<Size; x++ ){
        int set_min = x;
        for( int y=x+1; y<Size; y++ ){
            if( Array[y] < Array[set_min] ){
                set_min = y;
            }
        }
        if( set_min != x ){
            int Temp = Array[x];
            Array[x] = Array[set_min];
            Array[set_min] = Temp;
        }
    }
    for(int z=0; z<Size; z++){
        cout << Array[z] << "   ";
    }
}


int main()
{
    int Array[] = {5,   27,    8,    45,    35,    50,     12,    40,     1,    17};
    selection_sort(Array, 10);
    cout << endl << endl; return 0;
}

