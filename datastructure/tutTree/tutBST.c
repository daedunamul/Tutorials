#include "tutBST.h"

void tutBST_preorder( struct tutTreeNode *RootNode , void *Data , void ( *TravelFx )( struct tutTreeNode *ThisNode , void *Data ) )
{
	if( RootNode == NULL )
		return ;
	
	struct tutTreeNode *ThisNode = RootNode ;
	
	Visiting : 
	TravelFx( ThisNode , Data ) ;
	
	if( ThisNode->Left != NULL )
	{
		ThisNode = ThisNode->Left ;
		goto Visiting ;
	}
	
	if( ThisNode->Right != NULL )
	{
		ThisNode = ThisNode->Right ;
		goto Visiting ;
	}
	
	while( ThisNode->Super != NULL )
	{
		if( ThisNode->Super->Right != NULL && ThisNode->Super->Right != ThisNode )
		{
			ThisNode = ThisNode->Super->Right ;
			goto Visiting ;
		}
		
		ThisNode = ThisNode->Super ;
	}
	
	// no nodes to visit
}
void tutBST_inorder( struct tutTreeNode *RootNode , void *Data , void ( *TravelFx )( struct tutTreeNode *ThisNode , void *Data ) )
{

}
void tutBST_postorder( struct tutTreeNode *RootNode , void *Data , void ( *TravelFx )( struct tutTreeNode *ThisNode , void *Data ) )
{
	if( RootNode == NULL )
		return ;
	
	struct tutTreeNode *ThisNode = RootNode ;
	
	Moving : 
	if( ThisNode->Left != NULL )
	{
		ThisNode = ThisNode->Left ;
		goto Moving ;
	}
	
	if( ThisNode->Right != NULL )
	{
		ThisNode = ThisNode->Right ;
		goto Moving ;
	}
	
	while( ThisNode->Super != NULL )
	{
		TravelFx( ThisNode , Data ) ;
		
		if( ThisNode->Super->Right != NULL && ThisNode->Super->Right != ThisNode )
		{
			ThisNode = ThisNode->Super->Right ;
			goto Moving ;
		}
		
		ThisNode = ThisNode->Super ;
	}
	
	// no nodes to visit
}

void tutBST_push( struct tutTreeNode **RootNode , struct tutTreeNodePool *NodePool , int Value )
{
	if( NodePool == NULL )
		return ;
	
	struct tutTreeNode *ThisNode = *RootNode , *SuperNode = NULL , **NewNodePointer = RootNode , *NewNode ;
	
	while( ThisNode != NULL )
	{
		SuperNode = ThisNode ;
		if( ThisNode->Value < Value )
			NewNodePointer = &ThisNode->Left ;
		else if( ThisNode->Value > Value )
			NewNodePointer = &ThisNode->Right ;
		else
			return ;
		ThisNode = *NewNodePointer ;
	}
	
	NewNode = tutTreeNodePool_allocate( NodePool ) ;
	if( NewNode == NULL )
		return ;
	NewNode->Value = Value ;
	NewNode->Degree = 0 ;
	NewNode->Super = SuperNode ;
	NewNode->Sub = NULL ;
	NewNode->Left = NULL ;
	NewNode->Right = NULL ;
	
	*NewNodePointer = NewNode ;
	if( SuperNode != NULL )
		SuperNode->Degree ++ ;
}
void tutBST_pop( struct tutTreeNode **RootNode , struct tutTreeNodePool *NodePool )
{
	if( *RootNode == NULL || NodePool == NULL )
		return ;
}
