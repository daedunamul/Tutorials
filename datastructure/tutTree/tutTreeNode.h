#pragma once
#include <stdlib.h>

struct tutTreeNode
{
	int Value , MaxDegree , Degree ;
	struct tutTreeNode *Super , *Sub , *Left , *Right ;
} ;
struct tutTreeNodePool
{
	int MaxCount , Count ;
	struct tutTreeNode *FirstAddress , *LastAddress ;
	struct tutTreeNode **NodeStack ;
} ;

struct tutTreeNodePool* tutTreeNodePool_create( int MaxCount ) ;
void tutTreeNodePool_delete( struct tutTreeNodePool *NodePool ) ;

struct tutTreeNode* tutTreeNodePool_allocate( struct tutTreeNodePool *NodePool ) ;
void tutTreeNodePool_deallocate( struct tutTreeNodePool *NodePool , struct tutTreeNode *UsedNode ) ;
