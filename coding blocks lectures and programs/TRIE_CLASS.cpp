#include<bits/stdc++.h>
using namespace std;
int size=0;
class node
{
    vector<node*>children;
    bool is_terminal;
public:
    node():is_terminal(false)
    {
       children.resize(26,NULL);
    }

    bool has_child()
    {
        for(int i=0;i<26;i++)
        {
            if(children[i]!=NULL)
            {
                return true;
            }
        }
        return false;
    }

    int child_count()
    {
        int count=0;
        for(int i=0;i<26;i++)
        {
            if(children[i]!=NULL)
            {
                count++;
            }
        }
        return count;
    }
    friend class Tries;
};
class Tries
{
   node*root;
   public:
   Tries()
   {
       root=new node;
   }

   void insert_word(const string word)
   {
       node*it=root;
       for(int i=0;i<word.size();i++)
       {
           if(it->children[word[i]-'a']==NULL)
           {
               it->children[word[i]-'a']=new node;
           }
           it=it->children[word[i]-'a'];
       }
       it->is_terminal=true;
   }

   bool has_word(const string word) const
   {
       node*it=root;
       for(int i=0;i<word.size();i++)
       {
           if(it->children[word[i]-'a']==NULL)
           {
               return false;
           }
           it=it->children[word[i]-'a'];
       }
       if(it->is_terminal)
       {
           return true;
       }
       return false;
   }


   void delete_word(const string word)
   {
       if(word.size()==0)
       {
           throw" GIVEN STRING IS EMPTY";
       }
      node*it=delete_word_helper(word,root,0);
      if(it==NULL)
      {
          root=new node;
      }

      return ;
   }

   private:
    static node*delete_word_helper(const string word,node*curr,int index)
    {
        if(index==word.size())
        {
            if(curr==NULL || curr->is_terminal==false)
            {
                throw "WORD DOES NOT EXISTS";
            }
            if(curr->has_child())
            {
                curr->is_terminal=false;
                return curr;
            }
            delete curr;
            return NULL;
        }

        if(curr==NULL)
        {
            throw"word does not exist";
        }
        curr->children[word[index]-'a']=delete_word_helper(word,curr->children[word[index]-'a'],index+1);
        if(curr->has_child())
        {
            return curr;
        }
        if(curr->is_terminal)
        {
            return curr;
        }
        delete curr;
        return NULL;
    }

    public:
    vector<string>prefix(const string word)
    {
        vector<string>s;
        if(word.size()==0)
        {
            throw"GIVEN STRING IS EMPTY";
        }
        node*address=function(root,word,0);
        if(address==NULL)
        {
            cout<<"no words possible";
            return s;
        }
        if(address->child_count()==0)
        {
            if(address->is_terminal)
            {
                cout<<" no words possible except given prefix";
            }
            else{
                cout<<"no possible words";
            }
            return s;
        }
        s.resize(5);
        for(int i=0;i<word.size();i++)
        {
            s[0].push_back(word[i]);   ///ask for string pushback word
        }
                                        ///s.push_back(word);
        get_all_words(s,address);
        while(s.size()!=size)
        {
            s.pop_back();
        }
        return s;
    }


    void get_all_words( vector<string> & v ,const node*curr)
    {
        if(curr->is_terminal)
        {
           for(int i=0;i<v[size].size();i++)
           {
               if(v.size()==size+1)
               {
                   v.resize(2*size+2);
               }
             v[size+1].push_back(v[size][i]);
           }
           size++;
        }
        for(int i=0;i<26;i++)
        {
            if(curr->children[i]!=NULL)
            {
                 char ch='a'+i;
                 v[size].push_back(ch);
                 get_all_words(v,curr->children[i]);
            }
        }
        v[size].pop_back();
        return ;
    }

    private:
    static node*function(const node*curr,const string word,int index)
    {
        if(index==word.size()-1)
        {
            if(curr==NULL)
            {
                return NULL;
            }
            if(curr->children[word[word.size()-1]-'a']==NULL)
            {
                return NULL;
            }
            return curr->children[word[word.size()-1]-'a'];
        }

        if(curr==NULL)
        {
            return NULL;
        }
        return function(curr->children[word[index]-'a'],word,index+1);
    }

};
int main ()
{
    Tries T;
    T.insert_word("fore");
    T.insert_word("forest");
    T.insert_word("fork");
    T.insert_word("force");
    T.insert_word("forced");
    T.insert_word("forbid");
    T.insert_word("for");
    vector<string>v=T.prefix("fis");
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}
