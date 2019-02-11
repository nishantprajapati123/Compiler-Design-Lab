#include<stdio.h>  
#include<string.h>
char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}
int main()  
{  
	char gram[20],part1[20],part2[20],modifiedGram[20],newGram[20],tempGram[20];  
	int i,j=0,k=0,l=0,pos1,pos2;  
	printf("Enter Production : A->");  
	gets(gram);  
	for(i=0;gram[i]!='|';i++,j++)  
		part1[j]=gram[i];  
 	part1[j]='\0';  
 	for(j=++i,i=0;gram[j]!='\0';j++,i++)  
    		part2[i]=gram[j];  
	part2[i]='\0';  
	/*for(i=0;i<strlen(part1)||i<strlen(part2);i++)  
	{  
		if(part1[i]==part2[i])  
    		{  
    			modifiedGram[k]=part1[i];  
    	   		 k++;  
    	    		pos=i+1;  
    		}  
	} */
	
	for(i=strlen(part1)-1,j=strlen(part2)-1;i>=0&&j>=0;i--,j--)
	{
		if(part1[i]==part2[j])
		{
			modifiedGram[k] = part1[i];
			k++;
			pos1 = i-1;
			pos2 = j-1;
		}
	}
	//printf("%d\n%d\n",pos1,pos2);
	//modifiedGram[0]='X';  
	
	modifiedGram[k]='X';
	modifiedGram[++k]='\0';
	//printf("%s\n",modifiedGram);
	strrev(modifiedGram);
	//printf("%s\n",modifiedGram);
	for(i=pos1,j=0;i>=0;i--,j++)  
    		newGram[j]=part1[i];
    	//strrev(newGram);    
	newGram[j++]='|';  
	for(i=pos2;i>=0;i--,j++)
		newGram[j]=part2[i];  
	
	newGram[j]='\0';
	strrev(newGram); 
	printf("\n A->%s",modifiedGram);  
	printf("\n X->%s\n",newGram);
	//printf("\n%s\n%s",part1,part2);  
}
