#include "tutBT.h"

void tutBT_preorder( struct tutTreeNode *RootNode , void *Data , void ( *TravelFx )( struct tutTreeNode *ThisNode , void *Data ) )
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
void tutBT_inorder( struct tutTreeNode *RootNode , void *Data , void ( *TravelFx )( struct tutTreeNode *ThisNode , void *Data ) )
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
	TravelFx( ThisNode , Data ) ;
	
	if( ThisNode->Right != NULL )
	{
		ThisNode = ThisNode->Right ;
		goto Moving ;
	}
	
	while( ThisNode->Super != NULL )
	{
		if( ThisNode->Super->Right != NULL && ThisNode->Super->Right != ThisNode )
		{
			TravelFx( ThisNode->Super , Data ) ;
			ThisNode = ThisNode->Super->Right ;
			goto Moving ;
		}
		else if( ThisNode->Super->Right == NULL )
			TravelFx( ThisNode->Super , Data ) ;
		
		ThisNode = ThisNode->Super ;
	}
	
	// no nodes to visit
}
void tutBT_postorder( struct tutTreeNode *RootNode , void *Data , void ( *TravelFx )( struct tutTreeNode *ThisNode , void *Data ) )
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
