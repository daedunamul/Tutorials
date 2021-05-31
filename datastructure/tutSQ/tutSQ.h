#pragma once
#include "tutNode.h"

enum tutSQStatus
{
	tutSQStatusOk = 0 , 
	tutSQStatusOverflow , 
	tutSQStatusUnderflow , 
	tutSQStatusNullPointer 
} ;

struct tutSQ
{
	int MaxCount , Count ;
	struct tutNode *TopNode ;
} ;

int tutSQpushLikeStack( struct tutSQ *SQ , struct tutNode *NewNode ) ;
int tutSQpopLikeStack( struct tutSQ *SQ , struct tutNode **UsedNode ) ;
