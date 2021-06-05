#include "tutTreeNode.h"

struct tutTreeNodePool* tutTreeNodePool_create( int MaxCount )
{
	struct tutTreeNodePool *NewNodePool = ( struct tutTreeNodePool* )malloc( sizeof( struct tutTreeNodePool ) ) ;
	if( NewNodePool == NULL )
		return NULL ;
		
	NewNodePool->MaxCount = MaxCount ;
	NewNodePool->FirstAddress = ( struct tutTreeNode* )malloc( MaxCount * sizeof( struct tutTreeNode ) ) ;
	if( NewNodePool->FirstAddress == NULL )
	{
		free( NewNodePool ) ;
		return NULL ;
	}
	NewNodePool->LastAddress = NewNodePool->FirstAddress + ( MaxCount - 1 ) ;
	NewNodePool->NodeStack = ( struct tutTreeNode** )malloc( MaxCount * sizeof( struct tutTreeNode* ) ) ;
	if( NewNodePool->NodeStack == NULL )
	{
		free( NewNodePool->FirstAddress ) ;
		free( NewNodePool ) ;
		return NULL ;
	}
	for( NewNodePool->Count = 0 ; NewNodePool->Count < MaxCount ; NewNodePool->Count ++ )
		NewNodePool->NodeStack[ NewNodePool->Count ] = NewNodePool->FirstAddress + NewNodePool->Count ;
	
	return NewNodePool ;
}
void tutTreeNodePool_delete( struct tutTreeNodePool *NodePool )
{
	if( NodePool == NULL )
		return ;
	
	free( NodePool->NodeStack ) ;
	free( NodePool->FirstAddress ) ;
	free( NodePool ) ;
}

struct tutTreeNode* tutTreeNodePool_allocate( struct tutTreeNodePool *NodePool )
{
	if( NodePool == NULL || NodePool->Count <= 0 )
		return NULL ;
	
	NodePool->Count -- ;
	return NodePool->NodeStack[ NodePool->Count ] ;
}
void tutTreeNodePool_deallocate( struct tutTreeNodePool *NodePool , struct tutTreeNode *UsedNode )
{
	if( NodePool == NULL || NodePool->Count >= NodePool->MaxCount )
		return ;
	
	NodePool->NodeStack[ NodePool->Count ] = UsedNode ;
	NodePool->Count ++ ;
}
