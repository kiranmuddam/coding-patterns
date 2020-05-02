/* Created Date: Saturday, May 2nd 2020, 9:29:05 am
 * Author: Kiran Babu Muddam
 */

/* Pattern - Sliding Window Version 2 Optimized
   Problem - Given an array, find the average of all contiguous subarrays of size ‘K’ in it.
   Optimization: Remove common elements iteration while sliding windows in the array.
   Time Complexity - O(n)
   Space Complexity - O(n)
 */
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> intArray,avgArray;
    int k=10;
    //Populating array with 1-10 integers
    for(int i=1;i<=100;i++){ 
        intArray.push_back(i);
    }
    //Calculate first sum
    int firstElement,subarrayAvg=0;
    for(int i=0;i<k;i++){
        subarrayAvg = subarrayAvg + intArray[i];
    }
    avgArray.push_back(subarrayAvg);
    firstElement = intArray[0];
    for(int i=1;i+k<=intArray.size();i++){
        subarrayAvg = subarrayAvg - firstElement;
        subarrayAvg = subarrayAvg + intArray[i+k-1];
        firstElement = intArray[i];
        avgArray.push_back(subarrayAvg);
    }
    cout<<"The Array with contiguous subarrays averages:"<<endl;
    for(int i=0;i<avgArray.size();i++){
        cout<<avgArray[i]<<" ";
    }
}
