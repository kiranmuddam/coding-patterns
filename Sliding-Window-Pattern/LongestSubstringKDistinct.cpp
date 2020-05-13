/*
 * Created Date: Thursday, May 7th 2020, 12:44:53 pm
 * Author: Kiran Babu Muddam
Problem Statement #
Given a string, find the length of the longest substring in it with no more than K distinct characters.

Example 1:

Input: String="araaci", K=2
Output: 4
Explanation: The longest substring with no more than '2' distinct characters is "araa".
Example 2:

Input: String="araaci", K=1
Output: 2
Explanation: The longest substring with no more than '1' distinct characters is "aa".
Example 3:

Input: String="cbbebi", K=3
Output: 5
Explanation: The longest substrings with no more than '3' distinct characters are "cbbeb" & "bbebi".
Time Complexity : O(n+n)
Space Complexity : O(K+1)
 * 
 */
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
class LongestSubstringKDistinct{
    public:
    int findLongestSubstringKDistinct(string inputString,int inputK){
        unordered_map<char,int> charFrequencyMap;
        int windowStart=0,windowEnd=0,maxLength=0;
        for(windowEnd=0;windowEnd<inputString.size();++windowEnd){
            char rightCharacter= inputString[windowEnd];
            charFrequencyMap[rightCharacter]++;
            while(charFrequencyMap.size()>inputK){
                char leftCharacter = inputString[windowStart];
                charFrequencyMap[leftCharacter]--;
                if(charFrequencyMap[leftCharacter]==0){
                    charFrequencyMap.erase(leftCharacter);
                }
                windowStart++;
            }
            maxLength = max(maxLength,windowEnd-windowStart + 1);
        }
        return maxLength;
    }
};
int main(){
    LongestSubstringKDistinct solution;
    cout<<solution.findLongestSubstringKDistinct("aaraci",2)<<endl;
    cout<<solution.findLongestSubstringKDistinct("aaaasdwwwewasd",7)<<endl;
    cout<<solution.findLongestSubstringKDistinct("sooslabcdsooow",3)<<endl;
}