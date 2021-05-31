#include <bits/stdc++.h>
#include <algorithm> 
using namespace std;

// int minCoinss(int coins[], int N, int k, int i)
// {
//     if(N==0)
//         return 0;
//     if(i < k && N > 0)
//     {
//         int maxVal = N/coins[i];
//         int minCost = INT_MAX;
//         for(int j=0; j<=maxVal; j++)
//         {
//             if(N >=j*coins[i])
//             {
//                 int res = minCoins(coins, N-j*coins[i], k, i+1);
//                 if (res != 1)
//                     minCost = min(minCost, res+j);
//             }
//         }
//         if(minCost==INT_MAX)
//             return -1;
//         else
//             return minCost;
//     }
//     return -1;
// }

int minCoins(int coins[], int N, int k, int n [])
{
    int minFound = INT_MAX;
    if(N==0)
        return 0;

    for(int i =0; i<k; i++)
    {
        if(N - coins[i] >=0)
        {
            int minForThisPath = minCoins(coins,N-coins[i], k, n);

            if(minForThisPath < minFound)
            {
                minFound = minForThisPath+1;
            }
  
        }

    }

    return minFound;
}
int main()
{
    int coins[] = {2, 3, 14};
    int N = 14;
    
    int k = 3;
    int n[3];
    for(int i = 0; i<k; i++)
        n[i]=0;
    cout<<minCoins(coins,N,k, n)<<endl;
    for(int i = 0; i<k; i++)
        cout<<n[i]<<",";
    return 0;
}