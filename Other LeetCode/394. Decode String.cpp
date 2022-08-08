#include <string>
#include <math.h>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
        return decodeSubstring(s,1);
    }
private:
    string decodeSubstring(string s, int k)
    {
        int countBraces=0,it=0,num=0;
        string curr="",result="",resultTimesK="";
        string number="";
        while(it < s.length())
        {
            //If it is a number
            if(isADigit(s[it]))
            {
                number="";
                while(isADigit(s[it]))
                {
                    number+=s[it];
                    it++;
                }
                num = decodeNumber(number);
                //Find the beging and end of braces ([ and ])
                curr="";
                while(it < s.length())
                {
                    if(s[it] == '[')
                    {
                        countBraces++;
                        if(countBraces>1)   //If there is more bracets inside add them to curr as well
                        {
                            curr+=s[it];
                        }
                    }
                    else if (s[it] == ']')
                    {
                        countBraces--;
                        if(countBraces == 0)
                        {
                            //Send to the function
                            curr = decodeSubstring(curr,num);       //Recevie substring 
                            it++;                                   //Move iterator to next char
                            break;
                        }
                        else
                        {
                            curr+=s[it];            //If this is internal closing, add it to curr
                        }
                    }
                    else
                    {
                        curr+=s[it];                //Add to curr - to be decoded
                    }
                    it++;
                }
                result+=curr;
                curr="";
            }
            else
            {
                result+=s[it];
                it++;
            }
        }
        //Duplicate k times
        for(int i = 0;i<k;i++)
        {
            resultTimesK+=result;
        }
        return resultTimesK;
    }
    int decodeNumber(string s)      //Decode number from string
    {
        int result=0;
        int power = s.length()-1;
        for(auto const& ch: s)
        {
            result += (ch-'0')*pow(10,power);
            power--;
        }
        return result;
    }
    bool isADigit(char ch)          //Check if it is a digit
    {
        if(ch >='0' && ch <='9')
            return true;
        return false;
    }
};