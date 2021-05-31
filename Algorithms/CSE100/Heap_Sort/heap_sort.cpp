#include <iostream>
#include <math.h>
using namespace std;

int parent(int i)
{
    return floor(i/2);
}

int left(int i)
{
    return (2*i+1);
}

int right(int i)
{
    return (2*i+2);
}

void max_heapify(int A[],int n, int i)
{
    int largest = 0;
    int l = left(i);
    int r = right(i);
    if (l < n && A[l] > A[i])
         largest = l;
    else
        largest = i;

    if (r< n && A[r]>A[largest])
        largest=r;

    if (largest != i)
    {
        swap(A[i],A[largest]);
        max_heapify(A,n, largest);
    }
    
}


void max_heap(int A [], int size)
{
    for(int i = floor(size/2)-1; i>=0; i--)
    {
        max_heapify(A,size,i);
    }

    for(int i = size-1; i>0; i--)
    {
        swap(A[0],A[i]);
        max_heapify(A,i,0);
    }
}

int main(int argc, const char * argv[])
{
    int num_sort = 0;
    cin>>num_sort;
    int arr[num_sort];
    for (int i =0; i<num_sort; i++)
    {
        cin>>arr[i];
    }
    max_heap(arr, num_sort);

    for (int i = 0; i < num_sort; i++)
        cout<<arr[i]<<";";
    
    return 0;
}