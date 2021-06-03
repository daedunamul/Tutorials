#pragma once
#include <stdlib.h>

struct tutLinearNode
{
	int Value ;
	struct tutLinearNode *Left , *Right ;
} ;
struct tutLinearNodePool
{
	int MaxCount , Count ;
	struct tutLinearNode *FirstAddress , *LastAddress ;
	struct tutLinearNode **LinearNodeStack ;
} ;

struct tutLinearNodePool* tutLinearNodePool_create( int MaxCount ) ;
void tutLinearNodePool_delete( struct tutLinearNodePool* LinearNodePool ) ;

struct tutLinearNode* tutLinearNodePool_allocate( struct tutLinearNodePool* LinearNodePool ) ;
void tutLinearNodePool_deallocate( struct tutLinearNodePool* LinearNodePool , struct tutLinearNode *UsedLinearNode ) ;
