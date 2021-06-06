#pragma once
#include "tutTreeNode.h"

void tutTree_travel( struct tutTreeNode *RootNode , void *Data , void ( *TravelFx )( struct tutTreeNode *ThisNode , void *Data ) ) ;

void tutTree_push( struct tutTreeNode *ThisNode , struct tutTreeNodePool *NodePool , int Value ) ;
void tutTree_pop( struct tutTreeNode *ThisNode , struct tutTreeNodePool *NodePool ) ;
void tutTree_flush( struct tutTreeNode *ThisNode , void *Data ) ;
