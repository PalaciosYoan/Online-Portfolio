#include <iostream>
using namespace std;
#include <time.h>

int partition(int A[],int p,int r)
{
    int x = A[r];
    int i = p-1;
    for(int j = p; j<=(r-1); j++)
    {
        if (A[j]<=x)
        {
            i += 1;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1], A[r]);

    return (i+1);

}

int rand_partition(int A[], int p, int r)
{
    //p = left
    srand((unsigned)time(0));
    int i = p + rand()%(r-p);
    
    swap(A[r],A[i]);
    return partition(A,p,r);
}


void rand_quick_sort(int A[], int p, int r)
{
    if (p<r)
    {
        int q = rand_partition(A, p, r);
        rand_quick_sort(A, p, q-1);
        rand_quick_sort(A, q+1, r);
    }
}

int main(int arg, const char * argv[])
{
    int size = 0;
    cin>>size;
    int arr[size];

    for (int i = 0; i<size; i++)
        cin>>arr[i];


    rand_quick_sort(arr, 0, size-1);

    for (int i =0; i<size; i++)
        cout<<arr[i]<<";";
    
}