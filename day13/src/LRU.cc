#include <iostream>
#include <unordered_map>
#include <list>

using std::pair;
using std::unordered_map;
using std::list;

class LRUCache {
public:
    LRUCache(int capacity) 
    :_size(capacity)
    {}
    int get(int key) {
        auto it = _dict.find(key);
        if(it == _dict.end())
            return -1;
        int value = it->second->second;
        _list.erase(it->second);
        _list.push_front(std::make_pair(key, value));
        _dict[key] = _list.begin();
        return value;
    }
    
    void put(int key, int value) {
        auto it = _dict.find(key);
        if(it != _dict.end())
        {
            _list.erase(it->second);
        }
        _list.push_front(std::make_pair(key, value));
        _dict[key] = _list.begin();
        if(_list.size() > _size)
        {
            int key = _list.back().first;
            _dict.erase(key);
            _list.pop_back();
        }
    }
private:
    unordered_map<int, list<pair<int, int> >::iterator >_dict;
    list<pair<int, int> > _list;
    int _size;
};

int main()
{
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    std::cout<<cache.get(1)<<std::endl;       // 返回  1
    cache.put(3, 3);    // 该操作会使得密钥 2 作废
    std::cout<<cache.get(2)<<std::endl;           // 返回 -1 (未找到)
    cache.put(4, 4);    // 该操作会使得密钥 1 作废
    std::cout<<cache.get(1)<<std::endl;          // 返回 -1 (未找到)
    std::cout<<cache.get(3)<<std::endl;         // 返回  3
    std::cout<<cache.get(4)<<std::endl;           // 返回  4
    return 0;
}
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */