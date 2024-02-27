#pragma ocne
#include <vector>
using namespace std;

class MyLinkedList {
private:
    vector<int> m_data;
    int index;

public:
    MyLinkedList() : index(0) {

    }
    
    int get(int index) {
        if (index < 0 || index >= m_data.size()) {
            return -1;
        }
        return m_data[index];
    }
    
    void addAtHead(int val) {
        m_data.insert(m_data.begin(), val);
    }
    
    void addAtTail(int val) {
        m_data.push_back(val);
    }
    
    void addAtIndex(int index, int val) {
        if (index == m_data.size()) {
            m_data.push_back(val);
            return;
        }
        else if (index > m_data.size()) {
            return;
        }
        m_data.insert(m_data.begin() + index, val);
    }
    
    void deleteAtIndex(int index) {
        if (index >=0 && index < m_data.size()) {
            m_data.erase(m_data.begin() + index);
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
