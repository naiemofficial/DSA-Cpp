#include <iostream>
using namespace std;

// Array Traversal - coded by @Naiem
void array_traversal(int Array[], int Size){
    for( int i=0; i<Size; i++ ){
        cout << "(" <<i+1 <<") Index [" << i << "] => ";
        cout << Array[i] << endl;
    }
}


int main()
{
    int Array[] = {5,   27,    8,    45,    35,    50,     12,    40,     1,    17};
    array_traversal(Array, 10);
    cout << endl << endl; return 0;
}
