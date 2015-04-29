#include <iostream>
#include <vector>
#include <map>
#include <deque>
#include <assert.h>
#include <algorithm>

typedef std::map<int, int> Dict;
typedef Dict::const_iterator It;

using namespace std;

class LRUCache{
private:
    std::map<int, int> dict;
    deque<int> access_fifo;
    std::map<int, deque<int>::const_iterator > access_fifo_dict; // {key: isInFifo}

    int capacity;

    void mark_LRU_key(int key) {
        
        // if access item in queue
        if (access_fifo_dict.find(key) != access_fifo_dict.end()) 
        {
            // cout<<"mark_LRU_key: item in queue, key:"<<key<<endl;
            deque<int>::const_iterator it = access_fifo_dict[key];
            access_fifo.erase(it);
            access_fifo.push_back(key);
        } else {// item not in queue
            // queue is full
            // cout<<"mark_LRU_key: item not in queue, key:"<<key<<endl;
            if (access_fifo.size() == capacity) {
                int pop_key = access_fifo.front();
                access_fifo.pop_front();
                access_fifo_dict[pop_key] = access_fifo.end();

                dict.erase( dict.find(pop_key));
            }

            access_fifo.push_back(key);
            access_fifo_dict[key] = (access_fifo.end() - 1);
        }
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (dict.find(key) == dict.end()) {
            return -1;
        } else {
            // cout<<"get key:"<<key<<" value:"<<dict.find(key)->second<<endl;
            mark_LRU_key(key);
            return dict.find(key)->second;
        }
    }
    
    void set(int key, int value) {
        // cout<<"set key:"<<key<<" value:"<<value<<endl;
        if (capacity == 0) return;
        
        dict[key] = value;
        mark_LRU_key(key);
    }

    // void test(){
    //     for (int i = 0; i < 3; ++i)
    //     {
    //         cout<<"dict.find("<<i<<")==dict.end():"<<(dict.find(i)==dict.end())<<endl;
    //         if (dict.find(i)!=dict.end()) {
    //             cout<<"dict["<<i<<"]="<<dict[i]<<endl;
    //         }
    //     }
    // }
};

void test() {
    LRUCache lru = LRUCache(1);
    lru.set(1,2);
    assert(2 == lru.get(1));
    assert(-1 == lru.get(2));
    lru.set(2,3);
    assert(-1 == lru.get(1));
    assert(3 == lru.get(2));

    LRUCache lru2 = LRUCache(2);
    lru2.set(1,11);
    lru2.set(2,22);
    assert(11 == lru2.get(1));
    lru2.set(3,33);
    assert(11 == lru2.get(1));
    assert(-1 == lru2.get(2));
    assert(33 == lru2.get(3));

    LRUCache lru3 = LRUCache(3);
    lru3.set(1,11);
    lru3.set(2,22);
    lru3.set(3,33);
    assert(22 == lru3.get(2));
    lru3.set(4,44);
    assert(-1 == lru3.get(1));
    assert(33 == lru3.get(3));

    LRUCache lru4 = LRUCache(0);
    assert(-1 == lru4.get(-1));
    assert(-1 == lru4.get(0));
    assert(-1 == lru4.get(1));
    lru4.set(1,11);
    assert(-1 == lru4.get(0));
    assert(-1 == lru4.get(1));

    LRUCache lru5 = LRUCache(1);
    assert(-1 == lru5.get(0));
    lru5.set(1,11);
    assert(-1 == lru5.get(0));
    assert(-1 == lru5.get(2));
    assert(11 == lru5.get(1));//failed
    lru5.set(2,22);
    assert(-1 == lru5.get(-1));
    assert(-1 == lru5.get(0));
    assert(-1 == lru5.get(1));
    assert(22 == lru5.get(2));

    LRUCache lru6 = LRUCache(2);
    assert(-1 == lru6.get(2));
    lru6.set(2,6);
    assert(-1 == lru6.get(1));
    lru6.set(1,5);
    lru6.set(1,2);
    assert(2 == lru6.get(1));
    assert(6 == lru6.get(2));

    LRUCache lru7 = LRUCache(2);
    lru7.set(2,1);
    lru7.set(1,1);
    lru7.set(2,3);
    lru7.set(4,1);
    assert(-1 == lru7.get(1));
    assert(3 == lru7.get(2));
    assert(1 == lru7.get(4));

    LRUCache lru8 = LRUCache(1);
    assert(-1 == lru7.get(0));


    printf("pass test!\n");
}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}