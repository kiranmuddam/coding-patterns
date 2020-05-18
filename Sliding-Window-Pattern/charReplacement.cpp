/*
 * Created Date: Monday, May 18th 2020, 10:41:32 am
 * Author: Kiran Babu Muddam
 Problem Statement #
Given a string with lowercase letters only, if you are allowed to replace no more than ‘k’ letters with any letter, find the length of the longest substring having the same letters after replacement.

Example 1:

Input: String="aabccbb", k=2
Output: 5
Explanation: Replace the two 'c' with 'b' to have a longest repeating substring "bbbbb".
Example 2:

Input: String="abbcb", k=1
Output: 4
Explanation: Replace the 'c' with 'b' to have a longest repeating substring "bbbb".
Example 3:

Input: String="abccde", k=1
Output: 3
Explanation: Replace the 'b' or 'd' with 'c' to have the longest repeating substring "ccc".
 */
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
class charReplacement{
    public:
    static int findMaxReplacementSubstringLenght(string inputStr,int inputK){
        int windowStart=0,maxLength=0,maxRepeatingCharLen=0;
        unordered_map<char,int> charFrequencyMap;
        for(int windowEnd=0;windowEnd<inputStr.size();windowEnd++){
            char forwardChar = inputStr[windowEnd];
            charFrequencyMap[forwardChar]++;
            maxRepeatingCharLen = max(maxRepeatingCharLen,charFrequencyMap[forwardChar]);
            if(windowEnd-windowStart+1-maxRepeatingCharLen>inputK){
                char backwardChar = charFrequencyMap[windowStart];
                charFrequencyMap[backwardChar]--;
                windowStart++;
            }
            maxLength = max(maxLength,windowEnd-windowStart+1);
        }
        return maxLength;
    }
};
int main(){
    cout<<charReplacement::findMaxReplacementSubstringLenght("kiranbabumuddam",3)<<endl;
    cout<<charReplacement::findMaxReplacementSubstringLenght("abcdaaaaaaaaaaa",4)<<endl;
    cout<<charReplacement::findMaxReplacementSubstringLenght("abccde",1)<<endl;
    cout<<charReplacement::findMaxReplacementSubstringLenght("abbcb",1)<<endl;
    cout<<charReplacement::findMaxReplacementSubstringLenght("aaaaabbbbb",0)<<endl;
}
