/*
Project:		
Problem_type:	
Author: 		kawaii_pendant
Date:   		2020-02-23 16:29:08
Last Modified Time: 2020-02-23 17:19:21
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
	int a[3];
	int T;
	scanf("%d",&T);
	while(T--){
		int ans=0;
		for(int i=0;i<3;i++) scanf("%d",&a[i]);
		sort(a,a+3);
		if(a[0]) ans++,a[0]--;
		if(a[1]) ans++,a[1]--;
		if(a[2]) ans++,a[2]--;
		sort(a,a+3);
		if(a[2]&&a[0]) ans++,a[2]--,a[0]--;
		if(a[2]&&a[1]) ans++,a[1]--,a[2]--;
		if(a[0]&&a[1]) ans++,a[0]--,a[1]--;
		if(a[0]&&a[2]&&a[1]) ans++,a[0]--,a[2]--,a[1]--;
		printf("%d\n",ans);
	}
}