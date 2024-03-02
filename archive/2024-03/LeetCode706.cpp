//706. 设计哈希映射
//不使用任何内建的哈希表库设计一个哈希映射（HashMap）。
//实现 MyHashMap 类：
//MyHashMap() 用空映射初始化对象
//void put(int key, int value) 向 HashMap 插入一个键值对 (key, value) 。如果 key 已经存在于映射中，则更新其对应的值 value 。
//int get(int key) 返回特定的 key 所映射的 value ；如果映射中不包含 key 的映射，返回 -1 。
//void remove(key) 如果映射中存在 key 的映射，则移除 key 和它所对应的 value 。
//
//示例：
//输入：
//["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
//[[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
//输出：
//[null, null, null, 1, -1, null, 1, null, -1]
//解释：
//MyHashMap myHashMap = new MyHashMap();
//myHashMap.put(1, 1); // myHashMap 现在为 [[1,1]]
//myHashMap.put(2, 2); // myHashMap 现在为 [[1,1], [2,2]]
//myHashMap.get(1);    // 返回 1 ，myHashMap 现在为 [[1,1], [2,2]]
//myHashMap.get(3);    // 返回 -1（未找到），myHashMap 现在为 [[1,1], [2,2]]
//myHashMap.put(2, 1); // myHashMap 现在为 [[1,1], [2,1]]（更新已有的值）
//myHashMap.get(2);    // 返回 1 ，myHashMap 现在为 [[1,1], [2,1]]
//myHashMap.remove(2); // 删除键为 2 的数据，myHashMap 现在为 [[1,1]]
//myHashMap.get(2);    // 返回 -1（未找到），myHashMap 现在为 [[1,1]]
//
//提示：
//0 <= key, value <= 10^6
//最多调用 10^4 次 put、get 和 remove 方法
#include "LeetCode706.hpp"
//方法一：链地址法
//我们假定读者已经完成了「705. 设计哈希集合」这一题目。
//「设计哈希映射」与「设计哈希集合」解法接近，唯一的区别在于我们存储的不是 key 本身，而是 (key,value) 对。除此之外，代码基本是类似的。
//class MyHashMap {
//private:
//    vector<list<pair<int, int>>> data;
//    static const int base = 769;
//    static int hash(int key) {
//        return key % base;
//    }
//public:
//    /** Initialize your data structure here. */
//    MyHashMap(): data(base) {}
//    
//    /** value will always be non-negative. */
//    void put(int key, int value) {
//        int h = hash(key);
//        for (auto it = data[h].begin(); it != data[h].end(); it++) {
//            if ((*it).first == key) {
//                (*it).second = value;
//                return;
//            }
//        }
//        data[h].push_back(make_pair(key, value));
//    }
//    
//    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
//    int get(int key) {
//        int h = hash(key);
//        for (auto it = data[h].begin(); it != data[h].end(); it++) {
//            if ((*it).first == key) {
//                return (*it).second;
//            }
//        }
//        return -1;
//    }
//    
//    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
//    void remove(int key) {
//        int h = hash(key);
//        for (auto it = data[h].begin(); it != data[h].end(); it++) {
//            if ((*it).first == key) {
//                data[h].erase(it);
//                return;
//            }
//        }
//    }
//};
//复杂度分析
//时间复杂度：O(nb)。其中 n 为哈希表中的元素数量，b 为链表的数量。假设哈希值是均匀分布的，则每个链表大概长度为 nb 。
//空间复杂度：O(n+b)。
