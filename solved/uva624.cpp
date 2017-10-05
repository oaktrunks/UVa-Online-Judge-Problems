//////////////////////////////////////////////////////////////////////

//Daniel Tomei : CD : 624 : oaktrunks

//Data structure required : vector, bitset

//Tricks of the trade : using bitsets to create possible combinations

/////////////////////////////////////////////////////////////////////
#include <vector>
#include <iostream>
#include <bitset>

using namespace std;
int main(){
  int N, num_tracks;
  int temp;
  
  ios_base::sync_with_stdio(0); cin.tie(0);
  while(cin >> N >> num_tracks){
    //Read in tracks
    vector<int> tracks;
    for(int i = 0; i < num_tracks;i++){
      cin >> temp;
      tracks.push_back(temp);
    }
    //Make bitset of all possible combinations (position wise)
    vector<bitset<20> >  combinations(1 << num_tracks,0);
    for(int i = 0; i <= 1 << num_tracks;i++){
      combinations[i] = i;
    }
    /* debug output of combination bitsets
    for(int j = 0; j < combinations.size(); j++){
      cout << combinations[j].to_string() << endl;
    }
    */
    int best = 0;
    vector<int> bestCombi;
    //Iterate over combinations
    for(int i = 0; i < 1 << num_tracks;i++){
      //cout << combinations[i].to_string() << endl;
      vector<int> Combi;
      int sum = 0;
      for(int j = 0; j < 21; j++){
        if(combinations[i][j] == 1){ //Bitset has a 1 in position
          sum += tracks[j];
          //cout << "plus " << tracks[j] << endl;
          Combi.push_back(tracks[j]);
        }
      }
      
      if(sum > best && sum <= N){
        best = sum;
        bestCombi.clear();
        for(int k = 0; k < Combi.size(); k++){
          bestCombi.push_back(Combi[k]);
        }
      }
    }
    
    //Output solution
    for(int i = 0; i < bestCombi.size(); i++){
      cout << bestCombi[i] << " ";
    }
    cout << "sum:" << best << endl;
  }

  return 0;
}