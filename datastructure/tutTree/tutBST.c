#include "tutBST.h"

void tutBST_travel( struct tutTreeNode *RootNode , void *Data , enum tutBSTMethod Method , void ( *TravelFx )( struct tutTreeNode *ThisNode , void *Data ) )
{
}

void tutBST_push( struct tutTreeNode *ThisNode , bool Flag , struct tutTreeNodePool *NodePool , int Value )
{
	if
	( 
		( ThisNode == NULL || NodePool == NULL )
		||
		( Flag == false && ThisNode->Left != NULL )
		||
		( Flag == true && ThisNode->Right != NULL )
	)
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
	NewNode->Right = NULL ;
	
	if( Flag )
		ThisNode->Right = NewNode ;
	else
		ThisNode->Left = NewNode ;
	ThisNode->Degree ++ ;
}
void tutBST_pop( struct tutTreeNode *ThisNode , bool Flag , struct tutTreeNodePool *NodePool )
{
}
