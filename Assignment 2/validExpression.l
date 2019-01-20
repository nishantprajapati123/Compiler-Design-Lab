%{
#include<stdio.h>
int operate=0,operan=0;
int ob=0,cb=0;
%}

operand			[a-zA-Z0-9]+
operator		[+\-\/*]

%%
{operand}		{++operan;}
{operator}		{++operate;}
"("			{if(cb<=ob) ++ob;}
")"			{++cb;}
\n			{if(ob==cb && operan>operate) printf("Valid Expression\n");
			else printf("Invalid Expression\n");}
%%

int yywrap()
{return 1;}

int main()
{
printf("Enter any expression:\n");
yylex();
return 0;
}
