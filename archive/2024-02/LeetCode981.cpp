//981. 基于时间的键值存储
//设计一个基于时间的键值数据结构，该结构可以在不同时间戳存储对应同一个键的多个值，并针对特定时间戳检索键对应的值。
//
//实现 TimeMap 类：
//
//TimeMap() 初始化数据结构对象
//void set(String key, String value, int timestamp) 存储给定时间戳 timestamp 时的键 key 和值 value。
//String get(String key, int timestamp) 返回一个值，该值在之前调用了 set，其中 timestamp_prev <= timestamp 。如果有多个这样的值，它将返回与最大  timestamp_prev 关联的值。如果没有值，则返回空字符串（""）。
//
//示例 1：
//输入：
//["TimeMap", "set", "get", "get", "set", "get", "get"]
//[[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]
//输出：
//[null, null, "bar", "bar", null, "bar2", "bar2"]
//解释：
//TimeMap timeMap = new TimeMap();
//timeMap.set("foo", "bar", 1);  // 存储键 "foo" 和值 "bar" ，时间戳 timestamp = 1   
//timeMap.get("foo", 1);         // 返回 "bar"
//timeMap.get("foo", 3);         // 返回 "bar", 因为在时间戳 3 和时间戳 2 处没有对应 "foo" 的值，所以唯一的值位于时间戳 1 处（即 "bar"） 。
//timeMap.set("foo", "bar2", 4); // 存储键 "foo" 和值 "bar2" ，时间戳 timestamp = 4  
//timeMap.get("foo", 4);         // 返回 "bar2"
//timeMap.get("foo", 5);         // 返回 "bar2"
//
//提示：
//1 <= key.length, value.length <= 100
//key 和 value 由小写英文字母和数字组成
//1 <= timestamp <= 10^7
//set 操作中的时间戳 timestamp 都是严格递增的
//最多调用 set 和 get 操作 2 * 10^5 次
#include "LeetCode981.hpp"
void TimeMap::set(string key, string value, int timestamp) {
    data[key][timestamp] = value;
}

string TimeMap::get(string key, int timestamp) {
    string result;
    auto& map = data[key];
    for (auto it = map.rbegin(); it != map.rend(); it++ ) {
        if (it->first <= timestamp) {
            auto [a, b] = map.begin();
            result = it->second;
            break;
        }
    }
    return result;
}
//方法一：哈希表 + 二分查找
//为实现 get 操作，我们需要用一个哈希表存储 set 操作传入的数据。具体地，哈希表的键为字符串 key，值为一个二元组列表，二元组中存储的是时间戳 timestamp 和值 value。
//由于 set 操作中的时间戳都是严格递增的，因此二元组列表中保存的时间戳也是严格递增的，这样我们可以根据 get 操作中的 key 在哈希表中找到对应的二元组列表 pairs，然后根据 timestamp 在 pairs 中二分查找。我们需要找到最大的不超过 timestamp 的时间戳，对此，我们可以二分找到第一个超过 timestamp 的二元组下标 i，若 i>0 则说明目标二元组存在，即 pairs[i−1]，否则二元组不存在，返回空字符串。
//class TimeMap {
//    unordered_map<string, vector<pair<int, string>>> m;
//
//public:
//    TimeMap() {}
//
//    void set(string key, string value, int timestamp) {
//        m[key].emplace_back(timestamp, value);
//    }
//
//    string get(string key, int timestamp) {
//        auto &pairs = m[key];
//        // 使用一个大于所有 value 的字符串，以确保在 pairs 中含有 timestamp 的情况下也返回大于 timestamp 的位置
//        pair<int, string> p = {timestamp, string({127})};
//        auto i = upper_bound(pairs.begin(), pairs.end(), p);
//        if (i != pairs.begin()) {
//            return (i - 1)->second;
//        }
//        return "";
//    }
//};
//复杂度分析
//时间复杂度：
//初始化 TimeMap 和 set 操作均为 O(1)；
//get 操作为 O(logn)，其中 n 是 set 操作的次数。最坏情况下 set 操作插入的 key 均相同，这种情况下 get 中二分查找的次数为 O(logn)。
//空间复杂度：O(n)，其中 n 是 set 操作的次数。我们需要使用哈希表保存每一次set 操作的信息。
