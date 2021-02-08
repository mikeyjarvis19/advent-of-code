#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
	std::string outputString;
	std::ifstream fileContents("input.txt");
	std::vector <int> values;
	int expectedSum = 2020;
	while (std::getline(fileContents, outputString)) {
		int lineInt;
		lineInt = std::stoi(outputString);
		values.push_back(lineInt);
	}
	for (int i = 0; i < values.size(); i++) {
		std::vector <std::vector<int>> possibleSums;
		for (int j = i + 1; j < values.size(); j++) {
			possibleSums.push_back({ values.at(i), values.at(j), values.at(i) + values.at(j) });
		}
		for (int i = 0; i < possibleSums.size(); i++) {
			std::vector <int> inputsAndSum = possibleSums.at(i);
			if (inputsAndSum.at(2) == expectedSum) {
				int multiplyResult = inputsAndSum.at(0) * inputsAndSum.at(1);
				std::cout << multiplyResult;
			}
		}
	}
}

/*
Notes about improvements:
* Not using pointers at all, so probably duping a bunch of stuff in memory.
* Should probably be using const in places where I don't expect values to be changed.
* This is a brute force method, could probably achieve something much more efficient if I:
	* Sort the input values into ascending order.
	* Implement some kind of Quicksort approach (except evaluating on sum of i + j).
		* If sum is < 2020, pick value half way between end of sorted array and j, find sum.
		* If sum is > 2020, pick value half way between start of sorted array and j, find sum.
		* Continue until sum == 2020 OR we know there's no possible pair involving i that sums to 2020.
		* This would allow me to avoid summing all possible pairs.
*/