//To write a code for LR(0) Parser for following Production:
//S->AA
//E->aA
//E->b
#include<stdio.h>
#include<string.h>

int action[][3][2]={

        {{100,3},{100,4},{-1,-1}},

        {{-1,-1},{-1,-1},{102,102}},

        {{100,3},{100,4},{-1,-1}},

        {{100,3},{100,4},{-1,-1}},

        {{101,3},{101,3},{101,3}},

        {{-1,-1},{-1, -1},{101,1}},

        {{101,2},{101,2},{101,2}},

        };//Action Table

int gotot[10][2]={1,2,-1,-1,-1,5,-1,6,-1,-1,-1,-1,-1,-1};  //GoTo table 

int a[10];
char b[10];
int top=-1,btop=-1,i;

void push(int k)
{
	if(top<9)
		a[++top]=k;
}
void pushb(char k){
	if(btop<9)
		b[++btop]=k;
}
char topofStack()
{
	return a[top];
}
void pop()
{
	if(top>=0)
		top--;
}
void popb()
{
	if(btop>=0)
		b[btop--]='\0';
}
void display()
{
	for(i=0;i<=top;i++)
		printf("%d%c",a[i],b[i]);
}
void display1(char p[],int m) //displays the present input string
{
	int l;
	printf("\t\t\t");
	for(l=m;p[l]!='\0';l++)
		printf("%c",p[l]);
	printf("\n");
}
void error()
{
	printf("Syntax Error");
}
void reduce(int p)
{
	int len,k,ad;
	char src,*dest;
	switch(p){
		case 1:
			dest="AA";
			src='S';
			break;
		case 2:
			dest="aA";
			src='A';
			break;
		case 3:
			dest="b";
			src='A';
			break;
		default:
			dest="\0";
			src='\0';
			break;
	}
	for(k=0;k<strlen(dest);k++)
	{
		 pop();
		 popb();
	}
	pushb(src);
	switch(src)
	{
		case 'S':
			ad=0;
			break;
		case 'A':
			ad=1;
			break;
		default:
			ad=-1;
			break;
   }
	push(gotot[topofStack()][ad]);
}

int main()
{
	int j,st,ic;
	char ip[20]="\0",an;
	printf("Enter any String\n");
	scanf("%s",ip);
        ip[strlen(ip)]='$';
        ip[strlen(ip)+1]='\0';
	push(0);
	display();
	printf("\t%s\n",ip);
	for(j=0;ip[j]!='\0';)
        {
		st=topofStack();
		an=ip[j];
		if(an=='a') ic=0;
		else if(an=='b') ic=1;
		else if(an=='$') ic=2;
		else{
			error();
			break;
		}
		if(action[st][ic][0]==100)
		{
			pushb(an);
			push(action[st][ic][1]);
			display();
			j++;
			display1(ip,j);
		}
		if(action[st][ic][0]==101)
		{
			reduce(action[st][ic][1]);
			display();
			display1(ip,j);
		}
		if(action[st][ic][1]==102)
		{
			printf("Given String is accepted \n");
			break;
		}
	}
	return 0;
}
