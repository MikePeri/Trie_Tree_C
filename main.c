#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include "Trie.h"

int main(int argc, char *argv[]) 
{ 
	Tree* root=newNode();
	int height=insert(root);
	char str[height];
	memset(str, '\0', height);
	if(argc==2 && strcmp(argv[1],"r")==0)
		displayTreeR(root,str,0);
	else
		displayTree(root,str,0);
	freeAll(root);
	free(root);
	return 0; 
}//main 

