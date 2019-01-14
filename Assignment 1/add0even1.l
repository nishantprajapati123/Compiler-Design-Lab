/*Program to accept odd no. of zero's and even no. of one's*/
%{
#include<stdio.h>
int zero=0;
int one=0;
%}

%%
[0]			++zero;
[1]			++one;
\n          return 0;
%%

int yywrap()
{
return 1;
}

int main(void)
{
	yylex();
	if(zero%2!=0 && one%2==0) printf("Accept\n");
	else printf("Reject\n");
	return 0;
}