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
Time Complexity : 
Space Complexity : 
 * 
 */
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
class LongestSubstringKDistinct{
    public:
    int findLongestSubstringKDistinct(string inputString,int inputK){
        unordered_map<char,int> visited;
        int windowStart=0,windowEnd=0,longestSubstringSize=0,currentSubstringSize=0;
        int currentUniqueSubstringSize=0;
        for(int windowEnd=0;windowEnd<inputString.size();windowEnd++){
            if(visited.find(inputString[windowEnd])==visited.end()){
                ++currentSubstringSize;
                ++currentUniqueSubstringSize;
                visited[inputString[windowEnd]]=1;
                //cout<<visited[inputString[windowEnd]]<<endl;
                }
            else{
                ++currentSubstringSize;
                visited[inputString[windowEnd]]=visited[inputString[windowEnd]]+1;
                }
            while(currentUniqueSubstringSize>inputK){
                longestSubstringSize = max(longestSubstringSize,currentSubstringSize-1);
                if((visited[inputString[windowStart]]) > 1){
                    --currentSubstringSize;
                    visited[inputString[windowStart]]=visited[inputString[windowStart]]-1;

                }
                else{
                    --currentSubstringSize;
                    --currentUniqueSubstringSize;
                }
                ++windowStart;
            }
            longestSubstringSize = max(longestSubstringSize,currentSubstringSize);

        }
        return longestSubstringSize;
    }
};
int main(){
    LongestSubstringKDistinct solution;
    //cout<<solution.findLongestSubstringKDistinct("aaraci",2)<<endl;
    //cout<<solution.findLongestSubstringKDistinct("aaaasdwwwewasd",7)<<endl;
    cout<<solution.findLongestSubstringKDistinct("sooslabcdsooow",3)<<endl;

}