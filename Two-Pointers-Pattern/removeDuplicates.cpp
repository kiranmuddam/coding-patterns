#include<iostream>
#include<vector>

using namespace std;

class removeDuplicates {
	public:
	static int finalLength(vector<int> &arr) {
		int nonDuplicatePointer = 0;
		for (int i = 0; i < arr.size(); i++) {
			if (arr[nonDuplicatePointer] != arr[i + 1]) {
				arr[nonDuplicatePointer + 1] = arr[i + 1];
				nonDuplicatePointer++;
			}
		}
		return nonDuplicatePointer;
	}
};

int main (int argc, char *argv[]) {
	vector<int> arr = {1,2,3,3,4,4,5,6,6,7,7,7,7};
	cout<<removeDuplicates::finalLength(arr)<<endl;
	arr = {1,2,3,4,5,6,7,8,9,10,10,10,10,10,10,10};
	cout<<removeDuplicates::finalLength(arr)<<endl;
}
