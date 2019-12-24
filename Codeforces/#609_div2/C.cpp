/*
Project:		
Problem_type:	
Author: 		kawaii_pendant
Date:   		2019-12-21 17:09:07
Last Modified Time: 2019-12-24 16:17:08
*/
#include <cstdio>
#include <iostream>
#define ll long long
using namespace std;
const int maxm=2e5+10;
char a[maxm],b[maxm];	
char tmp[maxm];
int n,k;
bool judge(){
	bool equ=0;
	for(int i=0;i<n;i++){
		if(tmp[i%k]>a[i]) {
			return true;
		}else if(tmp[i%k]==a[i]) {
			equ=1;
		}else if(equ&&tmp[i%k]<a[i]) {
			return false;
		}
	}
	return true;
}
void add(char *s){
	if(s[k-1]<'9') {
		s[k-1]++;
	}else{
		int i=k-1;
		while(i>=0){
			if(s[i]=='9') {
				s[i]='0';
				i--;
			}else {
				s[i]++;
				break;
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&k);
	scanf("%s",a);
	for(int i=0;i<k;i++) tmp[i]=a[i];
	while(1){
		if(judge()) break;
		add(tmp);
		break;
	}	
	cout<<n<<endl;
	for(int i=0;i<n;i++){
		printf("%c",tmp[i%k]);
	}
	printf("\n");
}