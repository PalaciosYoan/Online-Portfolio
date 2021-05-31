#include <iostream>
#include <list>
#include <cstring>

using namespace std;

class hash_table {
    int mod;
    list<int> *hashTable;
public:
    hash_table(int n);
    int h(int k);
    void insert(int k);
    void del(int k);
    void search(int k);
    void print();
};

hash_table::hash_table(int n):mod(n)
{
    hashTable = new list<int>[n];
}

int hash_table::h(int k)
{
    return (k%mod);
}

void hash_table::insert(int k)
{
    int hashValue = h(k);

    hashTable[hashValue].push_front(k);
}

void hash_table::del(int k)
{
    int hashValue = h(k);
    list<int> :: iterator val;
    val =hashTable[hashValue].begin();
    while(val !=hashTable[hashValue].end())
    {
        if(*val ==k)
            break;
        val++;
    }

    if (val != hashTable[hashValue].end())
    {  
        cout<<k<<" : DELETED"<<endl;
        hashTable[hashValue].erase(val);
    }
    else 
    {
        cout<<k<<" : DELETE FAILED"<<endl;
    }
}

void hash_table::search(int k)
{
    int i = h(k);
    list<int> :: iterator j;
    int count =0;
    for(j =hashTable[i].begin(); j != hashTable[i].end(); j++)
    {
        if(*j ==k)
        {
            cout<<k<<" : FOUND AT "<< i <<"," << count <<endl;
            break;
        }
        count++;
    }
    if (j == hashTable[i].end())
    {  
        cout<<k<<" : NOT FOUND"<<endl;
    }
}

void hash_table::print()
{
    for(int i =0; i < mod; i++)
    {
        cout<<i<<" : ";
        int c = 0;
        for(auto x: hashTable[i])
        {
            if (c == 0)
            {
                cout<<x;
                c++;
            }
            else
                cout<< "->" << x;
        }
        cout<<endl;
    }
}

int main(int argc, char* argv[])
{
    int n;
    cin>>n;
    hash_table h(n);
    bool t = true;
    while(!cin.eof())
    {
        char action;
        int num;
        cin>>action;
        if(action == 'o')
        {
            h.print();
            cout<<"++++++++++++++++++++"<<endl;
        }
        else if (action == 'i')
        {
            cin>>num;
            h.insert(num);
        }
        else if (action == 'd')
        {
            cin>>num;
            h.del(num);
            cout<<"++++++++++++++++++++"<<endl;
        }
        else if (action == 's')
        {
            cin>>num;
            h.search(num);
            cout<<"++++++++++++++++++++"<<endl;
        }
        else if (action == 'e')
        {
            t = false;
            break;
        }
    }

    return 0;
}