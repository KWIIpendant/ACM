/*
Project:		UVA 247
Problem_type:	
Author: 		kawaii_pendant
Date:   		2020-01-09 10:35:15
Last Modified Time: 2020-01-11 22:23:24
*/
#include <map>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#define ll long long
using namespace std;
const int maxm=30;
map<string,int> mp;	
string ans[maxm];
int con[maxm][maxm],vis[maxm];	
int main(){
	int n,m,kase=0;
	while(~scanf("%d%d",&n,&m)&&(n||m)){
		int cnt=0;
		mp.clear();
		memset(con,0,sizeof(con));
		memset(vis,0,sizeof(vis));	
		for(int i=0;i<m;i++){
			string a,b;
			cin>>a>>b;
			if(!mp.count(a)) mp[a]=cnt++,ans[cnt-1]=a;
			if(!mp.count(b)) mp[b]=cnt++,ans[cnt-1]=b;
			con[mp[a]][mp[b]]=1;
		}
		for(int i=0;i<n;i++) con[i][i]=1;
		for(int k=0;k<n;k++){
			for(int i=0;i<n;i++){
				if(con[i][k]){
					for(int j=0;j<n;j++){
						if(con[k][j]){
							con[i][j]=1;
						}
					}
				}
			}
		}
		printf("Calling circles for data set %d:\n",++kase);
		for(int i=0;i<n;i++){
			if(vis[i]) continue;
			cout<<ans[i];
			vis[i]=1;
			for(int j=0;j<n;j++){
				if(!vis[j]&&con[i][j]&&con[j][i]){
					cout<<", "<<ans[j];
					vis[j]=1;
				}
			}
			cout<<endl;
		}
	}
}