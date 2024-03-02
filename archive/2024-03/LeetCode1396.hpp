#pragma once
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
class UndergroundSystem {
private:
    unordered_map<int, vector<pair<pair<string, int>, pair<string, int>>>> m_data;
public:
    UndergroundSystem() {

    }
    
    void checkIn(int id, string stationName, int t) {
        auto& vec = m_data[id];
        vec.push_back({{stationName, t},{stationName, t}});
    }
    
    void checkOut(int id, string stationName, int t) {
        auto& vec = m_data[id];
        vec[vec.size() - 1].second = {stationName, t};
    }
    
    double getAverageTime(string startStation, string endStation) {
        double count = 0, sum = 0;
        for (auto& vec : m_data) {
            for (size_t i = 0; i < vec.second.size(); i++) {
                if (vec.second[i].first.first == startStation && vec.second[i].second.first == endStation) {
                    sum += vec.second[i].second.second - vec.second[i].first.second;
                    count += 1;
                }
            }
        }
        return sum / count;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
