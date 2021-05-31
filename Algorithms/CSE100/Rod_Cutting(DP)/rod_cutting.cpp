#include <iostream>
#include <climits>

using namespace std;
int *r, *s;
void exteneded_bottom_up_cut_rod(int p[], int n)
{
    r = new int[n+1];
    s = new int[n+1];
    r[0]=0;
    for(int j =1; j<=n; j++)
    {
        int q = INT_MIN;
        for(int i = 1; i<=j; i++)
        {
            if(q<p[i]+r[j-i])
            {
                q = p[i]+r[j-i];
                s[j]=i;
            }
        }
        r[j]=q;
    }
}
void print(int p[], int n)
{
    exteneded_bottom_up_cut_rod(p, n);
    cout<<r[n]<<endl;
    while(n>0)
    {
        cout<<s[n]<<" ";
        n=n-s[n];
    }
    cout<<"-1"<<endl;
}
int main(int argc,char **argv) {
    int n;
    cin >> n;

    int p[n+1];
    p[0] =0;

    for(int i=1; i <= n; i++)
        cin>>p[i];

    print(p, n);

    return 0;
}
