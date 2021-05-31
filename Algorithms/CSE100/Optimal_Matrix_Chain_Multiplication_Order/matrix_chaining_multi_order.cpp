#include <iostream>
#include <climits>
#include <vector>
using namespace std;


void prints(vector<vector<int>> S, int i, int j)
{
    if (i == j)
    {
        cout << "A" << i-1;
        return;
    }
    cout << "(";
    prints(S, i, S[i][j]);
    prints(S, S[i][j] + 1, j);
    cout << ")";
}

void memoized_matrix(int p[],int n)
{
    vector< vector<int> > m(n+1, vector<int>(n+1,0));
    vector<vector<int>>S(n+1, vector<int>(n+1,0));

    int t = 0;

    for(int i=1; i<n;i++)
        m[i][i] = 0;
        

    for(int l =2; l<=n; l++)
        for(int i =1; i<=n-l+1;i++)
        {
            int j = i+l-1;
            m[i][j] = INT_MAX;

            for(int k=i; k<=j-1; k++)
            {
                int q = m[i][k]+m[k+1][j]+ p[i-1]*p[k]*p[j];
                if(q <m[i][j])
                {
                    m[i][j]=q;
                    t = m[i][j];
                    S[i][j] =k;
                }
            }
        }

    cout<<t<<"\n";

    prints(S, 1, n);

}

int main(int argc, char * argv[])
{
    int n;
    cin>>n;

    int *arr = new int[n + 1];

    for(int i = 0; i < n + 1; i++)
        cin>>arr[i];

    memoized_matrix(arr, n);

    return 0;
}