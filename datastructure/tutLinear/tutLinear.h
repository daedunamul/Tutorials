#pragma once
#include "tutLinearNode.h"

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
	struct tutLinearNode *FirstLinearNode , *LastLinearNode ;
} ;

int tutLinear_pushFirstNode( struct tutLinear *Linear , struct tutLinearNode *NewLinearNode ) ;
int tutLinear_pushLastNode( struct tutLinear *Linear , struct tutLinearNode *NewLinearNode ) ;
int tutLinear_popFirstNode( struct tutLinear *Linear , struct tutLinearNode **UsedLinearNode ) ;
int tutLinear_popLastNode( struct tutLinear *Linear , struct tutLinearNode **UsedLinearNode ) ;
