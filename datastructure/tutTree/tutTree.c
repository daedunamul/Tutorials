#include "tutTree.h"

void tutTree_traverse( struct tutTreeNode *RootNode , void ( *TraversalFx )( struct tutTreeNode *ThisNode , void *Data ) )
{
}

void tutTree_push( struct tutTreeNode *ThisNode , struct tutTreeNodePool *NodePool , int Value )
{
	if( ThisNode == NULL || NodePool == NULL )
		return ;
	
	struct tutTreeNode *NewNode ;
	
	NewNode = tutTreeNodePool_allocate( NodePool ) ;
	if( NewNode == NULL )
		return ;
	NewNode->Value = Value ;
	NewNode->Degree = 0 ;
	NewNode->Super = ThisNode ;
	NewNode->Sub = NULL ;
	NewNode->Left = NULL ;
	NewNode->Right = ThisNode->Sub ;
	
	if( ThisNode->Sub != NULL )
		ThisNode->Sub->Left = NewNode ;
	ThisNode->Sub = NewNode ;
}
void tutTree_pop( struct tutTreeNode *ThisNode , void *Data )
{
}
