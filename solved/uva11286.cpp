//////////////////////////////////////////////////////////////////////

//Daniel Tomei : Conformity : 11286 : oaktrunks

//Data structure required : unordered_map, string, vector

//Tricks of the trade : sorting and concatenating into a string
//                      makes indexing and comparisons easier
//                      using unordered_map for faster look up times
//                      than map.
//                      to avoid iterating over the map i use a variable
//                      to hold the max number in the unordered_map
//                      and int conformists to hold the amount of groups
//                      that hold the most popular classes

/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int frosh;	//holds amount of students
	cin >> frosh;
	while (frosh){
		unordered_map<string, int> popularity;
		int max = 0;	//holds how many people have the most popular combination
		int conformists = 1;	//holds how many groups hold the most popular combinations
		for (int i = 0; i < frosh; i++){
			vector<string> course(5);
			string s;

			//reading in selected courses
			for (int j = 0; j < 5; j++){
				cin >> course[j];
			}

            //sorting and concatenating into one string
			sort(course.begin(), course.end());
			for (int j = 0; j < 5; j++){
				s = s + course[j];
			}

            //inserting it into map and updating int max, int conformists
			if (++popularity[s] > max){
				max = popularity[s];
				conformists = 1;
			}
			else if (popularity[s] == max)
				conformists++;

		}
		cout << conformists * max << '\n';

		cin >> frosh;
	}

	return 0;
}