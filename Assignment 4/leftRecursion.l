%{
char *l,*r,*temp;
int i=0,j=0,flag=0;
%}
%%
[a-zA-Z]+[-][>][a-zA-Z]+[|][a-zA-Z]+ {left_recur();}
\n	{return 0;}

%%
int left_recur()
{
    l = strtok(yytext,"->");
    r = strtok(NULL,"->");
    temp = strtok(r,"|");
    while(temp)  
    {
    	printf("%c%c",temp[0],l[0]);
        if(temp[0] == l[0])  
        {
            flag = 1; 
            printf("\n%s'->%s%s'\0",l,temp+1,l);
        }
        else if(flag!=0)
            printf("\n%s->%s%s'\0",l,temp,l);
        temp = strtok(NULL,"|");
    }
    if(flag!=0)
    	printf("\n%s'->\u03B5\n",l);
    if(flag == 0)
        printf("%s\nThe given productions don't have Left Recursion",yytext);
    return 0;

}
int yywrap(){}
int main(){
printf("Enter production rules: ");
yylex();
return 0;
}
