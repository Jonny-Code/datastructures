#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

template <class T>
T min(vector<T> list) {
	sort(list.begin(), list.end());
	return list.front();
}

template <class T>
T max(vector<T> list) {
	sort(list.begin(), list.end());
	return list.back();
}

int main() {
	ifstream inputFile;
	inputFile.open("minmax.txt");

	if(!inputFile) cout << "Error opening file!" << endl;

	string line;
	vector<int> numbers;
	vector<string> words;

	while(inputFile >> line) {
		try {
			numbers.push_back(stoi(line));
		}
		catch(invalid_argument &e) {
			words.push_back(line);
		}
	}

	cout << "Numbers min: " << min(numbers) << endl;
	cout << "Numbers max: " << max(numbers) << endl;
	cout << "Words min: " << min(words) << endl;
	cout << "Words max: " << max(words) << endl;

	return 0;
}