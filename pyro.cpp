/*
 * creating a list conatining every possible numbers, keep track of the number of possible permutations.
 * Everytime get a new number, generate all possible permutations, and increment the number of possible permutations of those permutations in the list
 * list[i] contains the number of possible permutions of i.
 * everytime get all permutations x, increment list[x]
 */
#include <iostream>
using namespace std;
int main(){
	int input[250000],list[270000],numOfInputs=0,n,a,temp;
	for(int i=0;i<270000;i++){
		list[i]=0;
	}
	cin>>n;
	while(n!=-1){
		input[numOfInputs++]=n;
		for(int j=0;j<18;j++){
			temp=n^(1<<j);
			if(temp<n){
				list[temp]++;
			}
			for(int k=j+1;k<18;k++){
				temp=n^(1<<j)^(1<<k);
				if(temp<n){
					list[temp]++;
				}
			}
		}
		cin>>n;
	}
	for(int i=0;i<numOfInputs;i++){
		cout<<input[i]<<":"<<list[input[i]]<<endl;
	}
	return 0;
}
