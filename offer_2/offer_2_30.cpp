/*
@File  :offer_2_30.cpp
@Author:dfc
@Date  :2023/4/12  11:44
@Desc  :
*/
#include "unordered_set"
#include "vector"
#include "iostream"
#include "cstdlib"
#include "unordered_map"
using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int,int>my_map;
    vector<int> nums;
    int index = 0;
    RandomizedSet() {
        unsigned seed;

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (my_map.find(val) == my_map.end())
        {
            my_map[val] = index;
            nums.push_back(val);
            index++;
            return true;
        }
        else return false;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (my_map.find(val) != my_map.end())
        {
            int delete_index= my_map[val];
            int back_index = index-1;
            my_map[nums[back_index]] = delete_index;
            swap(nums[delete_index],nums[back_index]);
            nums.pop_back();
            my_map.erase(val);
            index--;
            return true;
        }
        else return false;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int num = rand() % my_map.size();
        return nums[num];
    }
};