#include <cwchar>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

bool sortByVal(const std::pair<char, std::vector<int>> &a, const std::pair<char, std::vector<int>> &b) { return (a.second < b.second); }

int main() {
	//map is easiest to store this data in
	std::map<char, std::vector<int>> newMap;
	//get input
	std::string input;
	std::cin >> input;
	//add characters, freqind= {frequency, index}
	for(int i = 0; i < input.length(); ++i)
	{
		if(newMap.find(input[i]) == newMap.end()) 
		{ 
			newMap.insert({input[i], {0, i}}); 
		}
		else { newMap[input[i]].at(0) ++; }
	}
	//convert to vector and sort by |freqind|
	std::vector<std::pair<char, std::vector<int>>> temporary(newMap.begin(), newMap.end());
	sort(temporary.begin(), temporary.end(), sortByVal);
	// letter: frequency(lowest), index in input
	std::cout << temporary.begin()->first << ": " << temporary.begin()->second.at(0) << ", " << temporary.begin()->second.at(1) << "\n";

	return 0;
}
