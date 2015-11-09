#include <iostream>
using namespace std;
int main(){
	int input[270000],map[270000],numOfInputs=0,n,a;
	for(int i=0;i<270000;i++){
		map[i]=0;
	}
	for(int i=0;i<18;i++){
		map[1<<i]=1;
		for(int j=i+1;j<18;j++){
			map[(1<<i)+(1<<j)]=1;
		}
	}
	cin>>n;
	while(n!=-1){
		input[numOfInputs++]=n;
		cin>>n;
	}
	for(int i=0;i<numOfInputs;i++){
		a=0;
		for(int j=i+1;j<numOfInputs;j++){
			if(map[input[i] xor input[j]]){
				a++;
			}
		}
		cout<<input[i]<<":"<<a<<endl;
	}
	return 0;
}
