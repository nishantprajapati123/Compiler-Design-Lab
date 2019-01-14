#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	getline(cin,s);
	int zero=0,one=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='0') zero++;
		else if(s[i]=='1') one++;
	}
	if((zero%2!=0) &&(one%2==0)) cout<<"Accept"<<endl;
	else cout<<"Reject"<<endl;
}
