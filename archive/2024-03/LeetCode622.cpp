//622. 设计循环队列
//设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。
//循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。
//你的实现应该支持如下操作：
//MyCircularQueue(k): 构造器，设置队列长度为 k 。
//Front: 从队首获取元素。如果队列为空，返回 -1 。
//Rear: 获取队尾元素。如果队列为空，返回 -1 。
//enQueue(value): 向循环队列插入一个元素。如果成功插入则返回真。
//deQueue(): 从循环队列中删除一个元素。如果成功删除则返回真。
//isEmpty(): 检查循环队列是否为空。
//isFull(): 检查循环队列是否已满。
//
//示例：
//MyCircularQueue circularQueue = new MyCircularQueue(3); // 设置长度为 3
//circularQueue.enQueue(1);  // 返回 true
//circularQueue.enQueue(2);  // 返回 true
//circularQueue.enQueue(3);  // 返回 true
//circularQueue.enQueue(4);  // 返回 false，队列已满
//circularQueue.Rear();  // 返回 3
//circularQueue.isFull();  // 返回 true
//circularQueue.deQueue();  // 返回 true
//circularQueue.enQueue(4);  // 返回 true
//circularQueue.Rear();  // 返回 4
//
//提示：
//所有的值都在 0 至 1000 的范围内；
//操作数将在 1 至 1000 的范围内；
//请不要使用内置的队列库。


//方法一：数组
//关于循环队列的概念可以参考：「循环队列」，我们可以通过一个数组进行模拟，通过操作数组的索引构建一个虚拟的首尾相连的环。在循环队列结构中，设置一个队尾 rear 与队首 front，且大小固定，结构如下图所示:
//在循环队列中，当队列为空，可知front=rear；而当所有队列空间全占满时，也有 front=rear。为了区别这两种情况，假设队列使用的数组有 capacity 个存储空间，则此时规定循环队列最多只能有capacity−1 个队列元素，当循环队列中只剩下一个空存储单元时，则表示队列已满。根据以上可知，队列判空的条件是 front=rear，而队列判满的条件是 front=(rear+1)  mod  capacity。
//对于一个固定大小的数组，只要知道队尾 rear 与队首 front，即可计算出队列当前的长度：
//(rear−front+capacity)  mod  capacity
//循环队列的属性如下:
//elements：一个固定大小的数组，用于保存循环队列的元素。
//capacity：循环队列的容量，即队列中最多可以容纳的元素数量。
//front：队列首元素对应的数组的索引。
//rear：队列尾元素对应的索引的下一个索引。
//循环队列的接口方法如下：
//
//MyCircularQueue(int k): 初始化队列，同时base 数组的空间初始化大小为 k+1。front,rear 全部初始化为 0。
//enQueue(int value)：在队列的尾部插入一个元素，并同时将队尾的索引 rear 更新为 (rear+1)  mod  capacity。
//deQueue()：从队首取出一个元素，并同时将队首的索引 front 更新为 (front+1)  mod  capacity。
//Front()：返回队首的元素，需要检测队列是否为空。
//Rear()：返回队尾的元素，需要检测队列是否为空。
//isEmpty()：检测队列是否为空，根据之前的定义只需判断 rear 是否等于 front。
//isFull()：检测队列是否已满，根据之前的定义只需判断 front 是否等于 (rear+1) mod  capacity。
//class MyCircularQueue {
//private:
//    int front;
//    int rear;
//    int capacity;
//    vector<int> elements;
//
//public:
//    MyCircularQueue(int k) {
//        this->capacity = k + 1;
//        this->elements = vector<int>(capacity);
//        rear = front = 0;
//    }
//
//    bool enQueue(int value) {
//        if (isFull()) {
//            return false;
//        }
//        elements[rear] = value;
//        rear = (rear + 1) % capacity;
//        return true;
//    }
//
//    bool deQueue() {
//        if (isEmpty()) {
//            return false;
//        }
//        front = (front + 1) % capacity;
//        return true;
//    }
//
//    int Front() {
//        if (isEmpty()) {
//            return -1;
//        }
//        return elements[front];
//    }
//
//    int Rear() {
//        if (isEmpty()) {
//            return -1;
//        }
//        return elements[(rear - 1 + capacity) % capacity];
//    }
//
//    bool isEmpty() {
//        return rear == front;
//    }
//
//    bool isFull() {
//        return ((rear + 1) % capacity) == front;
//    }
//};
//复杂度分析
//时间复杂度：初始化和每项操作的时间复杂度均为 O(1)。
//空间复杂度：O(k)，其中 k 为给定的队列元素数目。
//
//方法二：链表
//我们同样可以用链表实现队列，用链表实现队列则较为简单，因为链表可以在 O(1) 时间复杂度完成插入与删除。入队列时，将新的元素插入到链表的尾部；出队列时，将链表的头节点返回，并将头节点指向下一个节点。
//循环队列的属性如下:
//head：链表的头节点，队列的头节点。
//tail：链表的尾节点，队列的尾节点。
//capacity：队列的容量，即队列可以存储的最大元素数量。
//size：队列当前的元素的数量。
//class MyCircularQueue {
//private:
//    ListNode *head;
//    ListNode *tail;
//    int capacity;
//    int size;
//
//public:
//    MyCircularQueue(int k) {
//        this->capacity = k;
//        this->size = 0;
//        this->head = this->tail = nullptr;
//    }
//
//    bool enQueue(int value) {
//        if (isFull()) {
//            return false;
//        }
//        ListNode *node = new ListNode(value);
//        if (!head) {
//            head = tail = node;
//        } else {
//            tail->next = node;
//            tail = node;
//        }
//        size++;
//        return true;
//    }
//
//    bool deQueue() {
//        if (isEmpty()) {
//            return false;
//        }
//        ListNode *node = head;
//        head = head->next;  
//        size--;
//        delete node;
//        return true;
//    }
//
//    int Front() {
//        if (isEmpty()) {
//            return -1;
//        }
//        return head->val;
//    }
//
//    int Rear() {
//        if (isEmpty()) {
//            return -1;
//        }
//        return tail->val;
//    }
//
//    bool isEmpty() {
//        return size == 0;
//    }
//
//    bool isFull() {
//        return size == capacity;
//    }
//};
//复杂度分析
//时间复杂度：初始化和每项操作的时间复杂度均为 O(1)。
//空间复杂度：O(k)，其中 k 为给定的队列元素数目。
