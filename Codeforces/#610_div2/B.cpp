/*
Project:		
Problem_type:	
Author: 		kawaii_pendant
Date:   		2019-12-26 12:58:59
Last Modified Time: 2020-01-06 17:00:58
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int maxm=2e5+10;
int n,p,k,a[maxm];
int dp[maxm];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&p,&k);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);	
		for(int i=1;i<=n;i++){
			if(i-k>=0) dp[i]=min(dp[i-1]+a[i],dp[i-k]+a[i]);
			else dp[i]=dp[i-1]+a[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			if(p>=dp[i]) ans=i;
		printf("%d\n",ans);
	}
}