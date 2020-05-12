/*
 * Created Date: Tuesday, May 12th 2020, 11:29:05 am
 * Author: Kiran Babu Muddam
 
Problem Statement #
Given a string, find the length of the longest substring which has no repeating characters.

Example 1:

Input: String="aabccbb"
Output: 3
Explanation: The longest substring without any repeating characters is "abc".
Example 2:

Input: String="abbbb"
Output: 2
Explanation: The longest substring without any repeating characters is "ab".
Example 3:

Input: String="abccde"
Output: 3
Explanation: Longest substrings without any repeating characters are "abc" & "cde".

Time Complexity : 
Spacec complexity:
 */
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
class LongestDistinctSubstring{
    public:
    int findLongesetDistinctSubsting(string inputString){
        int  windowEnd=0, maxStringLength=0, currentWindowLength=0;
        unordered_map<char,int> charFrequencyMap;
        for(windowEnd=0;windowEnd<inputString.size();++windowEnd){
            char currentChar = inputString[windowEnd];
            if(charFrequencyMap.find(currentChar)==charFrequencyMap.end()){
                charFrequencyMap[currentChar]=windowEnd;
                ++currentWindowLength;
            }
            else if(charFrequencyMap[currentChar] and (windowEnd-charFrequencyMap[currentChar] < currentWindowLength)){
                maxStringLength = max(maxStringLength, currentWindowLength);
                currentWindowLength = windowEnd - charFrequencyMap[currentChar];
                charFrequencyMap[currentChar]=windowEnd;
            }
        }
        maxStringLength = max(maxStringLength, currentWindowLength);
        return maxStringLength;
    }

};
int main(){
    LongestDistinctSubstring myString;
    cout<<myString.findLongesetDistinctSubsting("kiranbabumuddam")<<endl;
    cout<<myString.findLongesetDistinctSubsting("aabccbb")<<endl;
    cout<<myString.findLongesetDistinctSubsting("abbbb")<<endl;
    cout<<myString.findLongesetDistinctSubsting("abccde")<<endl;
    cout<<myString.findLongesetDistinctSubsting("abcdabcdefghijklabcdesllsqwertyuioop")<<endl;
    cout<<myString.findLongesetDistinctSubsting("abccde")<<endl;
}
