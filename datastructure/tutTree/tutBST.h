#pragma once
#include "tutTreeNode.h"
#include <stdbool.h>

enum tutBSTMethod
{
	tutBSTMethodPreorder = 0 , 
	tutBSTMethodInorder , 
	tutBSTMethodPostorder 
} ;

void tutBST_travel( struct tutTreeNode *RootNode , void *Data , enum tutBSTMethod Method , void ( *TravelFx )( struct tutTreeNode *ThisNode , void *Data ) ) ;

void tutBST_push( struct tutTreeNode *ThisNode , bool Flag , struct tutTreeNodePool *NodePool , int Value ) ;
void tutBST_pop( struct tutTreeNode *ThisNode , bool Flag , struct tutTreeNodePool *NodePool ) ;
