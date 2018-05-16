/*
Bubble sorting is a simple sorting technique used in sorting algorithms.
In bubble sorting algorithm, we arrange the elements of the list by
forming pairs of adjacent elements. It means we repeatedly step through
the list we want to sort, compare two items at a time and swap them if
they are not in the right order.
Another way to visualize the bubble sort algorithm is as its name, the
smaller element 'bubble' to the top.
The following source code implements the bubble sorting algorithm in
C++, sorting an unordered list of integers.
*/

#include <iostream>
using namespace std;

class BubbleSort1 {

private:
    int a[10];
    int size;

public:
    BubbleSort1();
    void print();
    void sort();

}; // End of class definition

BubbleSort1::BubbleSort1() {
  a[0] = 10;
  a[1] = 2;
  a[2] = 5;
  a[3] = 1;
  a[4] = 4;
  a[5] = 10;
  a[6] = 8;
  a[7] = 7;
  a[8] = 3;
  a[9] = 9;
  size = 9;
}


int main(void) {
  BubbleSort1 bs;

  cout << "Before sorting:\n";
  bs.print();
    cout << "\n";

    cout << "Start sorting:\n";     //Added
    bs.sort();

    cout << "After sorting:\n";
  bs.print();
    cout << "\n";

    return 0;
}

//Det her er kernen i algoritmen
void BubbleSort1::sort() {
    int switched = 1;
    int hold = 0;
    int i = 0;
    int j = 0;

    /*for (i = 0; i < (size && switched); i++) {
        switched = 0;
        for(j = 0; j < size - i; j++)
            if(a[j] > a[i+1]) {
                switched = 1;
                hold = a[i];
                a[j] = a[j + 1];
                a[j + 1] = hold;
            }
        }
    }*/

    for (i = 0; (i < size) && switched; i++) {  // Condition
        switched = 0;
        for(j = 0; j < size - i; j++){
            if(a[j] > a[j+1]) {        //  Not use off i
                switched = 1;
                hold = a[j];
                a[j] = a[j + 1];
                a[j + 1] = hold;
            }// ??
        }
    }
}

void BubbleSort1::print() {
  for(int i = 0; i <= /*--*/size; ++i) {
    cout << a[i] << "  ";
  }
}

