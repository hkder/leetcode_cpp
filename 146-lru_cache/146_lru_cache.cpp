#include <unordered_map>

class LRUCache {
public:
    LRUCache(int capacity) : _capacity(capacity){
        dummy = new Node(-1, -1, nullptr, nullptr);
        dummy->next = dummy, dummy->prev = dummy;
    }
    ~LRUCache(){
        delete dummy;
    }
    
    int get(int key){
        if(m.find(key) == m.end()){
            return -1;
        }
        touch(key);
        return m[key]->value;
    }
    
    void put(int key, int value){
        if(m.find(key) != m.end()){
            m[key]->value = value;
            touch(key);
            return;
        }
        if(m.size() == _capacity){
            Node* lru = dummy->prev;
            m.erase(lru->key);
            dummy->prev = lru->prev;
            lru->prev->next = dummy;
            delete lru;
        }
        // create new node and add to map and head
        Node *newbie = new Node(key, value, dummy, dummy->next);
        m[key] = newbie;
        dummy->next->prev = newbie;
        dummy->next = newbie;
    }
    
private:
    int _capacity;
    typedef struct Node{
        int key, value;
        Node *prev, *next;
        Node(int k, int v, Node* p, Node *n) : key(k), value(v), prev(p), next(n){}
    }Node;
    unordered_map<int, Node*> m;
    Node* dummy;
    
    void touch(int key){
        Node* tmp = m[key];
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        
        tmp->prev = dummy;
        tmp->next = dummy->next;
        dummy->next->prev = tmp;
        dummy->next = tmp;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
