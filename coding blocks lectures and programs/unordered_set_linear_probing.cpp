#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<algorithm>
#include<iterator>
using namespace std;
template<typename t>
class unordered_set_linear_probing
{
    vector<t> table;
    unsigned int count;
public:
    unordered_set_linear_probing(unsigned int size=10):count(0),table(size,-1){}
    int  my_hash(const t& key)
    {
        int index=hash(key)%table.size();
        if(table[index]==-1 || table[index]==key)
        {
            return index;
        }
        else
        {
            for(int i=1;i<table.size();i++)
            {
                int temp_index=(index+i)%table.size();
                if(table[temp_index]!=-1 && table[temp_index]!=key)
                {
                    continue;
                } else if(table[temp_index]==-1 || table[temp_index]==key)
                {
                    return temp_index;
                }
            }
        }

    }

    void rehash()
    {
        vector<t> temp=table;
        table.clear();
        count=0;
        table.resize(2*temp.size());
        for(int i=0;i<table.size();i++)
        {
            table[i]=-1;
        }
        for(int i=0;i<temp.size();i++)
        {
            if(temp[i]==-1)
            {
                continue;
            }
            insert_key(temp[i]);
        }
        temp.clear();
        return ;
    }

    void insert_key(const t & key)
    {
        int index=my_hash(key);
        if(table[index]==key)
        {
            throw" KEY ALREADY EXISTS";
        }
        else{
            table[index]=key;
            count++;
        }

        if(count>=table.size()/2)
        {
             rehash();
        }
        return ;
    }

     t  get_key(const t & key)
    {
        int index=my_hash(key);
        if(table[index]==-1)
        {
            throw"INVALID KEY";
        }
        return table[index];
    }

private:
    static int hash(const string key)
    {
        int hash_value=0;
        int l=1;
        for(int i=0;i<key.size();i++)
        {
            hash_value+=key[i]*l;
            l=l*29;
        }
        return hash_value;
    }

    static int hash(const int key)
    {
        return key;
    }

    static int hash(const char key)
    {
        int i=key;
        return i;
    }
    public:
     bool is_empty()
    {
        return count==0;
    }

    bool contains(const t & key)
    {
        int index=my_hash(key);
        if(table[index]==key)
        {
            return true;
        }else{
               return false;
            }
    }

    void delete_key(const t & key)
    {
        int index=my_hash(key);
        if(table[index]!=-1)
        {
            table[index]=-1;
            count--;
            return ;
        }
        throw"DELETION OF INVALID KEY";
    }

    void clear()
    {
        table.clear();
        count=0;
        return ;
    }

    t  get_key_2(const t & key)
    {
        int index=my_hash(key);
        return table[index];
    }


    void print_pairs_with_sum(const vector<t>&v,int sum)
    {
        for(int i=0;i<v.size();i++)
        {
            insert_key_2(v[i]);
        }

        for(int i=0;i<v.size();i++)
        {
            t temp1,temp2;
            temp2=sum-v[i];
            if(temp2 < 0)
            {
                continue;
            }
            temp1=get_key_2(sum-v[i]);
            if(temp1==-1)
            {
                continue;
            }
            cout<<v[i]<<" "<<sum-v[i]<<endl;
        }
        return ;
    }

    void insert_key_2(const t & key)
    {
        int index=my_hash(key);
        if(table[index]==key)
        {
            return ;
        }
        else{
            table[index]=key;
            count++;
        }

        if(count>=table.size()/2)
        {
             rehash();
        }
        return ;
    }


    bool is_subset(const vector<t>&v1,const vector<t>&v2)
    {
        for(int i=0;i<v1.size();i++)
        {
            insert_key_2(v1[i]);
        }
        for(int i=0;i<v2.size();i++)
        {
            t temp=get_key_2(v2[i]);
            if(temp==-1)
            {
                return false;
            }
        }
        return true;
    }

    void remove_duplicates( vector<int>&v)
    {
        vector<int>sol;
        for(int i=0;i<v.size();i++)
        {
            insert_key_2(v[i]);
        }
        for(int i=0;i<v.size();i++)
        {
             t temp=get_key_2(v[i]);
             if(temp!=-1)
             {
                 sol.push_back(temp);
                 delete_key(v[i]);
             }
        }
        v.clear();
        for(int i=0;i<sol.size();i++)
        {
            v.push_back(sol[i]);
        }
        sol.clear();
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        return ;
    }


    void longest_sequence(vector<int>&v)
    {
        for(int i=0;i<v.size();i++)
        {
            insert_key_2(v[i]);
        }
        int size=-1;
        int f_val1;
        int f_val2;
        for(int i=0;i<v.size();i++)
        {
            int key_value=get_key_2(v[i]);

                if(key_value==-1)
                {
                    continue;
                }

            int curr=v[i];
            int temp1=curr;
            int temp2=curr-1;
            int j=0;
            int val1,val2;
            while(j<=v.size()+1)
            {
                int val=get_key_2(temp1);
                if(val!=-1)
                {
                    delete_key(temp1);
                    temp1++;
                    j++;
                    continue;
                }
                else{
                    val1=temp1-1;
                    break;
                }
            }
            j=0;
            while(j<=v.size()+1)
            {
                int val=get_key_2(temp2);
                if(val!=-1)
                {
                    delete_key(temp2);
                    temp2--;
                    j++;
                }
                else{
                    val2=temp2+1;
                    break;
                }
            }
            if(val1-val2+1 > size)
            {
                size=val1-val2+1;
                f_val1=val1;
                f_val2=val2;
            }
        }
        cout<<"longest possible sequence is:"<<endl;
        for(int i=f_val2;i<=f_val1;i++)
        {
            cout<<i<<" ";
        }
        return ;
    }


};

int main ()
{
    //from now check by contains function
       unordered_set_linear_probing<int> set;
       vector<int>v;
       for(int i=1;i<=5;i++)
       {
        int ch;
           cin>>ch;
           v.push_back(ch);
       }
       set.longest_sequence(v);
       //set.remove_duplicates(v);
        /* vector<int>v1,v2;
        for(int i=1;i<=20;i++)
        {
            v1.push_back(i);
        }
        for(int i=10;i<=21;i++)
        {
            v2.push_back(i);
        }
        cout<<set.is_subset(v1,v2);
        */
     /*for(int i=1;i<=5;i++)
     {
         int val;
         cin>>val;
         v.push_back(val);
     }
     int sum=6;
     set.print_pairs_with_sum(v,sum);
       /*for(int i=1;i<=100;i++)
       {
          set.insert_key(i);
       }
cout<<endl;
       for(int i=1;i<=100;i++)
       {
         cout<<set.get_key(i)<<" ";
       }
       cout<<endl;
        //set.delete_key(25);
        cout<<set.is_empty();
        */
       return 0;
}
/*

    */
