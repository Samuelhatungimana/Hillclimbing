#include <iostream>
#include <string>
#include <ctime>
#include <vector>

using namespace std;
const string target="samuel";
const string searchSpace="abcdefghijklmnopqrstuvwxyz";

// finding the number of matching letters 
int fitness(const string& s) {
	int score = 0;
	for (size_t i = 0; i < s.size(); i++) {
		if (s[i] == target[i]) {
			score++;
		}
	}
	return score;
}
//Generating a random string of samelength as a target 

string randomString() {
	string s = " ";
	for (size_t i = 0; i < target.size() - 1; i++) {
		s += searchSpace[rand() % searchSpace.size()];
	}
	return s;
}

// mutate oneletter randomly to get the next string 

string mutate(const string& s) {
	string newString = s;
	int index = rand() % s.size();
	newString[index] = searchSpace[rand() % searchSpace.size()];
	return newString;
}

int main() {
	srand(time(0));
	

	string currentString = randomString();
	int currentFitness = fitness(currentString);
	int iteration = 0;

	while (currentString != target) {
		string newString = mutate(currentString);
		int newFitness = fitness(newString);
		if (newFitness >= currentFitness) {
			currentString = newString;
			currentFitness = newFitness;
		}
		iteration++;
		cout << "***Number of iteration: " << iteration << "| String: " << currentString << " | Fitness: " << currentFitness << endl;
	}
	cout << "** Target mached: " << currentString << endl;

	return 0;

}