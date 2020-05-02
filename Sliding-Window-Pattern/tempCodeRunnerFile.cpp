/*
 * Created Date: Saturday, May 2nd 2020, 9:09:02 am
 * Author: Kiran Babu Muddam
 */

/* Pattern - Sliding Window
   Problem - Given an array, find the average of all contiguous subarrays of size ‘K’ in it
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
