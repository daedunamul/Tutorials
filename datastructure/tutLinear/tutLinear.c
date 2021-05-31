#include "tutLinear.h"

int tutLinear_pushFirstNode( struct tutLinear *Linear , struct tutLinearNode *NewLinearNode )
{
	if( Linear == NULL || NewLinearNode == NULL )
		return tutLinearStatusNullPointer ;
	else if( Linear->Count >= Linear->MaxCount )
		return tutLinearStatusOverflow ;
	
	NewLinearNode->Left = NULL ;
	NewLinearNode->Right = Linear->FirstLinearNode ;
	if( Linear->FirstLinearNode == NULL )
	{
		Linear->FirstLinearNode = NewLinearNode ;
		Linear->LastLinearNode = NewLinearNode ;
	}
	else
	{
		Linear->FirstLinearNode->Left = NewLinearNode ;
		Linear->FirstLinearNode = NewLinearNode ;
	}
	Linear->Count ++ ;
	
	return tutLinearStatusOk ;
}
int tutLinear_pushLastNode( struct tutLinear *Linear , struct tutLinearNode *NewLinearNode )
{
	if( Linear == NULL || NewLinearNode == NULL )
		return tutLinearStatusNullPointer ;
	else if( Linear->Count >= Linear->MaxCount )
		return tutLinearStatusOverflow ;
	
	NewLinearNode->Left = Linear->LastLinearNode ;
	NewLinearNode->Right = NULL ;
	if( Linear->LastLinearNode == NULL )
	{
		Linear->FirstLinearNode = NewLinearNode ;
		Linear->LastLinearNode = NewLinearNode ;
	}
	else
	{
		Linear->LastLinearNode->Right = NewLinearNode ;
		Linear->LastLinearNode = NewLinearNode ;
	}
	Linear->Count ++ ;
	
	return tutLinearStatusOk ;
}
int tutLinear_popFirstNode( struct tutLinear *Linear , struct tutLinearNode **UsedLinearNode )
{
	if( Linear == NULL || UsedLinearNode == NULL )
		return tutLinearStatusNullPointer ;
	else if( Linear->Count <= 0 )
		return tutLinearStatusUnderflow ;
	
	UsedLinearNode = &Linear->FirstLinearNode ;
	Linear->FirstLinearNode = Linear->FirstLinearNode->Right ;
	if( Linear->FirstLinearNode == NULL )
		Linear->LastLinearNode = NULL ;
	else
		Linear->FirstLinearNode->Left = NULL ;
	Linear->Count -- ;
	
	return tutLinearStatusOk ;
}
int tutLinear_popLastNode( struct tutLinear *Linear , struct tutLinearNode **UsedLinearNode )
{
	if( Linear == NULL || UsedLinearNode == NULL )
		return tutLinearStatusNullPointer ;
	else if( Linear->Count <= 0 )
		return tutLinearStatusUnderflow ;
	
	UsedLinearNode = &Linear->LastLinearNode ;
	Linear->LastLinearNode = Linear->LastLinearNode->Left ;
	if( Linear->LastLinearNode == NULL )
		Linear->FirstLinearNode = NULL ;
	else
		Linear->LastLinearNode->Right = NULL ;
	Linear->Count -- ;
	
	return tutLinearStatusOk ;
}
