/*
Project:		UVA 658
Problem_type:	
Author: 		kawaii_pendant
Date:   		2020-01-14 11:49:29
Last Modified Time: 2020-01-14 13:02:59
*/
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#define ll long long
using namespace std;
const int INF=1e9;
const int maxm=(1<<20)+10;
int vis[maxm],dis[maxm];
int s[2][110],t[2][110];
int n,m,w[110];
string s1,s2;
int main(){
	int kase=0;
	while(~scanf("%d%d",&n,&m)&&(n||m)){
		memset(s,0,sizeof(s));
		memset(t,0,sizeof(t));
		for(int i=0;i<m;i++){
			scanf("%d",&w[i]);
			cin>>s1>>s2;
			for(int j=0;j<n;j++){
				if(s1[j]=='+') s[1][i]+=(1<<j);//表示必须打补丁
				if(s1[j]!='-') s[0][i]+=(1<<j);//无所谓
				if(s2[j]=='+') t[1][i]+=(1<<j);
				if(s2[j]!='-') t[0][i]+=(1<<j);
			}
		}
		int maxx=(1<<n)-1;//1表示未打补丁,有bug
		queue<int> q;
		for(int i=0;i<maxx;i++){
			vis[i]=0;
			dis[i]=INF;
		}
		vis[maxx]=1;
		dis[maxx]=0;
		q.push(maxx);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			vis[u]=0;
			for(int i=0;i<m;i++){
				if((u|s[1][i])==u&&(u&s[0][i])==u){
					int v=u;
					v=v|t[1][i];
					v=v&t[0][i];
					if(dis[u]+w[i]<dis[v]){
						dis[v]=dis[u]+w[i];
						if(!vis[v]){
							q.push(v);
							vis[v]=1;
						}
					}
				}
			}
		}
		printf("Product %d\n",++kase);
		if(dis[0]==INF) printf("Bugs cannot be fixed.\n");
		else printf("Fastest sequence takes %d seconds.\n",dis[0]);
		printf("\n");
	}	
}