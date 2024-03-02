#pragma once
#include <string>
#include <unordered_map>
#include <map>
using namespace std;
class TimeMap {
private:
    unordered_map<string, map<int, string>> data;

public:
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp);
    
    string get(string key, int timestamp);
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
