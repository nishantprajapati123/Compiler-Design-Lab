%{
#include<stdio.h>
#include<stdlib.h>
%}

keywords	"if"|"auto"|"char"|"const"|"double"|"enum"|"extern"|"float"|"inline"|"int"|"long"|"register"|"restrict"|"short"|"signed"|"static"|"struct"|"typedef"|"union"|"unsigned"|"void"|"break"|"case"|"continue"|"default"|"do"|"else"|"for"|"while"|"goto"|"return"|"sizeof"|"switch"|"class"

punctuator	"{"|";"|"["|"]"|"("|")"|"{"|"}"|"."|"~"|"!"|"<<"|">>"|"!"|":"|";"|"<<="|">>="|"&="|","

operator	"+"|"-"|">"|"--"|"&"|"*"|"+"|"/"|"%"|"<"|"<="|">="|"=="|"^"|"&&"|"?:"|"="|"*="|"/="|"%="|"+="|"-="|"^="|"|"

literals	[_a-zA-Z][_a-zA-Z0-9]*

constant	[0-9]+|[0-9]*"."[0-9]+

escape		"\n"|"\t"|"\a"|"\r"|"\v"|"\b"|"\f"|"\0"|"\"
space		[" "]+
%%
{keywords}		{printf("%s\t-\tKeywords\n",yytext);}
{punctuator}		{printf("%s\t-\tPunctuator\n",yytext);}
{operator}		{printf("%s\t-\tOperator\n",yytext);}
{literals}		{printf("%s\t-\tLiterals\n",yytext);}
{constant}		{printf("%s\t-\tConstant\n",yytext);}
\'.\'			{printf("%s\t-\tCharacter\n",yytext);}
\".+\"			{printf("%s\t-\tString\n",yytext);}
{space}			;
\n			{return 0;}
%%

int yywrap()
{
return 1;
}

int main()
{
	yylex();
	return 0;
}
