#include <iostream>
#include <stdio.h>
using namespace std;

int linear_search(int arr [],int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main(int argc, const char * argv[])
{
    int target;
    int arr_size;
    cin >> arr_size;
    cin >> target;
    int arr[arr_size];
    for (int i =0; i < arr_size; i++)
    {
        cin>>arr[i];
    }
    cout << linear_search(arr, arr_size, target) << endl;
    return 0;
}