#include <iostream>
#include <ctime>
#include <vector>
#include "myHeap.h"

const int MAX_SIZE = 10;
int main()
{
    using std::cout;
    using std::endl;

    std::srand(std::time(nullptr));
    int array[MAX_SIZE];
    cout << "Unsorted:\n";
    for (int i = 0; i < MAX_SIZE; i++)
    {
        array[i] = rand() % 100;
        cout << array[i] << "  ";
    }   
      
    cout << "\nPyromid sort:\n";
    heapsort(array, array + 10);
    for (int i = 0; i < 10; i++)
    {
        cout << array[i] << "  ";
    }
    cout << endl;
    return 0;
}