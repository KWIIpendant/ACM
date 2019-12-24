/*
Project:		
Problem_type:	
Author: 		kawaii_pendant
Date:   		2019-12-24 16:54:30
Last Modified Time: 2019-12-24 17:07:32
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#define ll long long
using namespace std;
const int maxm=1e2+10;	
char a[maxm],b[maxm];
int lena,lenb;
int numa[30],numb[30];
bool check(int s,int t){
	memset(numb,0,sizeof(numb));
	for(int i=s;i<=t;i++)
		numb[b[i]-'a']++;
	for(int i=0;i<26;i++)
		if(numb[i]!=numa[i])
			return false;
	return true;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		memset(numa,0,sizeof(numa));
		scanf("%s%s",a,b);
		lena=strlen(a),lenb=strlen(b);
		for(int i=0;i<lena;i++) numa[a[i]-'a']++;
		bool ans=0;
		for(int i=0;i<lenb;i++){
			for(int j=i;j<lenb;j++){
				if(check(i,j)){
					ans=1;
					break;
				}
			}
			if(ans) break;
		}
		if(ans) printf("YES\n");
		else printf("NO\n");
	}
}