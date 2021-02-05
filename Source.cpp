#include <iostream>;
#include <fstream>
#include <string>

int main() {
	std::string outputString;
	std::ifstream MyReadFile("input.txt");
	while (std::getline(MyReadFile, outputString)) {
		// Output the text from the file
		std::cout << outputString << "\n";
	}
	std::cout << "test";
}