//////////////////////////////////////////////////////////////////////

//Daniel Tomei : Rails : 514 : oaktrunks

//Data structure required : stacks, queues

//Tricks of the trade : push every input train onto a stack
//                      and then try to loop through and empty
//                      the stack as much as possible
//          (checking if front of output queue == top of input stack)

/////////////////////////////////////////////////////////////////////
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(){
	int numCoaches, currentTrain;
	bool continuePerms;
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> numCoaches;
	while (numCoaches){

		continuePerms = true;
		while (continuePerms){
			queue<int> trainOutput; //used to hold current output permutation
			stack<int> trainStack;  //used as the "station" for trains to reverse out of

            //reading in train input
			for (int i = 0; i < numCoaches; i++){
				cin >> currentTrain;
                //checking for 0 input
				if (!currentTrain){
					continuePerms = false;
					break;
				}
				trainOutput.push(currentTrain);
			}
			if (!continuePerms){
				break;
			}

            //processing
			for (int i = 1; i <= numCoaches; i++){
				trainStack.push(i);

				//try to empty stack as much as possible
				while (!trainStack.empty() && !trainOutput.empty() && (trainOutput.front() == trainStack.top())){
					trainStack.pop();
					trainOutput.pop();
				}
			}

            //outputting
			if (!trainStack.empty()){
				cout << "No\n";
			}
			else
				cout << "Yes\n";

		}
		cout << "\n";
		cin >> numCoaches;
	}
	return 0;
}