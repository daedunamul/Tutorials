#pragma once
#include <stdlib.h>

struct tutNode
{
	int Value ;
	struct tutNode *Left , *Right ;
} ;
struct tutNodePool
{
	int MaxCount , Count ;
	struct tutNode *FirstAddress , *LastAddress ;
	struct tutNode **NodeStack ;
} ;

struct tutNodePool* tutNodePoolcreate( int MaxCount ) ;
void tutNodePooldelete( struct tutNodePool* NodePool ) ;

struct tutNode* tutNodePoolallocate( struct tutNodePool* NodePool ) ;
void tutNodePooldeallocate( struct tutNodePool* NodePool , struct tutNode *UsedNode ) ;
