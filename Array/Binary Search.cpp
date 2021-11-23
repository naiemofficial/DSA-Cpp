
#include <iostream>
using namespace std;


string binarySearch(int Array[], int n, int Search){           // SEARCH = 8
    int Start=0, Center, End=n-1;       // NUMBERS => 5    8    15    20    25  |  30    35    40    45
                                        //            ^    ^     ^     ^     ^  |   ^     ^     ^     ^
    while(Start <= End){                // INDEX   => 0    1     2     3     4  |   5     6     7     8
        Center = (Start + End)/2;
        if( Search == Array[Center] ){
            return "Matched";
        }else{
            if( Search < Array[Center] ){
                End = Center - 1;
            }else{
                Start = Center + 1;
            }
        }
    }
    return "Not Matched";
}


int main()
{
    int myArray[] = {5,    8,    15,    20,    25,   30,    35,    40,    45, 100};
    int input, Items = 10;
    while(1){
        cout << "Enter the number: " ;
        cin >> input;
        cout << binarySearch(myArray, Items, input) << endl<<endl;
    }

    cout << endl << endl; return 0;
}
