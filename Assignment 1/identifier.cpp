#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	bool valid=true;
	getline(cin,s);
	if(s[0]=='_' || (s[0]>='A'&&s[0]<='Z') || (s[0]>='a'&&s[0]<='z'))
	{
		for(int i=1;i<s.length();i++)
		{
			if(s[i]==' ')
			{
				valid=false;
				break;
			}
			if(s[i]=='_' || (s[i]>='A'&&s[i]<='Z') || (s[i]>='a'&&s[i]<='z') || (s[i]>='0'&&s[i]<='9'))
			{
				continue;
			}
			else 
			{
				valid=false;
				break;
			}		
		}
	}
	else valid=false;
	if(valid) cout<<"Valid"<<endl;
	else cout<<"NOT Valid"<<endl;
}
