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

void insert(Tree* root, char* key) 
{ 
	//Variables - create once
	int i; 
	int length = strlen(key); 
	int moduleIndex; 
	//Pointer to the root
	Tree* pCrawl = root; 
	for (i = 0; i < length; i++) 
	{ 
		if(key[i]>='A' && key[i]<='Z')
			moduleIndex=toLowerCase(key[i]);
		else
			moduleIndex = MODULE(key[i]); 
		//If there isn't such node: CREATE
		if ((pCrawl)->children[moduleIndex]==NULL)
			(pCrawl)->children[moduleIndex] = newNode(); 
		(pCrawl) = (pCrawl)->children[moduleIndex]; 
	}//for 
	//If we repeated counter it.
	if((pCrawl)->isEndOfWord = true)
		(pCrawl)->counter++;
	(pCrawl)->isEndOfWord = true; 
}//insert 

bool search(Tree *root, const char *key) 
{ 
	int i; 
	int length = strlen(key); 
	int moduleIndex; 

	Tree *pCrawl = root; 

	for (i = 0; i < length; i++) 
	{ 
		//Getting the right place on module
		moduleIndex = MODULE(key[i]); 
		if (!pCrawl->children[moduleIndex]) 
			return false; 
		pCrawl = pCrawl->children[moduleIndex]; 
	}//for 
	//printf("Times: %d\n",pCrawl->counter);
	return (pCrawl != NULL && pCrawl->isEndOfWord); 
}//search

_Bool isLeaf(Tree* root)
{
	return root->isEndOfWord;
}//isLeaf

void displayTree(Tree* root,char* str,int level)
{
	if(isLeaf(root))
	{
		str[level]+='\0';
		emptyNotUseIndex(str,level);
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
}//freeALL

void displayTreeR(Tree* root,char* str,int level)
{
		if(isLeaf(root))
		{
			str[level]+='\0';
			emptyNotUseIndex(str,level);
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
}//freeALL

void emptyNotUseIndex(char* str,int level)
	{
		for (size_t i = level; i < sizeof(str); i++)
		{
			str[i]='\0';
		}//for
}//empty

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
