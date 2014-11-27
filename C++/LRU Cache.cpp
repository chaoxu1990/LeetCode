/*

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

*/

class LRUCache{
private:
    class cacheNode{
    public:
        int key;
        int value;
        cacheNode(int k, int v): key(k), value(v){}
    };
    int key;
    int value;
    int capacity;
    list<cacheNode> cache;
    unordered_map<int, list<cacheNode>::iterator> table;

    void moveToHead(list<cacheNode>::iterator it)
    {
        cache.erase(it);
        cache.push_front(*it);
        table[it->key] = cache.begin();
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if(table.find(key) == table.end())
            return -1;
        moveToHead(table[key]);
        return table[key]->value;
    }

    void set(int key, int value) {
        if(table.find(key) == table.end())
        {
            cacheNode newNode(key, value);
            cache.push_front(newNode);
            table[key] = cache.begin();
            if(cache.size() > capacity)
            {
                table.erase(cache.back().key);
                cache.pop_back();
            }
        }
        else
        {
            auto it = table.find(key);
            it->second->value = value;
            moveToHead(table[key]);
        }
    }
};
