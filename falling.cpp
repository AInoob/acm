/*
 * basically factorize the n and see if any combination of it's factors differ only 2k.
 * if the difference of x and y is 2k, then (x/2+y/2+k)(x/2+y/2-k) is |((x+y)/2)^2-k^2| or say a^2-k^2
 * factoring takes O(log n)
 * computing combinations takes O(2^(log n)) which is O(n)
 * so overall speed is O(n)
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <time.h>
#define BIG 2000000000
using namespace std;
int factors[30],numOfFactors=0,n,tempN,p=2,a=BIG,k=BIG,tempX,tempY,tempA;
void dfs(int i,int total){
	//if compute the value of x
	if(i==numOfFactors-1){
		//if the difference of x and y is 2k, then (x/2+y/2+k)(x/2+y/2-k) is |((x+y)/2)^2-k^2| or say a^2-k^2
		if((total-n/total)%2==0){
			tempX=total<n/total?total:n/total;
			tempY=n/tempX;
			tempA=(tempX+tempY)/2;
			//get the smallest possible
			if(tempA<a){
				a=tempA;
				k=abs(tempX-tempY)/2;
			}
		}
	}
	else{
		//if not the finishing computing the x, keep calling.
		dfs(i+1,factors[i+1]*total);
		dfs(i+1,total);
	}
}
int main(){
	cin>>n;
	//if one, just output
	if(n==1){
		cout<<0<<" "<<1;
		return 0;
	}
	tempN=n;
	//factor the n into factors list
	while(tempN!=1){
		if(tempN%p==0){
			factors[numOfFactors++]=p;
			tempN/=p;
		}
		else{
			p++;
		}
	}
	//get all possible combinations of x,y where xy=n
	for(int i=0;i<numOfFactors;i++){
		//[start at which position]	[previous value]
		dfs(i,factors[i]);
	}
	if(a==BIG){
		cout<<"impossible";
	}
	else{
		cout<<k<<" "<<a;
	}
	return 0;
}
