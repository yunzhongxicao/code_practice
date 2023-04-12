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
using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_set<int> my_set;
    RandomizedSet() {
        unsigned seed;
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (my_set.find(val) == my_set.end())
        {
            my_set.emplace(val);
            return true;
        }
        else return false;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (my_set.find(val) != my_set.end())
        {
            my_set.erase(val);
            return true;
        }
        else return false;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int index = rand() % my_set.size();
        auto iter = my_set.begin();
        
    }
};