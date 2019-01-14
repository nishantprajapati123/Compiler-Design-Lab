/*Program to identify valid Identifier*/
%{
#include<stdio.h>
%}

%%

[_a-zA-Z][_a-zA-Z0-9]*       printf("Identifier\n");
.*                           printf("NOT Identifier\n"); /*All other string*/

%%

/*call the yywrap function*/
int yywrap()					
{
return 1;
}

int main(void)
{
yylex();						
return 0;
}
