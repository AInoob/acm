/*
 * https://open.kattis.com/problems/dancerecital
 * this is a simple dfs, with prune. However, the running time can be reduced(even not necessary) by trying to remove some unnecessary work. My first running time was 0.17, now it's 0.05, I mean, it is unnecessary, but just treat my action as a crave to be perfect, even this is stupid.
 * so first make a 2-D dist that contains the distance(number of same players) then evaluate all possible combinations. That's dfs part, the prune part is once dfs get the distance of the cost of one combination, put it in ans, later compare cost dfs get with ans, if greater or equal to ans, just ignore it.
 * A very tiny reduce is do not evaluate one input as first element in the conbination, because the reverse order will work, so there are duplicate, thus we are safe to ignore one input as first element in the combination.
 * Other stupid reduce is to declare some variables outside se we do not need to declare it again and again in for loop. Very useless but I just did!
 * Another slower version can be found in my git called dancerecital_slow.cpp, it has basically the same dfs and prune, but do not have those small optimization
 */
#include <iostream>
#include <string.h>
using namespace std;
char input[10][27];
int dist[26][26],n,ans=10000000,cursor_1,cursor_2,len_1,len_2,temp_cost,index_1;
void dfs(int arr,int len,int prev,int cost){
	if(len==0){
		if(ans>cost){
			ans=cost;
		}
	}
	else{
		int temp=1;
		for(int i=0;i<len;i++){
			index_1=arr/temp%10;
			temp_cost=cost+dist[prev][index_1];
			if(temp_cost<ans){
				dfs(arr%temp+arr/10/temp*temp,len-1,index_1,temp_cost);
			}
			temp*=10;
		}
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>input[i];
		for(int j=0;j<i;j++){
			int k=0,
				cursor_1=0;cursor_2=0;len_1=strlen(input[i]);len_2=strlen(input[j]);
			for(;cursor_1<len_1;cursor_1++){
				for(int l=cursor_2;l<len_2;l++){
					if(input[i][cursor_1]==input[j][l]){
						k++;
						cursor_2=l+1;
					}
				}
			}
			dist[j][i]=dist[i][j]=k;
		}
	}
	int temp=1;
	int arr=0;
	for(int i=0;i<n;i++){
		arr*=10;
		arr+=i;
	}
	for(int i=0;i<n-1;i++){
		dfs(arr%temp+arr/10/temp*temp,n-1,n-1-i,0);
		temp*=10;
	}
	cout<<ans;
	return 0;
}
