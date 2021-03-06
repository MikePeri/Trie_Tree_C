#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include "Trie.h"

Tree* newNode() 
{ 
	Tree *pNode = NULL; 
	pNode = (Tree *)malloc(sizeof(Tree)); 
	//Create and initialize all the new struct
	if (pNode)      
	{ 
		int i; 
		pNode->isEndOfWord = false; 
		pNode->counter=0;
		for (i = 0; i < ALPHABET_SIZE; i++) 
			pNode->children[i] = NULL; 
	}//if 
	return pNode; 
}//newNode 

int insert(Tree *root) 
{ 
	int height=0;
	int max=0;
	Tree* pCrawl;
	char c=' ';
	int moduleIndex; 
	pCrawl=root;

	while (scanf("%c",&c)!=EOF)
	{
		if(c==' ' || c== '\n' || c==',' || c=='.' || c=='\t' || c=='\0')
			{
				pCrawl->isEndOfWord=true;
				pCrawl->counter++;
				//printf("\tend of word, Times:%d\n",pCrawl->counter);
				pCrawl=root;
				if(max<height)
					max=height;
				height=0;
			}//if
		else
		{
				if(c>='A' && c<='Z')
				moduleIndex=toLowerCase(c);
			else
				moduleIndex = MODULE(c); 
			if(pCrawl->children[moduleIndex]==NULL)
			{
				pCrawl->children[moduleIndex]=newNode();
				height++;
			}//if
				pCrawl=pCrawl->children[moduleIndex];
				//printf("%c",c);
		}//else
	}//while
	return max;
	
}//insert

bool search(Tree *root, const char *key) 
{ 
	int i=0; 
	int length = strlen(key); 
	int moduleIndex=0; 

	Tree *pCrawl = root; 

	for (i = 0; i < length; i++) 
	{ 
		printf("%d ",i);
		//Getting the right place on module
		moduleIndex = MODULE(key[i]); 
		if (pCrawl->children[moduleIndex]==NULL) 
			return false; 
		pCrawl = pCrawl->children[moduleIndex]; 
	}//for 
	printf("Times: %d\n",pCrawl->counter);
	return (pCrawl != NULL && isLeaf(pCrawl)); 
}//search

_Bool isLeaf(Tree* root)
{
	return root->isEndOfWord;
}//isLeaf

void displayTree(Tree* root,char* str,int level)
{
	if(isLeaf(root))
	{
		memset(str+level, '\0', 1);
		if(strcmp(str,""))
				printf("%s %d\n",str,root->counter);
	}//if
	int i;
	for (i = 0; i < ALPHABET_SIZE; i++)
	{
		if(root->children[i]!=NULL)
		{
			str[level]=ReverseMODULE(i);
			displayTree(root->children[i],str,level+1);
		}//if
	}//for
}//displayTree

void displayTreeR(Tree* root,char* str,int level)
{
		if(isLeaf(root))
		{
			memset(str+level, '\0', 1);
			if(strcmp(str,""))
				printf("%s %d\n",str,root->counter);
		}//if

		int i;
		for (i = ALPHABET_SIZE-1; i >=0; i--)
			{
				if(root->children[i]!=NULL)
				{
					str[level]=ReverseMODULE(i);
					displayTreeR(root->children[i],str,level+1);
				}//if
			}//for
}//displayTreeR


void freeAll(Tree* root)
{
	for (size_t i = 0; i < ALPHABET_SIZE; i++)
	{
		if(root->children[i]!=NULL)
		{
			
			freeAll(root->children[i]);
			free(root->children[i]);
		}//if
	}//for
}//FreeAll
