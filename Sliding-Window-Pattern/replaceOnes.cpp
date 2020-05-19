/*
 * Created Date: Monday, May 18th 2020, 11:13:15 am
 * Author: Kiran Babu Muddam
 
Problem Statement #
Given an array containing 0s and 1s, if you are allowed to replace no more than ‘k’ 0s with 1s, find the length of the longest contiguous subarray having all 1s.

Example 1:

Input: Array=[0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1], k=2
Output: 6
Explanation: Replace the '0' at index 5 and 8 to have the longest contiguous subarray of 1s having length 6.
Example 2:

Input: Array=[0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1], k=3
Output: 9
Explanation: Replace the '0' at index 6, 9, and 10 to have the longest contiguous subarray of 1s having length 9.

Time Complexity: O(n)
Space Complexity: O(1)
 */
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class replaceOnes{
    public:
    static int findMaxReplacementSubarrayOnesLength(vector<int> inputVector,int inputK){
        int windowStart=0,maxLength=0,maxOnes=0;
        unordered_map<char,int> charFrequencyMap;
        for(int windowEnd=0;windowEnd<inputVector.size();windowEnd++){
            if(inputVector[windowEnd]==1){
                maxOnes++;
            }
            if(windowEnd-windowStart+1-maxOnes>inputK){
                if(inputVector[windowStart]==1){
                    maxOnes--;
                }
                windowStart++;
            }
            maxLength = max(maxLength,windowEnd-windowStart+1);
        }
        return maxLength;
    }
};
int main(){
    cout<<replaceOnes::findMaxReplacementSubarrayOnesLength({0,1,1,0,1,0,0},3)<<endl;
    cout<<replaceOnes::findMaxReplacementSubarrayOnesLength({0,1,0,0},3)<<endl;
    cout<<replaceOnes::findMaxReplacementSubarrayOnesLength({{0,0,0,1,1,0,1,1,0,0,1}},3)<<endl;
    cout<<replaceOnes::findMaxReplacementSubarrayOnesLength({0,0,0},3)<<endl;
    cout<<replaceOnes::findMaxReplacementSubarrayOnesLength({0,1,1,0,1,0,0,1,0,1,1,1,1,1,1},3)<<endl;
    cout<<replaceOnes::findMaxReplacementSubarrayOnesLength({0,0,0,0,0},3)<<endl;
}
