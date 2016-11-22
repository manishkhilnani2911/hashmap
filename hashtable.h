// Example program
#include <iostream>
#include <string>
using namespace std;
const int TABLE_SIZE = 128;

class hashnode{
    public:
    int key;
    int value;
    hashnode *next;
    
    hashnode(int k,int v){
        key = k;
        value = v;
        next = NULL;
    }
};
class hashtable{
    hashnode ** table;
    
public:    
    hashtable(){
        table = new hashnode*[TABLE_SIZE];
        for(int i=0;i<TABLE_SIZE;i++)
            table[i] = NULL;
    }
    
    void hashput(int val,int key){
        int hash = hashfn(key);
        int index = hash % TABLE_SIZE;
        hashnode * prev = NULL;
        hashnode * current = NULL;
        if(table[index] == NULL){
            table[index] = new hashnode(key,val);
        }
        else{
            current = table[index];
            while(current){
                prev = current;
                current = current->next;
            }
            prev->next = new hashnode(key,val);
        }
    }
    
    bool search(int key){
        int hash = hashfn(key);
        int index = hash % TABLE_SIZE;
        bool found = false;
        hashnode * current = NULL;
        if(table[index] != NULL){
            current = table[index];
            while(current){
                if(current->key == key){
                    cout<<"found val:"<<current->value<<endl;
                    found = true;
                }
                current=current->next;
            }    
        }
        if(found == true)
            return true;
        else
            return false;
    }    
    int hashfn(int key){
        return key % 10000;
    }
};
    
int main(){
    hashtable * t;
    bool flag;
    t = new hashtable();
    t->hashput(5,1);
    t->hashput(10,1);
    
    flag = t->search(1);
    cout<<flag<<endl;
    return 0;
}
    