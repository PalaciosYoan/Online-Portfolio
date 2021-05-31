#include <iostream>
#include <climits>
using namespace std;

class hashs
{
    static const int tableZise = 13;
    struct item
    {
        int number;
        item* next;
    };

    item* hashTable[tableZise];
public:
    hashs()
    {
        for(int i=0; i<tableZise; i++)
        {
            hashTable[i] = new item;
            hashTable[i]->number = INT_MIN;
            hashTable[i]->next = NULL;
        }
    }
    int h1(int k)
    {
        return (k%13);
    }
    int h2(int k)
    {
        return (1+(k%11));
    }
    int hashKey(int key, int i)
    {
        int hash = 0;
        return ((h1(key)+i*h2(key))%13);
    }

    void insert(int key)
    {
        int i =0;
        int index = abs(hashKey(key, i));//acount for negative numbers
        while(hashTable[index]->number != INT_MIN)
        {
            index = abs(hashKey(key, i));
            i++;
        }
        hashTable[index]->number = key;
        
    }
    void search(int val)
    {
        bool found = false;
        int i =0;
        for(i; i < tableZise; i++)
        {
            if(hashTable[i]->number == val)
            {
                found = true;
                break;
            }
        }
        if(found)
            cout<<i<<endl;
        else
            cout<<"NOT_FOUND"<<endl;
    }
    void del(int val)
    {
        int i =0;
        for(i; i < tableZise; i++)
        {
            if(hashTable[i]->number == val)
            {
                hashTable[i]->number = INT_MIN;
                break;
            }
        }
    }

    void print()
    {
        for(int i =0; i<tableZise; i++)
        {
            if(hashTable[i]->number == INT_MIN)
                cout<<""<<endl;
            else
                cout<<hashTable[i]->number<<endl;
        }
    }
};


int main(int argc, char* argv[])
{   
    hashs table;

    int action = -1;
    
    while(!cin.eof())
    {
        int user;
        cin>>user;

        if(user == -1)
        {
            cout<<"++++table printout++++"<<endl;
            table.print();
            action = -2;
            cout<<"++++searching++++"<<endl;
            continue;
        }
        else if(user == -2)
        {
            action = -3;
            cout<<"++++deleting++++"<<endl;
            continue;
        }
        else if(user == -3)
        {
            cout<<"++++table printout++++"<<endl;
            table.print();
            break;
        }
        if(action == -1)
        {
            table.insert(user);
        }
        else if(action == -2)
        {
            table.search(user);
        }
        else if(action == -3)
        {
            table.del(user);
        }
    }

    return 0;
}