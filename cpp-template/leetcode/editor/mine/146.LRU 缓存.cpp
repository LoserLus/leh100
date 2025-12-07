/*
 * @lc app=leetcode.cn id=146 lang=cpp
 * @lcpr version=30203
 *
 * [146] LRU 缓存
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <list>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include "../common/utils.cpp"

using namespace std;

// @lc code=start
class LRUCache
{
public:
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, decltype(cache.begin())> key_map;
    LRUCache(int capacity_) : capacity{capacity_}
    {
    }

    int get(int key)
    {
        if (key_map.count(key))
        {
            auto tmp = *key_map[key];
            cache.erase(key_map[key]);
            cache.push_back(tmp);
            auto it = cache.end();
            key_map[key] = it--;
        }
        else
            return -1;
    }

    void put(int key, int value)
    {
        if (key_map.count(key))
        {
            auto tmp = *key_map[key];

            cache.erase(key_map[key]);
            cache.push_back(tmp);
            auto it = cache.end();
            key_map[key] = it--;
        }
        else if (key_map.size() <= capacity)
        {
            pair<int, int> tmp = {key, value};
            cache.push_back(tmp);
            auto it = cache.end();
            key_map[key] = it--;
        }
        else
        {
            auto tmp = cache.front();
            key_map.erase(tmp.first);
            cache.erase(cache.begin());
            put(key, value);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

int main()
{
    Solution solution;
    // your test code here
}
