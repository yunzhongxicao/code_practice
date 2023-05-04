/*
@File  :priority_queue.cpp
@Author:dfc
@Date  :2023/5/3  21:09
@Desc  :
*/
#include "iostream"
#include "vector"

using namespace std;

class priorityQueue
{
private:
    vector<int> nums={-1};
public:
    void push(int x);
    void pop();
    int get_head();
    void move_down(int hole);
    priorityQueue(const  vector<int>&items);
    priorityQueue()= default;;
};

void priorityQueue::push(int x) {
    nums.push_back(x); // 先满足结构性
    int hole = nums.size()-1;
    while (hole>1 and nums[hole/2]>nums[hole])
    {
        swap(nums[hole/2],nums[hole]);
        hole = hole/2;
    }
}

void priorityQueue::pop() {
    nums[1] = nums.back();
    nums.pop_back();
    move_down(1);
}

void priorityQueue::move_down(int hole) { // 将索引位hole的节点向下过滤到应该的位置
    int child;
    while (hole*2<=nums.size()-1) // hole*2 是左孩子
    {
        child = hole *2;
        if (child+1<= nums.size()-1 and nums[child+1]<nums[child])
            child++;
        if (nums[hole]>nums[child])
        {
            swap(nums[hole],nums[child]);
            hole = child;
        }
        else break;
    }
}

priorityQueue::priorityQueue(const vector<int> &items) {
    for (int i = 0; i < items.size(); ++i) {
        nums.push_back(items[i]);
    }
    for (int i = (nums.size()-1)/2; i >=1 ; --i) {
        move_down(i);
    }
}

int priorityQueue::get_head() {
    return nums[1];
}

void sort_heap(vector<int> &nums)
{
    priorityQueue *p_queue = new priorityQueue(nums);
    for (int i = 0; i < nums.size(); ++i) {
        nums[i] = p_queue->get_head();
        p_queue->pop();
    }
}

int main()
{
    priorityQueue *obj = new priorityQueue();
    obj->push(2);
    obj->push(3);
    obj->push(4);
    obj->push(5);
    obj->push(7);
    obj->push(10);
    obj->push(23);
    obj->push(29);
    obj->push(60);
    obj->push(1);
    obj->pop();
    obj->pop();

    vector<int> items = {1,3,4,3,2,5,1,0};
    priorityQueue * obj2 = new priorityQueue(items);
    obj2->push(2);
    obj2->pop();

    sort_heap(items);
    for (int i = 0; i < items.size(); ++i) {
        cout<<items[i]<<" ";
    }

}