%{
#include<stdio.h>
%}

id              [_a-zA-Z0-9]*

%%
\'{id}\'		printf("Character literal:%s",yytext);
\"{id}\"		printf("String literal:%s",yytext);
.*			printf("NOT Valid");
%%

int yywrap()
{
	return 1;
}

int main()
{
	printf("Enter within single quote or double quote\n");
	yylex();
	return 0;
}
