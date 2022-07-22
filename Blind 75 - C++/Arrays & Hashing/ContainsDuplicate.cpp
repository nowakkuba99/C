#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> solution;
        for(int i = 0; i<nums.size(); i++)
        {
            if(solution.find(nums[i]) != solution.end())
                return true;
            else
                solution.insert(nums[i]);
        }
        return false;
    }
};