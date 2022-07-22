#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string,vector<string>> result;
        for(int i=0;i<strs.size();i++)
        {
            vector<string> t;
            string key = get_key(strs[i]);
            result[key].push_back(strs[i]);
        }
        vector<vector<string>> ret;
        for (auto it = result.begin(); it != result.end(); it++) {
            ret.push_back(it->second);
        }
        return ret;

    }
private:
    string get_key(string word)
    {
        vector<int> set(26); //'a' -> 'z'
        for(int i=0;i<word.length();i++)
            set[word[i]-'a']++;
        string ret;
        for(int i=0;i<26;i++)
            ret+=set[i]*(i+'a');
        return ret;
    }
};
