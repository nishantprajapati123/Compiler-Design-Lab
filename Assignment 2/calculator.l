%{
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int op=0;
float a,b;
%}

digits		[0-9]+|[0-9]*"."[0-9]+

%%
{digits}	{
			if(op==0)
				a=atof(yytext);
			else
			{
				b=atof(yytext);
				switch(op)
				{
				case 1:
				a=a+b;
				break;
				case 2:
				a=a-b;
				break;
				case 3:
				a=a*b;
				break;
				case 4:
				a=a/b;
				break;
				}
			op=0;
			}
			
		}
"+"		{op=1;}
"-"		{op=2;}
"*"		{op=3;}
"/"		{op=4;}
\n		{return 0;}
%%

int yywrap()
{return 1;}

int main()
{
yylex();
printf("Result:%f\n",a);
return 0;
}



