#include <iostream>
#define BIG 1000000000
using namespace std;
/*
 * using Dynamic Programming to solve this, the shape is like a triangle.
 * map[a][0] means creating a new line, while map[a][b] means append the word to map[a-1][b-1]
 * Every time creating a new line, get the smallest height from previous combinations
 */
int main(){
	//0:current width 1:current height 2:total height
	int map[5000][5000][3],n,width,w,h,temp;
	cin>>n>>width;
	cin>>w>>h;
	map[0][0][0]=w;
	map[0][0][1]=h;
	map[0][0][2]=h;
	for(int i=1;i<n;i++){
		//if start a new line, get the smallest height of previous possibilities
		temp=0;
		cin>>w>>h;
		for(int j=1;j<i;j++){
			if(map[i-1][j][2]<map[i-1][temp][2]){
				temp=j;
			}
		}
		map[i][0][0]=w;
		map[i][0][1]=h;
		map[i][0][2]=map[i-1][temp][2]+h;
		for(int j=1;j<=i;j++){
			if(map[i-1][j-1][0]+w>width){
				map[i][j][0]=BIG;
				map[i][j][1]=BIG;
				map[i][j][2]=BIG;
			}
			else{
				map[i][j][0]=map[i-1][j-1][0]+w;
				if(h>map[i-1][j-1][1]){
					map[i][j][1]=h;
					map[i][j][2]=map[i-1][j-1][2]+h-map[i-1][j-1][1];
				}
				else{
					map[i][j][1]=map[i-1][j-1][1];
					map[i][j][2]=map[i-1][j-1][2];
				}
			}
		}
	}
	temp=0;
	for(int j=1;j<n;j++){
		if(map[n-1][j][2]<map[n-1][temp][2]){
			temp=j;
		}
	}
	cout<<map[n-1][temp][2];
	return 0;
}
