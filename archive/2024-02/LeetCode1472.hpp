#pragma once
#include <vector>
#include <string>
using namespace std;
class BrowserHistory {
private:
    vector<string> m_data;
    int index;
public:
    BrowserHistory(string homepage) : m_data({homepage}), index(0) {

    }
    
    void visit(string url) {
        index++;
        while (m_data.size() > index) {
            m_data.erase(m_data.begin() + index);
        }
        m_data.push_back(url);
    }
    
    string back(int steps) {
        index = index - steps < 0 ? 0 : index - steps;
        return m_data[index - steps];
    }
    
    string forward(int steps) {
        index = index + steps > m_data.size() - 1 ? m_data.size() - 1 : index + steps;
        return m_data[index + steps];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
