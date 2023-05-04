/*
@File  :offer_2_059.cpp
@Author:dfc
@Date  :2023/5/4  10:51
@Desc  :
*/
#include "iostream"
#include "vector"
using namespace std;

class priorityQueue{
private:
    vector<int>  nums = {-1};
public:
    priorityQueue(){};
    priorityQueue(const vector<int>&items)
    {
        for (int i = 0; i < items.size(); ++i) {
            nums.push_back(items[i]);
        }
        for (int i = (nums.size()-1) /2 ; i >=1 ; --i) {
            move_down(i);
        }
    }
    void push(int val)
    {
        nums.push_back(val);
        int hole = nums.size()-1;
        while (hole>1 and nums[hole/2]>nums[hole])
        {
            swap(nums[hole/2],nums[hole]);
            hole = hole/2;
        }
    }
    void move_down(int hole)
    {
        int child;
        while (hole * 2 <=nums.size()-1) // 保证要有孩子 至少要有左子
        {
            child = hole *2;
            if (child+1<=nums.size()-1 and nums[child+1]<nums[child])
                child++;
            if (nums[hole]>nums[child])
            {
                swap(nums[hole],nums[child]);
                hole = child;
            }
            else
                break;
        }
    }
    void pop()
    {
        nums[1] = nums.back();
        nums.pop_back();
        move_down(1);
    }
    int get_size()
    {
        return nums.size()-1;
    }
    int get_head()
    {
        return nums[1];
    }
};

class KthLargest {
public:
    priorityQueue *p_queue;
    int _k;
    KthLargest(int k, vector<int>& nums) {
        _k = k;
        p_queue = new priorityQueue(nums);
        while (p_queue->get_size()>k)
        {
            p_queue->pop();
        }
    }

    int add(int val) {
        p_queue->push(val);
        if (p_queue->get_size()>_k)
            p_queue->pop();
        return p_queue->get_head();
    }
};

