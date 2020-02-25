/*
Project:		
Problem_type:	
Author: 		kawaii_pendant
Date:   		2020-02-23 17:47:50
Last Modified Time: 2020-02-24 12:42:36
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,x,y;
		scanf("%d%d%d",&n,&x,&y);
		int ans_l=0,ans_r=0;
		if(x+y>=n+1) ans_r=n,ans_l=min(n,x+y+1-n);
		else ans_l=1,ans_r=x+y-1;
		printf("%d %d\n",ans_l,ans_r);
	}
}