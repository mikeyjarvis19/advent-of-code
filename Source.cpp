#include <iostream>;
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