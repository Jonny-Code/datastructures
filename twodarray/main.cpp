#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

const int LIST_SIZE = 4;
const int YES_INDEX = 0;
const int NO_INDEX = 1;

int getFoodIndex(string *foods, string food) {
	for(int i = 0; i < LIST_SIZE; i++) {
		if(*(foods + i) == "") {
			*(foods + i) = food;
			return i;
		}
		else if(*(foods + i) == food) {
			return i;
		}
	}

	return -1;
}

int main() {
	ifstream inputFile;
	inputFile.open("cafeteria.txt");

	if(!inputFile) cout << "Error opening file!" << endl;

	string line;
	string foods[LIST_SIZE] = {"", "", "", ""};
	int results[LIST_SIZE][2] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};

	while(getline(inputFile, line)) {
		string food;
		string like;
		istringstream iss(line);

		getline(iss, food, '\t');
		getline(iss, like, '\t');

		int i = getFoodIndex(foods, food);

		if(like.find("Y") == 0) results[i][YES_INDEX]++;
		else results[i][NO_INDEX]++;
	}

	cout << "Food Item" << "\t" << "Like" << "\t" << "Dislike" << endl;

	for(int i = 0; i < LIST_SIZE; i++)
		cout << foods[i] << "\t" << results[i][YES_INDEX] << "\t" << results[i][NO_INDEX] << endl;

	inputFile.close();

	return 0;
}