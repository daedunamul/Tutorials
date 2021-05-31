#include "tutLinear.h"

int tutLinear_pushFirstNode( struct tutLinear *Linear , struct tutLinearNode *NewLinearNode )
{
	if( Linear == NULL || NewLinearNode == NULL )
		return tutLinearStatusNullPointer ;
	else if( Linear->Count >= Linear->MaxCount )
		return tutLinearStatusOverflow ;
	
	NewLinearNode->Left = NULL ;
	NewLinearNode->Right = Linear->FirstNode ;
	if( Linear->FirstNode == NULL )
	{
		Linear->FirstNode = NewLinearNode ;
		Linear->LastNode = NewLinearNode ;
	}
	else
	{
		Linear->FirstNode->Left = NewLinearNode ;
		Linear->FirstNode = NewLinearNode ;
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
	
	NewLinearNode->Left = Linear->LastNode ;
	NewLinearNode->Right = NULL ;
	if( Linear->LastNode == NULL )
	{
		Linear->FirstNode = NewLinearNode ;
		Linear->LastNode = NewLinearNode ;
	}
	else
	{
		Linear->LastNode->Right = NewLinearNode ;
		Linear->LastNode = NewLinearNode ;
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
	
	UsedLinearNode = &Linear->FirstNode ;
	Linear->FirstNode = Linear->FirstNode->Right ;
	if( Linear->FirstNode == NULL )
		Linear->LastNode = NULL ;
	else
		Linear->FirstNode->Left = NULL ;
	Linear->Count -- ;
	
	return tutLinearStatusOk ;
}
int tutLinear_popLastNode( struct tutLinear *Linear , struct tutLinearNode **UsedLinearNode )
{
	if( Linear == NULL || UsedLinearNode == NULL )
		return tutLinearStatusNullPointer ;
	else if( Linear->Count <= 0 )
		return tutLinearStatusUnderflow ;
	
	UsedLinearNode = &Linear->LastNode ;
	Linear->LastNode = Linear->LastNode->Left ;
	if( Linear->LastNode == NULL )
		Linear->FirstNode = NULL ;
	else
		Linear->LastNode->Right = NULL ;
	Linear->Count -- ;
	
	return tutLinearStatusOk ;
}
