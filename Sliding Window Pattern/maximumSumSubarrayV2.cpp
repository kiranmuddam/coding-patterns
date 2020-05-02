/* Created Date: Saturday, May 2nd 2020, 9:50:15 am
 * Author: Kiran Babu Muddam
 */
/* 
Pattern - Sliding Window Version 2 Optimized
Problem Statement #
Given an array of positive numbers and a positive number ‘k’, find the maximum sum of any contiguous subarray of size ‘k’.

Example 1:

Input: [2, 1, 5, 1, 3, 2], k=3 
Output: 9
Explanation: Subarray with maximum sum is [5, 1, 3].
Example 2:

Input: [2, 3, 4, 1, 5], k=2 
Output: 7
Explanation: Subarray with maximum sum is [3, 4].
Time Complexity - O(n)
Space Complexity - O(n)
 */
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> intArray;
    int k=10;
    int maxSubarraySum =0,firstIndex=-1,lastIndex=-1;
    //Populating array with 1-10 integers
    for(int i=1;i<=100;i++){ 
        intArray.push_back(i);
    }
    //Calculate first sum
    int firstElement;
    double subarraySum=0;
    double subarrayAvg=0;
    for(int i=0;i<k;i++){
        subarraySum = subarraySum + intArray[i];
    }
    firstElement = intArray[0];
    for(int i=1;i+k<=intArray.size();i++){
        subarraySum = subarraySum - firstElement;
        subarraySum = subarraySum + intArray[i+k-1];
        firstElement = intArray[i];
        if(subarraySum>maxSubarraySum){
            maxSubarraySum = subarraySum;
            firstIndex = i;
            lastIndex = i+k;
        }
        }
   vector<int>::const_iterator first = intArray.begin() + firstIndex;
    vector<int>::const_iterator last = intArray.begin() + lastIndex;
    vector<int> maxSumSubArray(first, last);
    cout<<"The subarray with max sum is :"<<endl;
    for(int i=0;i<maxSumSubArray.size();i++){
        cout<<maxSumSubArray[i]<<" ";
    }
}
