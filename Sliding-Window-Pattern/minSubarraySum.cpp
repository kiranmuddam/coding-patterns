/*
 * Created Date: Saturday, May 2nd 2020, 11:14:55 am
 * Author: Kiran Babu Muddam
 
Problem Statement #
Given an array of positive numbers and a positive number ‘S’, find the length of the smallest contiguous subarray whose sum is greater than or equal to ‘S’. Return 0, if no such subarray exists.

Example 1:

Input: [2, 1, 5, 2, 3, 2], S=7 
Output: 2
Explanation: The smallest subarray with a sum great than or equal to '7' is [5, 2].
Example 2:

Input: [2, 1, 5, 2, 8], S=7 
Output: 1
Explanation: The smallest subarray with a sum greater than or equal to '7' is [8].
Example 3:

Input: [3, 4, 1, 1, 6], S=8 
Output: 3
Explanation: Smallest subarrays with a sum greater than or equal to '8' are [3, 4, 1] or [1, 1, 6].

Time Complexity : O(N+N)
Space Complexity : O(1)
 * 
 */
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
class minSubarraySum{
    public:
    int findMinSubarraySum(vector<int> inputVector,int inputSum){
        int windowStart=0,windowEnd=0,arraySum=0,minSumSubarraySize=INT_MAX;
        for(int i=windowStart;i<inputVector.size();i++){
            arraySum=arraySum+inputVector[i];
            windowEnd = i;
            while(arraySum>=inputSum){
                minSumSubarraySize=min(minSumSubarraySize,windowEnd-windowStart+1);
                arraySum=arraySum-inputVector[windowStart];
                windowStart=windowStart+1;
            }
        }
        return minSumSubarraySize;
    }
};
int main(){
    minSubarraySum solution;
    cout<<solution.findMinSubarraySum({1,5,6,1,6,3,5,3,7},7)<<endl;
    cout<<solution.findMinSubarraySum({1,5,6,1,6,3,5,3},7)<<endl;
    cout<<solution.findMinSubarraySum({1,1,2,1,1,1},7)<<endl;
    cout<<solution.findMinSubarraySum({3,4,1,1,6},8)<<endl;

}