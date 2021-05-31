//Followed the provided psuedo code and the book's pseudo code
#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

void primMST(vector<pair<int,int> > G[], int numVertices) {
    priority_queue< pair<int, int>, vector <pair<int, int>> , greater<pair<int, int>> > Q;
    int u, v, w;
    int key[numVertices], pi[numVertices];
    bool visited[numVertices];

    for(int i=0; i < numVertices; i++)
    {
        key[i]=INT_MAX;
        pi[i]=-1;
        visited[i]=false;
    }

    Q.push(make_pair(0, 0));
    key[0] = 0;
    
    while (!Q.empty()) {
        u = Q.top().second, Q.pop(), visited[u] = true;

        for(vector<pair<int,int> >::iterator j = G[u].begin(); j != G[u].end(); j++)
        {
            v = (*j).first, w = (*j).second;
            if (visited[v] == false && key[v] > w) {
                pi[v] = u;
                key[v] = w;
                Q.push(make_pair(key[v], v));
            }    
        }
    }

    for (int i = 1; i < numVertices; ++i)
        cout<<pi[i]<<endl;
}

int main() {
   int numVertices, numEdges, u, v, w;
   cin >> numVertices;
   cin >> numEdges;
   
   vector<pair<int, int> > G[numVertices];

   for(int i=0; i<numEdges; i++){
        cin >> u;
        cin>> v;
        cin >> w;
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }

   primMST(G, numVertices);

   return 0;
}