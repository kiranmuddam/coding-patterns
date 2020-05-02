/* Created Date: Saturday, May 2nd 2020, 9:50:15 am
 * Author: Kiran Babu Muddam
 */
/* 
Pattern - Sliding Window
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
Time Complexity - O(n*k)
Space Complexity - O(n)
 */
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> intArray,avgArray;
    int k=5;
    //Populating array with 1-10 integers
    for(int i=1;i<=10;i++){ 
        intArray.push_back(i);
    }
    for(int i=0;i+k<=intArray.size();i++){
        int counter=0,subarrayAvg=0;
        for(int j=i;counter<5;j++){
            subarrayAvg=subarrayAvg+intArray[j];
            counter=counter+1;
        }
        avgArray.push_back(subarrayAvg);
    }
    cout<<"The Array with contiguous subarrays averages:"<<endl;
    for(int i=0;i<avgArray.size();i++){
        cout<<avgArray[i]<<" ";
    }
}
