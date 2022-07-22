#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> map(26);
        if(s.size()!=t.size())
            return false;
        for(int i=0; i<s.size() ;i++)
        {
            map[s[i]-97]++;
            
        }
        for(int i=0; i<t.size();i++)
        {
            map[t[i]-97]--;
            if(map[t[i]-97]<0)
                return false;
        }
        return true;
    }
};