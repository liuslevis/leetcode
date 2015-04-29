/* 
用时6h，2天，（我的方法思路对，但是出错case无法找到），参考ref实现accept, 100ms
=== Should learn how to analysis as below === 

ref: https://leetcode.com/discuss/13964/accepted-c-solution-296-ms
1. hash map holds iterators to linked list
2. linked list holds key and value, key to access hash map items
3. when item is accessed, it's promoted - moved to the tail of the list - O(1) operation
4. when item should be removed, we remove head of the list - O(1) operation
5. when item is not promoted long time, it's moved to the head of the list automatically
6. time complexity: based on unordered_map:
    get() - avg. O(1) performance or worst O(n), set() - O(1) performance
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <assert.h>
#include <algorithm>

using namespace std;



class LRUCache{
private:
    struct item_t {
        int key, val;
        item_t(int k, int v) : key(k), val(v) {}
    };

    typedef list<item_t> list_t;
    typedef std::unordered_map<int, list_t::iterator> dict_t; // { key: list_t::iterator}

    dict_t m_dict; // {key : list_iter}
    list_t m_list; // FIFO + LRU, front()==LRU, list<item_t(key,value)>
    int capacity;

    // remove LRU item at front of the list
    void remove_LRU_item() {
        int pop_key = m_list.front().key;
        m_dict.erase(pop_key);
        m_list.pop_front();
    }

    // add item at the end of the list
    void add_new_item(int key, int value) {
        m_list.push_back(item_t(key, value));
        m_dict[key] = (--m_list.end());
    }

    // get value and promote item to the end of the list
    int get_value_and_promote_key(int key) {
        list_t::iterator it = m_dict[key];
        item_t item = item_t(it->key, it->val);
        m_list.erase(it);
        m_list.push_back(item);
        m_dict[key] = (--m_list.end());
        return item.val;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (m_dict.find(key) == m_dict.end()) {
            return -1;
        } else {
            return get_value_and_promote_key(key);
        }
    }
    
    void set(int key, int value) {
        // cout<<"set key:"<<key<<" value:"<<value<<endl;
        if (capacity == 0) return;

        // item not found
        if (m_dict.find(key) == m_dict.end()) {
            // remove LRU item if out of capacity
            if (!m_dict.empty() && m_dict.size() == capacity) {
                remove_LRU_item();
            }

        } else { // item found, move item to the end of the list
            m_list.erase(m_dict[key]);
        }
        
        add_new_item(key, value);
    }
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