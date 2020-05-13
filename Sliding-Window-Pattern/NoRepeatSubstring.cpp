#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
class NoRepeatSubstring {
    public:
    static  int findLength(const string& str){
        int windowStart = 0, maxLength =0;
        unordered_map<char, int> charIndexMap;
        for(int windowEnd =0;windowEnd < str.length();windowEnd++){
            char rightChar = str[windowEnd];
            if (charIndexMap.find(rightChar)!=charIndexMap.end()){
                windowStart = max(windowStart, charIndexMap[rightChar]+1);
            }
            charIndexMap[rightChar]=windowEnd;
            maxLength = max(maxLength,windowEnd- windowStart +1);
        }
        return maxLength;
    }
};
int main(int argc, char* argv[]){
    cout<<"Length of the longeset substring:"<<NoRepeatSubstring::findLength("aarchiarionpqabcdiopq");
}
