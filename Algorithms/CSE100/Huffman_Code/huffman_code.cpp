//Author: Yoan Palacios Guzman

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

struct Node
{
public:
    int index;
    int freq;
    Node *left;
    Node *right;

    Node(int index, int freq)
    {
        this->index = index;
        this->freq = freq;
        left = NULL;
        right = NULL;
    }
};

struct minHeapPropertyCompare
{
    bool operator()(Node* left, Node*right){ return left->freq > right->freq;}
};

Node* root;
vector<string> temp;

void sortToPrint(Node* r, string st)
{
    if (r->left == NULL && r->right == NULL)
    {
        //Update vector to the mapping of location and return nothing
        temp[r->index-1] = st;
        return;
    }
    sortToPrint(r->left, st+"0");
    sortToPrint(r->right, st+"1");
}

void huffman(vector<int>& data, vector<int>& freq, int n)
{
    Node *x, *y;

    priority_queue<Node*, vector<Node*>, minHeapPropertyCompare> heap;

    for(int i=0; i< n; ++i)
        heap.push(new Node(data[i], freq[i]));//creating "array of frequencies"

    for(int i=0;i<n-1;i++) //do this until we have the root of the huffman tree
    {
        x = heap.top();
        heap.pop();

        y = heap.top();
        heap.pop();

        root = new Node(INT_MIN, x->freq+y->freq);
        root ->left = x;
        root ->right= y;

        heap.push(root);
    }

    sortToPrint(heap.top(), "");

    for(int i=0; i<temp.size(); i++)
        cout<<temp[i]<<endl;
}



int main(int argc, char* argv[])
{
    int n, x;
    cin>>n;

    vector<int> index, freq;

    for (int i=0;i<n;i++)
    {
        index.insert(index.end(), i+1);
        temp.push_back("GG");
    }
    for (int i=0;i<n;i++)
    {
        cin>>x;
        freq.insert(freq.end(), x);
    }

    huffman(index, freq, n);

}