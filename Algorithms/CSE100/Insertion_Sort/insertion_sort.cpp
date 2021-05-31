#include <iostream>
using namespace std;
void insertion_sort(int array [], int n)
{
    for (int j = 1; j < n; j++)
    {
        int key = array[j];
        int i =j-1;

        while (i >= 0 &&  array[i] < key)
        {
            array[i+1] = array[i];
            i--;
        }
        array[i+1] = key;
    }
    for  (int i =0; i<n; i++)
    {
        cout << array[i] << ";";
    }
}

int main(int argc, const char * argv[])
{   
    int array_size;
    cin>> array_size;

    int array[array_size];

    for (int i = 0; i<array_size; i++)
    {
        cin>>array[i];
    }
    // int array_size = 12;
    // int array[] = {1,2,3,4,5,100,-1,-2,0,-365,250,-255};
    insertion_sort(array, array_size);
    return 0;
}