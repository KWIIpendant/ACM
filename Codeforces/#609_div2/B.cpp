/*
Project:		
Problem_type:	
Author: 		kawaii_pendant
Date:   		2019-12-21 17:09:03
Last Modified Time: 2019-12-21 21:10:44
*/
#include <set>
#include <map>
#include <cstdio>
#include <iostream>
#include <unordered_map>
#define ll long long
using namespace std;
const int maxm=2e3+10;
int n,m;
int a[maxm],b[maxm];
unordered_map<int,int> numa,numb,tmp;
set<int> sta,stb;
bool able(int x){
	for(set<int>::iterator it=sta.begin();it!=sta.end();it++){
		if(numa[*it]!=numb[(*it+x)%m]) return false;
	}
	return true;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) {	
		scanf("%d",&a[i]);
		numa[a[i]]++;
		if(!sta.count(a[i])) sta.insert(a[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&b[i]);
		numb[b[i]]++;
		if(!stb.count(b[i])) stb.insert(b[i]);
	}
	int ans=1e9+10;
	for(set<int>::iterator it=sta.begin();it!=sta.end();it++){
		for(set<int>::iterator it1=stb.begin();it1!=stb.end();it1++){
			if(numa[*it]!=numb[*it1]) continue;
			else {
				int a=*it,b=*it1;
				if(a<b) if(able(b-a)) ans=min(ans,b-a);
				else if(able(b-a+m)) ans=min(ans,b-a+m);
			}
		}
	}
	if(ans==m) ans=0;
	cout<<ans<<endl;
}
