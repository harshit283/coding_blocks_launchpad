/*#include<iostream>
#include<list>
#include<vector>
#include<string>
using namespace std;
int hash(int  key)
{
    return key;
}
int hash(const string & key)
{
    int hash_value=0;
    for(int i=0;i<key.size();i++)
    {
        hash_value=hash_value*29+key[i];
    }
    return hash_value;
}
template<typename t,typename v>
class unordered_map
{
    vector<list<pair<t,v> > >table;
    unsigned long int count ;

public:
    unordered_map(int size=10):count(0) //default arguements since we have to provide some initial size to the hash table
    {
        table.resize(size);
    }
    int my_hash(const t & key)  //returns index
    {
        return hash(key)%table.size();
    }

    void rehash()
    {
        vector<list<pair<t,v> > >temp=table;
        table.clear();
        count=0;
        table.resize(2*temp.size());
        for(int i=0;i<temp.size();i++)
        {
            typename list<pair<t,v> >::iterator it=temp[i].begin();
            while(it!=temp[i].end())
            {
                insert_element(it->first,it->second);
                it++;
            }
        }
        temp.clear();
        return ;
    }

    void insert_element(const t &key,const v &value)
    {
        int index=my_hash(key);
        typename list<pair<t,v> > ::iterator it=table[index].begin();
        while(it!=table[index].end())
        {
            if(it->first==key)
            {
                it->second=value;
                return ;
            }
            it++;
        }
        pair<t,v>temp;
        temp.first=key;
        temp.second=value;
        table[index].push_back(temp);
        count++;
        if(count > table.size()) //load factor>1
        {
            rehash();
        }
        return;
    }

    bool contains(const t & key)  //determine whether given key is present or not
    {
        int index=my_hash(key);
        typename list<pair<t,v> > ::iterator it=table[index].begin();
        while(it!=table[index].end())
        {
            if(it->first==key)
            {
                return true;
            }
            it++;
        }
        return false;
    }

    v & get_value(const t & key) //for reading and writing both
    {
        int index=my_hash(key);
        typename list<pair <t,v> >::iterator it=table[index].begin();
        while(it!=table[index].end())
        {
            if(it->first==key)
            {
                return it->second;
            }
            it++;
        }
        throw"key does not exists";
    }

     const v & get_value(const t & key) const //for read only use
    {
        int index=my_hash(key);
        typename list<pair <t,v> >::const_iterator it=table[index].begin();
        while(it!=table[index].end())
        {
            if(it->first==key)
            {
                return it->second;
            }
            it++;
        }
        throw"key does not exists";
    }

    void remove(const t & key)
    {
        int index=my_hash(key);
        typename list<pair<t,v> >::iterator it=table[index].begin();
        while(it!=table[index].end())
        {
            if(it->first==key)
            {
                table[index].erase(it);
                count--;
                return ;
            }
            it++;
        }
        throw"invalid not found";
    }

    const v & operator[](const t & key) const
    {
            return get_value(key);

    }

     v & operator[](const t & key)
    {
        if(contains(key))
        {
            return get_value(key);
        }
        insert_element(key,t());  //will work for v and t type
        return get_value(key);
    }

};
int main ()
{
    unordered_map<int,int>map;
    return 0;
}
*/

#include<bits/stdc++.h>
using namespace std;
template<typename t,typename v>
class unordered_map
{
    vector<list<pair<t,v> > > table;
    unsigned int count;
public:
    unordered_map(int size=10) :count(0)
    {
        table.resize(size);
    }


    int my_hash(const t & key)
    {
        return hash(key)%table.size();
    }
private:
    int hash(const int key)
    {
        return key;
    }
    int hash(const string key)
    {
        int hash_value=0;
        int l=1;
        for(int i=0;i<key.size();i++)
        {
            hash_value=hash_value+key[i]*l;
            l=l*29;
        }
        return hash_value;
    }

private:
    void rehash()
    {
        vector<list<pair<t,v> > > temp=table;
        clear();
        table.resize(2*temp.size());
        for(int i=0;i<temp.size();i++)
        {
           typename list<pair<t,v> >::iterator it=temp[i].begin();
            while(it!=temp[i].end())
            {
                insert_or_update(it->first,it->second);
                it++;
            }
        }
        temp.clear();
        return ;
    }

