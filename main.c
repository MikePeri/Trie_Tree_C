#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include "Trie.h"
#define WORD 30

int main(int argc, char *argv[]) 
{ 
	Tree* root=newNode();
	char c;
	char word[WORD];
	int index=0;
	while (scanf("%c",&c)!=EOF)
	{
		if (c==' '||c=='\t'||c=='\n'||c=='.'||c==',')
		{
			word[index]='\0';
			if (index!=0)
				insert(root,word);		
			//printf("%s\n",word);
			emptyNotUseIndex(word,0);
			index=0;
		}//if
		else
		{
			word[index++]=c;
		}//else
	}//while
	char str[WORD];
	if(argc==2 && strcmp(argv[1],"r")==0)
		displayTreeR(root,str,0);
	else
		displayTree(root,str,0);
	freeAll(root);
	free(root);
	return 0; 
} 

