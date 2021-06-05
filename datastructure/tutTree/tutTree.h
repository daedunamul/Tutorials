#pragma once
#include "tutTreeNode.h"

void tutTree_traverse( struct tutTreeNode *RootNode , void ( *TraversalFx )( struct tutTreeNode *ThisNode , void *Data ) ) ;

void tutTree_push( struct tutTreeNode *ThisNode , struct tutTreeNodePool *NodePool , int Value ) ;
void tutTree_pop( struct tutTreeNode *ThisNode , void *Data ) ;
