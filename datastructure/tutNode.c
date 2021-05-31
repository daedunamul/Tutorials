#include "tutNode.h"

struct tutNodePool* tutNodePoolcreate( int MaxCount )
{
	struct tutNodePool *NewNodePool = ( struct tutNodePool* )malloc( sizeof( struct tutNodePool ) ) ;
	if( NewNodePool == NULL )
		return NULL ;
		
	NewNodePool->MaxCount = MaxCount ;
	NewNodePool->FirstAddress = ( struct tutNode* )malloc( MaxCount * sizeof( struct tutNode ) ) ;
	if( NewNodePool->FirstAddress == NULL )
	{
		free( NewNodePool ) ;
		return NULL ;
	}
	NewNodePool->LastAddress = NewNodePool->FirstAddress * ( MaxCount - 1 ) ;
	NewNodePool->NodeStack = ( struct tutNode** )malloc( MaxCount * sizeof( struct tutNode* ) ) ;
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
void tutNodePooldelete( struct tutNodePool* NodePool )
{
	if( NodePool == NULL )
		return ;
	
	free( NodePool->NodeStack ) ;
	free( NodePool->FirstAddress ) ;
	free( NodePool ) ;
}

struct tutNode* tutNodePoolallocate( struct tutNodePool* NodePool )
{
	if( NodePool == NULL || NodePool->Count <= 0 )
		return NULL ;
	
	NodePool->Count -- ;
	return NodePool->NodeStack[ NodePool->Count ] ;
}
void tutNodePooldeallocate( struct tutNodePool* NodePool , struct tutNode *UsedNode )
{
	if( NodePool == NULL || NodePool->Count >= NodePool->MaxCount )
		return NULL ;
	
	NodePool->NodeStack[ NodePool->Count ] = UsedNode ;
	NodePool->Count ++ ;
}
