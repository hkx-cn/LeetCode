#pragma once
class ParkingSystem {
private:
    int m_big, m_medium, m_small, c_big, c_medium, c_small;

public:
    ParkingSystem(int big, int medium, int small) : m_big(big), m_medium(medium), m_small(small), c_big(0), c_medium(0), c_small(0) {
        
    }
    
    bool addCar(int carType) {
        switch (carType){
            case 1:
                if (c_big + 1 <= m_big) {
                    c_big++;
                    return true;
                }
                break;
            case 2:
                if (c_medium + 1 <= m_medium) {
                    c_medium++;
                    return true;
                }
                break;
            case 3:
                if (c_small + 1 <= m_small) {
                    c_small++;
                    return true;
                }
                break;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
//方法一：模拟
//思路与算法
//为每种车维护一个计数器，初始值为车位的数目。此后，每来一辆车，就将对应类型的计数器减 1。当计数器为 0 时，说明车位已满。
//class ParkingSystem {
//public:
//    int b, m, s;
//    ParkingSystem(int big, int medium, int small): b(big), m(medium), s(small) {}
//    
//    bool addCar(int carType) {
//        if (carType == 1) {
//            if (b > 0) {
//                b--;
//                return true;
//            }
//        } else if (carType == 2) {
//            if (m > 0) {
//                m--;
//                return true;
//            }
//        } else if (carType == 3) {
//            if (s > 0) {
//                s--;
//                return true;
//            }
//        }
//        return false;
//    }
//};
//时间复杂度
//时间复杂度：单次操作为 O(1)。
//空间复杂度：O(1)。
