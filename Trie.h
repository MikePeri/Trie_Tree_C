#ifndef TRIE_H_
#define TRIE_H_

#define MODULE(c) ((int)c - (int)'a') 
#define toLowerCase(c) ((int)c - (int)'A') 
#define ReverseMODULE(c) (char)(c + 'a') 
#define ALPHABET_SIZE	(26)
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0]) 

/**
 * This struct represetnt Node in Trie Tree
 * The Tree is collection of this nodes with dependesies.
 * Each node have 26 option NEXTS.
 * Boolean variable that determine if is suffix
 * Counter the num of times we input the same value
 */
typedef struct TrieNode 
{ 
	struct TrieNode* children[ALPHABET_SIZE]; 
	_Bool isEndOfWord; 
	int counter;
}Tree; 
/**
 * This function simple create new node.
 */
Tree *newNode() ;
/**
 * This function will insert new node to the Tree
 */
void insert(Tree *root, char *key) ;
/**
 * This function will search if word inputed to the tree
 */
_Bool search(Tree *root,const char *key);
/**
 * This function will free all the memory in the tree
 */
void freeAll();
/**
 * Displaying all the content tree in lexographic way
 * Method: like BT we will travel untill we find a leaf 
 * We do that recursive with all the optional Nodes
 */
void displayTree(Tree*,char*,int);
/**
 * Display in the oposite way of upon function
 */
void displayTreeR(Tree*,char*,int);
/**
 * This function will help us to Dspaly the tree
 */
_Bool isLeaf();
/**
 * This function will help the display function to re use the char pointer
 */
void emptyNotUseIndex(char*,int);
/**
 * Converting big letter to lower one
 */
#endif