    public:
    void insert_or_update(const t & key,const v & value)
    {
        int index=my_hash(key);
        typename list<pair<t,v> > ::iterator it=table[index].begin();
        while(it!=table[index].end())
        {
            if(it->first==key)
            {
                it->second=value;
                return ;
            }
            it++;
        }
        pair<t,v>my_pair(key,value);
        table[index].push_back(my_pair);
        count++;
        if(count>table.size()) //load factor >1
        {
            rehash();
        }
    }

    v & get_value(const t& key)
    {
        int index=my_hash(key);
        typename list<pair<t,v> >::iterator it=table[index].begin();
        while(it!=table[index].end())
        {
            if(it->first==key)
            {
                return it->second;
            }
            it++;
        }
        throw" INVALID KEY";
    }

     const v & get_value(const t& key) const
    {
        int index=my_hash(key);
        typename list<pair<t,v> >::iterator it=table[index].begin();
        while(it!=table[index].end())
        {
            if(it->first==key)
            {
                return it->second;
            }
            it++;
        }
        throw" INVALID KEY";
    }


    void delete_key(const t & key)
    {
        int index=my_hash(key);
        typename list<pair<t,v> >::iterator it=table[index].begin();
        while(it!=table[index].end())
        {
            if(it->first==key)
            {
                table[index].erase(it);
                return;
            }
            it++;
        }
        throw"INVALID KEY";
    }

    bool contains(const t&key)
    {
        int index=my_hash(key);
        typename list<pair<t,v> >::iterator it=table[index].begin();
        while(it!=table[index].end())
        {
            if(it->first==key)
            {
                return true;
            }
            it++;
        }
        return false;
    }

    void clear()
    {
        for(int i=0;i<table.size();i++)
        {
            table[i].clear();
        }
        count=0;
        return ;
    }


    bool is_empty()
    {
        return count==0;
    }

    const v & operator[](const t & key) const
    {
        return get_value(key);
    }

    v & operator[](const t & key)
    {
        if(contains(key))
        {
            return get_value(key);
        }
        insert_or_update(key,v());
        return get_value(key);
    }

    public:
       void return_intersection(vector<t>&v1,vector<t>&v2)
        {
            for(int i=0;i<v1.size();i++)
            {
                insert_or_update(v1[i],v1[i]);
            }
            vector<t>v3;
            for(int i=0;i<v2.size();i++)
            {
                v temp=return_value(v2[i]);
                if(temp==-100)
                {
                    continue;
                }
                else{
                     v3.push_back(temp);
                }
            }
            for(int i=0;i<v3.size();i++)
            {
                cout<<v3[i]<<" ";
            }
        }

    v  return_value(const t& key)
    {
        int index=my_hash(key);
        typename list<pair<t,v> >::iterator it=table[index].begin();
        while(it!=table[index].end())
        {
            if(it->first==key)
            {
                return it->second;
            }
            it++;
        }
        return -100;
    }
};
int main ()
{
     unordered_map<int,int>map;

    /* vector<int>v1,v2;
     for(int i=1;i<=10;i++)
     {
         v1.push_back(i);
     }
     for(int i=2;i<=20;i=i+2)
     {
         v2.push_back(i);
     }

     map.return_intersection(v1,v2);
     */

   /* for(int i=1;i<=100;i++)
    {
        map.insert_or_update(i,i);
    }

    for(int i=1;i<=100;i++)
    {
        cout<<map2.get_value(i)<<" ";
    }
*/
   /* for(int i=1;i<=50;i++)
    {
        map.delete_key(i);
    }
    for(int i=51;i<=100;i++)
    {
        cout<<map.get_value(i)<<" ";
    }
    */

    return 0;
}

