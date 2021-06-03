#include "tutLinearNode.h"

struct tutLinearNodePool* tutLinearNodePool_create( int MaxCount )
{
	struct tutLinearNodePool *NewLinearNodePool = ( struct tutLinearNodePool* )malloc( sizeof( struct tutLinearNodePool ) ) ;
	if( NewLinearNodePool == NULL )
		return NULL ;
		
	NewLinearNodePool->MaxCount = MaxCount ;
	NewLinearNodePool->FirstAddress = ( struct tutLinearNode* )malloc( MaxCount * sizeof( struct tutLinearNode ) ) ;
	if( NewLinearNodePool->FirstAddress == NULL )
	{
		free( NewLinearNodePool ) ;
		return NULL ;
	}
	NewLinearNodePool->LastAddress = NewLinearNodePool->FirstAddress + ( MaxCount - 1 ) ;
	NewLinearNodePool->LinearNodeStack = ( struct tutLinearNode** )malloc( MaxCount * sizeof( struct tutLinearNode* ) ) ;
	if( NewLinearNodePool->LinearNodeStack == NULL )
	{
		free( NewLinearNodePool->FirstAddress ) ;
		free( NewLinearNodePool ) ;
		return NULL ;
	}
	for( NewLinearNodePool->Count = 0 ; NewLinearNodePool->Count < MaxCount ; NewLinearNodePool->Count ++ )
		NewLinearNodePool->LinearNodeStack[ NewLinearNodePool->Count ] = NewLinearNodePool->FirstAddress + NewLinearNodePool->Count ;
	
	return NewLinearNodePool ;
}
void tutLinearNodePool_delete( struct tutLinearNodePool* LinearNodePool )
{
	if( LinearNodePool == NULL )
		return ;
	
	free( LinearNodePool->LinearNodeStack ) ;
	free( LinearNodePool->FirstAddress ) ;
	free( LinearNodePool ) ;
}

struct tutLinearNode* tutLinearNodePool_allocate( struct tutLinearNodePool* LinearNodePool )
{
	if( LinearNodePool == NULL || LinearNodePool->Count <= 0 )
		return NULL ;
	
	LinearNodePool->Count -- ;
	return LinearNodePool->LinearNodeStack[ LinearNodePool->Count ] ;
}
void tutLinearNodePool_deallocate( struct tutLinearNodePool* LinearNodePool , struct tutLinearNode *UsedLinearNode )
{
	if( LinearNodePool == NULL || LinearNodePool->Count >= LinearNodePool->MaxCount )
		return ;
	
	LinearNodePool->LinearNodeStack[ LinearNodePool->Count ] = UsedLinearNode ;
	LinearNodePool->Count ++ ;
}
