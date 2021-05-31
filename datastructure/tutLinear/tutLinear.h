#pragma once
#include "../tutNode.h"

enum tutLinearStatus
{
	tutLinearStatusOk = 0 , 
	tutLinearStatusOverflow , 
	tutLinearStatusUnderflow , 
	tutLinearStatusNullPointer 
} ;

struct tutLinear
{
	int MaxCount , Count ;
	struct tutNode *FirstNode , *LastNode ;
} ;

int tutLinear_pushFirstNode( struct tutLinear *Linear , struct tutNode *NewNode ) ;
int tutLinear_pushLastNode( struct tutLinear *Linear , struct tutNode *NewNode ) ;
int tutLinear_popFirstNode( struct tutLinear *Linear , struct tutNode **UsedNode ) ;
int tutLinear_popLastNode( struct tutLinear *Linear , struct tutNode **UsedNode ) ;
