#include<iostream>
#include<vector>

using namespace std;

class pairWithTargetSum {
	public:
	static pair<int,int> search(vector<int> &arr, int targetSum) {
	int firstPointer = 0;
	int secondPointer = arr.size() - 1;
	while (firstPointer < secondPointer) {
		int currentSum = arr[firstPointer] + arr[secondPointer];
		if ( currentSum == targetSum) {
			return make_pair(firstPointer, secondPointer);
		} else if (currentSum > targetSum) {
			secondPointer--;
		} else {
			firstPointer--;
		}
	}
	return make_pair(-1, -1);
	} 
};

int main(int argc, char *argv[]) {
	vector<int> arr = {1,2,3,4,5,6,9};
	auto result = pairWithTargetSum::search(arr, 7);
	cout<< result.first << ":" << result.second <<endl;
	result = pairWithTargetSum::search(arr, 10);
	cout<< result.first << ":" << result.second <<endl;
	result = pairWithTargetSum::search(arr, 20);
	cout<< result.first << ":" << result.second <<endl;
}
