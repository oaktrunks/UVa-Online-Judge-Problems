//////////////////////////////////////////////////////////////////////

//Daniel Tomei : One Little, Two Little, Three Little Endians : 673 : oaktrunks

//Data structure required : bitsets

//Tricks of the trade : swapping bits around by using a formula to subscript

/////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main(){
	int num;
	ios_base::sync_with_stdio(0); cin.tie(0);
	while (cin >> num){
		bitset<32> bitSet1(num);
		bitset<32> bitSet2;
		int length = 32;
		//changing bytes all over the place
		for (int i = 0; i < length; i++){
			bitSet2[length + i % 8 - (i / 8 + 1) * 8] = bitSet1[i];
		}
		if (bitSet2[31]){ //number is negative (twos compliment)
			bitSet2.flip();
			cout << num << " converts to -" << bitSet2.to_ulong() + 1 << "\n";
		}
		else
			cout << num << " converts to " << bitSet2.to_ulong() << endl;
	}

	return 0;
}