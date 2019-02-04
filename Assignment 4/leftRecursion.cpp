#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cout<<"Enter number of productions:";
	cin>>t;
	while(t--)
	{
		char str[100],*l,*r,*temp,productions[25][50];
		bool flag=false;
		int i=0,j=0;
		cout<<"Enter the production:\n";
		cin>>str;
		l = strtok(str,"->");
		r = strtok(NULL,"->");
		//cout<<r<<"\n";
		temp = strtok(r,"|");
		while(temp)  
		{
        		if(temp[0] == l[0])  {
            			flag = true;
            			sprintf(productions[i++],"%s'->%s%s'",l,temp+1,l);
        		}
        		else
            			sprintf(productions[i++],"%s->%s%s'",l,temp,l);
            		//cout<<temp<<"\n";
        		temp = strtok(NULL,"|");
    		}
    		sprintf(productions[i++],"%s'->\u03B5",l);
    		if(!flag)
        		cout<<"The given productions don't have Left Recursion\n";
    		else
        		for(j=0;j<i;j++)  
        		{
        		    cout<<productions[j]<<"\n";
        		}
        }
    	return 0;
}
