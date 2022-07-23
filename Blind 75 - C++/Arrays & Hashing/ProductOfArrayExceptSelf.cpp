#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n,1);

        for(int i=1;i<n;i++)
        {
            result[i] = result[i-1] * nums[i-1];
        }
        int helping = nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            result[i] *= helping;
            helping *= nums[i];
        }
        return result;
    }
};