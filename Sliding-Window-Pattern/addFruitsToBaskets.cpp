/*
 * Created Date: Tuesday, May 12th 2020, 10:54:46 am
 * Author: Kiran Babu Muddam

 * Problem Statement #
Given an array of characters where each character represents a fruit tree, you are given two baskets and your goal is to put maximum number of fruits in each basket. The only restriction is that each basket can have only one type of fruit.

You can start with any tree, but once you have started you can’t skip a tree. You will pick one fruit from each tree until you cannot, i.e., you will stop when you have to pick from a third fruit type.

Write a function to return the maximum number of fruits in both the baskets.

Example 1:

Input: Fruit=['A', 'B', 'C', 'A', 'C']
Output: 3
Explanation: We can put 2 'C' in one basket and one 'A' in the other from the subarray ['C', 'A', 'C']
Example 2:

Input: Fruit=['A', 'B', 'C', 'B', 'B', 'C']
Output: 5
Explanation: We can put 3 'B' in one basket and two 'C' in the other basket. 
This can be done if we start with the second letter: ['B', 'C', 'B', 'B', 'C']

Time Complexity: O(n+n) ==> O(n)
Space Complexity: O(K+1) ==> o(K)
 */
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class addFruitsToBaskets{
    public:
    int findMaxFruitsToBaskets(vector<int> inputFruits){
        unordered_map<char,int> fruitFrequencyMap;
        int windowStart=0, windowEnd=0, maxFruits=0;
        for(windowEnd=0;windowEnd<inputFruits.size();++windowEnd){
            char rightChar = inputFruits[windowEnd];
            fruitFrequencyMap[rightChar]++;
        while((int)fruitFrequencyMap.size()>2){
            char leftChar = inputFruits[windowStart];
            fruitFrequencyMap[leftChar]--;
            if(fruitFrequencyMap[leftChar]==0){
                fruitFrequencyMap.erase(leftChar);
            }
            windowStart++;
        }
        maxFruits = max(maxFruits , windowEnd-windowStart+1);
        }
        return maxFruits;
    }
};
int main(){
    addFruitsToBaskets myBasket;
    cout<<myBasket.findMaxFruitsToBaskets({'A', 'B', 'C', 'B', 'B', 'C'})<<endl;
    cout<<myBasket.findMaxFruitsToBaskets({'A', 'B', 'C', 'A', 'C'})<<endl;
    cout<<myBasket.findMaxFruitsToBaskets({})<<endl;
}
