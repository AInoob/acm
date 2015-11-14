/* look at dancerecital.cpp for the idea*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string.h>
#include <math.h>
#include <time.h>
using namespace std;
char input[10][27];
int dist[26][26],n,ans=10000000;
void dfs(int arr,int len,int prev,int cost){

	if(cost>ans){

		return;
	}
	if(len==0){

		ans=ans<cost?ans:cost;
	}
	else{

		int temp=1,next_arr,index;
		for(int i=0;i<len;i++){

			index=arr/temp%10;
			next_arr=arr%temp+arr/10/temp*temp;
			dfs(next_arr,len-1,index,cost+dist[prev][index]);
			temp*=10;
		}
	}
}
int main(){

	cin>>n;
	for(int i=0;i<n;i++){

		cin>>input[i];
		for(int j=0;j<i;j++){

			int k=0,cursor_1=0,cursor_2=0,len_1=strlen(input[i]),len_2=strlen(input[j]);
			for(;cursor_1<len_1;cursor_1++){

				for(int l=cursor_2;l<len_2;l++){

					if(input[i][cursor_1]==input[j][l]){

						k++;
						cursor_2=l+1;
					}
				}
			}
			dist[i][j]=k;
			dist[j][i]=k;
		}
	}
	for(int i=0;i<n;i++){

		int temp=0;
		for(int j=0;j<n;j++){

			if(j!=i){

				temp*=10;
				temp+=j;
			}
		}
		dfs(temp,n-1,i,0);
	}
	cout<<ans;
	return 0;
}
