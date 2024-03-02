#pragma once
#include <vector>
#include <list>
using namespace std;
class MyHashMap {
private:
    vector<list<pair<int, int>>> m_data;
public:
    MyHashMap() : m_data(vector<list<pair<int, int>>>(10000)){}
    
    void put(int key, int value) {
        for (auto it = m_data[key % 10000].begin(); it != m_data[key % 10000].end(); ++it) {
            if (it->first == key) {
                it->second = value;
                return;
            }
        }
        m_data[key % 10000].push_back({key, value});
    }
    
    int get(int key) {
        for (auto it = m_data[key % 10000].begin(); it != m_data[key % 10000].end(); ++it) {
            if (it->first == key) {
                return it->second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        for (auto it = m_data[key % 10000].begin(); it != m_data[key % 10000].end(); ++it) {
            if (it->first == key) {
                m_data[key % 10000].erase(it);
            }
        }
    }
};
