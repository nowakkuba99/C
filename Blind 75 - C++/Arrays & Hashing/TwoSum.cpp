#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        vector<int> result;
        int diff = 0;
        for(int i=0;i<nums.size();i++)
        {
            diff = target - nums[i];
            if(map.find(diff) != map.end())
            {
                result.push_back(i);
                result.push_back(map[diff]);
            }
            else
            {
                map.insert({nums[i],i});
            }
        }
        return result;
    }
};