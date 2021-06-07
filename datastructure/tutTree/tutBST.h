#pragma once
#include "tutTreeNode.h"
#include <stdbool.h>

void tutBST_preorder( struct tutTreeNode *RootNode , void *Data , void ( *TravelFx )( struct tutTreeNode *ThisNode , void *Data ) ) ;
void tutBST_inorder( struct tutTreeNode *RootNode , void *Data , void ( *TravelFx )( struct tutTreeNode *ThisNode , void *Data ) ) ;
void tutBST_postorder( struct tutTreeNode *RootNode , void *Data , void ( *TravelFx )( struct tutTreeNode *ThisNode , void *Data ) ) ;

void tutBST_push( struct tutTreeNode *ThisNode , bool Flag , struct tutTreeNodePool *NodePool , int Value ) ;
void tutBST_pop( struct tutTreeNode *ThisNode , bool Flag , struct tutTreeNodePool *NodePool ) ;
