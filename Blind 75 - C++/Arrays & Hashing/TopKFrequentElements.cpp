#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mapa;
        for(int i=0;i<nums.size();i++)
        {
            mapa[nums[i]]++;
        }
        vector<vector<int>> freq(nums.size());
        for(auto it = mapa.begin();it != mapa.end();it++)
            freq[it->second].push_back(it->first);
        vector<int> result;
        for(int i=freq.size()-1;i>0;i--)
        {
            for(int j=0;j<freq[i].size();j++)
                result.push_back(freq[i][j]);
            if(result.size() == k)
                return result;
        }
    }
};

/*
    Second way -> Bucket Sort
*/

class Solution2 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mapa;
        for(int i=0;i<nums.size();i++)
        {
            mapa[nums[i]]++;
        }
        vector<vector<int>> freq(nums.size()+1);
        for(auto it = mapa.begin();it != mapa.end();it++)
            freq[it->second].push_back(it->first);
        vector<int> result;
        for(int i=freq.size()-1;i>0;i--)
        {
            for(int j=0;j<freq[i].size();j++)
                result.push_back(freq[i][j]);
            if(result.size() == k)
                return result;
        }
        return result;
    }
};