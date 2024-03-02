#pragma once
#include <vector>
using namespace std;
class MyCircularQueue {
private:
    vector<int> m_data;
    int front, rear, size, count;
public:
    MyCircularQueue(int k) : m_data(vector<int>(k)), front(-1), rear(-1), size(k), count(0) {

    }
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        front = front == -1 ? 0 : front;
        rear = (rear + 1) % size;
        m_data[rear] = value;
        count++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % size;
        count--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return m_data[front];
    }
    
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return m_data[rear];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
