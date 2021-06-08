#include<iostream>
#include<unordered_map>
#include<vector>
  
using namespace std;

#define hashmap unordered_map<char ,node*>

class node{
    public:
    char data;
    hashmap h;
    bool isTerminal;
    // constructor
    node(char d){
        data=d;
        isTerminal=false;
    }

};

class Trie{
    node * root;

  
    public:
      Trie(){
         root=new node ('\0'); 
      }
      // insertion

        void insert(string s){

            node *temp=root;
            for(int i=0;i<s.size();i++){
                char ch=s[i]; 

              if(temp->h.count(ch)==0){
                  node * child=new node(ch);
                  temp->h[ch]=child;
                  temp=child;
              }
              else{
                  temp=temp->h[ch];
              }   
            }
            temp->isTerminal=true;
        }

      // lookup
    bool search(string s){

        node * temp=root;

        for(int i=0;i<s.size();i++){

            char ch=s[i];
            if(temp->h.count(ch)){
                temp=temp->h[ch];
            }
            else 
                return false;
        }

         return (temp->isTerminal);

    }

};

int main(){

    Trie t;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
            t.insert(s);
    }

    int query;
    cin>>query;
    while(query--){
        string s;
        cin>>s;

        cout<<t.search(s)<<endl;
    }

    return 0;
}