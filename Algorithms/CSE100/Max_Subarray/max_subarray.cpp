#include <iostream>
#include <climits>
#include "math.h"
using namespace std;

int max_cross_subarray(int array [], int L, int mid, int H)
{
    int left_sum = INT_MIN; 
    int right_sum = INT_MIN;

    int sum = 0;
    for (int i = mid; i >= L; i--)
    {
        sum += array[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    sum = 0;
    for(int i = mid+1; i <= H; i++)
    {
        sum += array[i];
        if (sum > right_sum)
            right_sum = sum;
    }
    return (left_sum+right_sum);
}


int max_sub_array(int arr [], int L, int H)
{
    //L = low, H = high
    if (L==H)
        return arr[L];

    int mid = floor((L+H)/2);

    int left_sum = max_sub_array(arr, L, mid);
    int right_sum = max_sub_array(arr, mid+1, H);
    int cross_sum = max_cross_subarray(arr, L, mid, H);

    if (left_sum >= right_sum && left_sum >= cross_sum)
        return left_sum;
    else if (right_sum >= left_sum && right_sum >= cross_sum)
        return right_sum;
    else
        return cross_sum;
    
    
}



int main(int argc, const char * argv[])
{
    int size = 0;
    cin>>size;

    int arr [size];

    for (int i=0; i < size; i++)
        cin>>arr[i];

    cout<<max_sub_array(arr, 0 , size-1);
    
    return 0;
}