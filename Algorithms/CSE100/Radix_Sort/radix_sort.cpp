#include <iostream> 
#include <vector> 
using namespace std;



void count_sort(int vec[], int n)
{
    int k = 10;
    int b[n];
    int c[k];
   
    for (int i=0; i<k; i++)
    {
        c[i]=0;
    }
    
    for (int j=0; j<n; j++)
        c[vec[j]]=c[vec[j]]+1;

       
    for (int i =1; i<k; i++)
        c[i]=c[i]+c[i-1];
    
    
    for (int j=n-1; j>=0; j--)
    {
        b[c[vec[j]]-1] = vec[j];
        c[vec[j]]=c[vec[j]]-1;
    }
    
}

void radix(vector<vector<int>> vecs, int d)
{
    int temp [d];
    int index [d];
    // for(int j =9; j>=0; j--)
    // {    
    //     for (int i =0; i<d; i++)
    //     {
    //         temp[i] = vecs[i][j];
    //     }
    //     count_sort(temp, d, index);
        
    // }
    for(int j =0; j<d; j++)
    {
        //dosomething
        
    }
    for(int i =0; i < d; i++)
    {
        cout<<temp[i]<<";";
    }
    cout<<endl;
}

int main(int argc, const char * argv [])
{
    vector<vector<int>> vecs {
                            {1,2,3,4,5,6,7,8,9,0},
                            {9,2,1,4,5,6,3,1,4,3},
                            {2,3,4,5,6,1,8,3,8,2},
                            {9,9,4,5,6,9,8,9,8,2},
                            {0,0,4,0,6,0,8,0,8,0},
                            {7,3,7,5,7,1,7,3,7,2},
                            {4,3,4,4,6,1,4,3,4,2},
                            };
    int r =7;
    int c = 10;
    //cin>>r;
    radix(vecs, vecs.size());
    // for (int i =0; i< r; i++)
    // {
    //     vector<int> v2;
    //     for (int j =0; j < c; j++)
    //     {
    //         int temp = 0;
    //         cin >>temp;
    //         v2.push_back(temp);
    //     }

    // }

    // for (int i =0; i< vecs.size(); i++)
    // {
    //     for (int j =0; j < vecs[i].size(); j++)
    //     {
    //         cout<<vecs[i][j]<<";";
    //     }
    //     cout<<endl;
    // }

}