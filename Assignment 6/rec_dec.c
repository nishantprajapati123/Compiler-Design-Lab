//	Used grammar: 
//	E	->	iE'
//	E'	->	+iE'
//	E'	->	null
#include "stdio.h"
#include "string.h"
char l;
char a[100];
int i;
void match(char c)
{
	if(a[i]!=c)
	{
		printf("Error!");
		exit(0);
	}
	i++;
}
void E_()
{
	if(a[i]=='+')
	{
		i++;
		match('i');
		E_();
	}
	else
		return;
}
void E()
{
	match('i');
	E_();
}
main()
{
	printf("Enter a string: ");
	scanf("%s",a);
	E();
	if(a[i]=='\0')
		printf("valid expression.\n");
}
