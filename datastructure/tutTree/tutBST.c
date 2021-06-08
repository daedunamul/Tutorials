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
	
	struct tutTreeNode *ThisNode = *RootNode , **ThisNodePointer = RootNode , *SuperNode = NULL , *NewNode ;
	
	while( ThisNode != NULL )
	{
		SuperNode = ThisNode ;
		if( Value < ThisNode->Value )
			ThisNodePointer = &ThisNode->Left ;
		else if( Value > ThisNode->Value )
			ThisNodePointer = &ThisNode->Right ;
		else
			return ;
		ThisNode = *ThisNodePointer ;
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
	
	*ThisNodePointer = NewNode ;
}
void tutBST_pop( struct tutTreeNode **RootNode , struct tutTreeNodePool *NodePool , int Value )
{
	if( *RootNode == NULL || NodePool == NULL )
		return ;
	
	struct tutTreeNode *ThisNode = *RootNode , **ThisNodePointer = RootNode , *CandidateNode ;
	
	do
	{
		if( Value < ThisNode->Value )
			ThisNodePointer = &ThisNode->Left ;
		else if( Value > ThisNode->Value )
			ThisNodePointer = &ThisNode->Right ;
		else
		{
			// picking candidate node
			if( ThisNode->Left == NULL )
			{
				*ThisNodePointer = ThisNode->Right ;
				if( ThisNode->Right != NULL )
					ThisNode->Right->Super = ThisNode->Super ;
			}
			else
			{
				for( CandidateNode = ThisNode->Left ; CandidateNode->Right != NULL ; CandidateNode = CandidateNode->Right ) ;
				
				if( CandidateNode != ThisNode->Left )
				{
					CandidateNode->Super->Right = CandidateNode->Left ;
					if( CandidateNode->Left != NULL )
						CandidateNode->Left->Super = CandidateNode->Super ;
					CandidateNode->Left = ThisNode->Left ;
				}
				CandidateNode->Right = ThisNode->Right ;
				CandidateNode->Super = ThisNode->Super ;
				ThisNode->Right->Super = CandidateNode ;
				*ThisNodePointer = CandidateNode ;
			}
			
			// deallocating this node
			tutTreeNodePool_deallocate( NodePool , ThisNode ) ;
		}
		
		ThisNode = *ThisNodePointer ;
	}
	while( ThisNode != NULL ) ;
}
