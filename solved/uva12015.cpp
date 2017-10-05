//////////////////////////////////////////////////////////////////////

//Daniel Tomei : Google is Feeling Lucky : 12015  : OakTrunks

//Data structure required : vectors, strings

//Tricks of the trade :

/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	int t, tempR;
	string tempUrl;
	vector<string> urls; //holds highest rated urls
	int r; //holds relevance of highest rated url

	cin >> t;
	for (int i = 1; i <= t; i++){
		urls.clear();
		r = 0;
		for (int j = 0; j < 10; j++){
			cin >> tempUrl >> tempR;
			if (tempR > r){	//input relevance higher than previous high
				urls.clear();
				r = tempR;
				urls.push_back(tempUrl);
			}
			else if (tempR == r){
				urls.push_back(tempUrl);
			}
		}
		cout << "Case #" << i << ":" << "\n";
		for (int k = 0; k < urls.size(); k++){
			cout << urls[k] << "\n";
		}
	}

	return 0;
}