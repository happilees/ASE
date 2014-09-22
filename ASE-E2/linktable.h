/**************************************************************************************************/
/*  Copyright (C) mc2lab.com, SSE@USTC, 2014-2015                                                 */
/*                                                                                                */
/*  FILE NAME             :  menu.h                                                               */
/*  PRINCIPAL AUTHOR      :  Lixiaolin                                                            */
/*  SUBSYSTEM NAME        :  ASE-E2                                                               */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  Linux                                                                */
/*  DATE OF FIRST RELEASE :  2014/09/21                                                           */
/*  DESCRIPTION           :  This is a linktable.h                                                */
/**************************************************************************************************/

/**************************************************************************************************/
/*                                                                                                */
/*                              Please open the RAW by IE Browser                                 */
/*                                                                                                */
/**************************************************************************************************/

/*
 * Revision log : 
 *
 * Coding by Lixiaolin, 2014/09/21
 *
 */

/*
 * linked list node struct
 */
typedef struct LinkNode
{
    struct LinkNode *pNext;
} tLinkNode;

/*
 * linked list table struct
 */
typedef struct LinkTable
{
    tLinkNode *pHead;
    tLinkNode *pTail;
    int linkNodeSize;
} tLinkTable;

/*
 * create a linked list table
 */
tLinkTable* CreateLinkTable();

/*
 * delete the linked list table
 */
int DeleteLinkTable(tLinkTable *pLinkTable);

/*
 * add a node into linked list
 */
int AddLinkNode(tLinkTable *pLinkTable, tLinkNode *pNode);

/*
 * delete a node in linked list
 */
int DeleteLinkNode(tLinkTable *pLinkTable, tLinkNode *pNode);

/*
 * search a linked list node with condition
 */
tLinkNode* SearchLinkNode(tLinkTable *pLinkTable, int Condition(tLinkNode *pNode));

/*
 * get next linked list node
 */
tLinkNode* GetNextLinkNode(tLinkTable *pLinkTable, tLinkNode *pNode);

/*
 * get first node in linked list table
 */
tLinkNode* GetLinkTableFirst(tLinkTable *pLinkTable);
