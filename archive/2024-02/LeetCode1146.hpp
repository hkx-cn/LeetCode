#pragma once
#include <vector>
using namespace std;
class SnapshotArray {
private:
    vector<vector<int>> m_data;
    int m_index;

public:
    SnapshotArray(int length) : m_data(length, vector<int>(1, 0)), m_index(0) {

    }
    
    void set(int index, int val) {
        while (m_data[index].size() < m_index + 1) {
            m_data[index].push_back(m_data[index][m_data[index].size() - 1]);
        }
        m_data[index][m_data[index].size() - 1] = val;
    }
    
    int snap() {
        m_index++;
        return m_index - 1;
    }
    
    int get(int index, int snap_id) {
        if (m_data[index].size() < snap_id + 1) {
            return m_data[index][m_data[index].size() - 1];
        }
        return m_data[index][snap_id];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
