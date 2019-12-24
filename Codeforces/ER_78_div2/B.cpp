/*
Project:		
Problem_type:	
Author: 		kawaii_pendant
Date:   		2019-12-24 17:08:14
Last Modified Time: 2019-12-24 17:18:18
*/
#include <cstdio>
#include <iostream>
#define ll long long
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int a,b;
		cin>>a>>b;
		if(a<b) swap(a,b);
		int ans=0;
		while(1){
			int tmp=ans*(ans+1)/2;
			if(tmp>=a-b&&(a-b)%2==tmp%2) break;
			else ans++;
		}
		cout<<ans<<endl;
	}
}