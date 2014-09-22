/**************************************************************************************************/
/*  Copyright (C) mc2lab.com, SSE@USTC, 2014-2015                                                 */
/*                                                                                                */
/*  FILE NAME             :  menu.c                                                               */
/*  PRINCIPAL AUTHOR      :  Lixiaolin                                                            */
/*  SUBSYSTEM NAME        :  ASE-E2                                                               */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  Linux                                                                */
/*  DATE OF FIRST RELEASE :  2014/09/21                                                           */
/*  DESCRIPTION           :  This is a menu program                                               */
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

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "linktable.h"

#define CMD_MAX_LEN 128

int out = 0;
char pInputCmd[CMD_MAX_LEN];
char* deleteCmd;

/*command struct*/
struct CmdNode
{
    tLinkNode *pNext;
    char* cmd;
    char* desc;
    int (*fPoint)();
};

/*menu struct*/
struct Menu
{
    tLinkTable *pMenuHead;
};

/*create a menu*/
tMenu* CreateMenu()
{
    tMenu *pNewMenu = (tMenu*)malloc(sizeof(tMenu));
    tLinkTable *pNewLinkTable = CreateLinkTable();
    pNewMenu->pMenuHead = pNewLinkTable;
    return pNewMenu;
}

/*create linked list node*/
tCmdNode* CreateCmdNode(char* pNodeCmd, char* pNodeDesc, int (*pNodeOpt)())
{
    tCmdNode *pNewNode;
    pNewNode = (tCmdNode*)malloc(sizeof(tCmdNode));
    if(pNewNode == NULL)
    {
        printf("\n\033[40;32mError: Command node create failed\033[5m\n");
        printf("\033[40;37m\033[5m");
        return NULL;
    }
    else
    {
        pNewNode->cmd = pNodeCmd;
        pNewNode->desc = pNodeDesc;
        pNewNode->fPoint = pNodeOpt;
    }
    return pNewNode;
}

/*add a command into menu*/
int AddCommand(tMenu *pMenu, char* pCommand, char* pDesc, int (*fPoint)())
{
    AddLinkNode(pMenu->pMenuHead, (tLinkNode *)CreateCmdNode(pCommand, pDesc, fPoint));
    return 0;
}

/*print all commands and their functions on screen*/
int ShowAllInfo(tMenu *pMenu)
{
    tLinkTable *pLinkTable = pMenu->pMenuHead;
    if(pLinkTable->linkNodeSize == 0)
    {
        return -1;
    }
    tCmdNode *pThisCmdNode;
    pThisCmdNode = (tCmdNode *)GetLinkTableFirst(pLinkTable);
    printf("\n");
    while(pThisCmdNode != NULL)
    {
        printf("\033[40;32m%s\t--->  %s\033[5m\n", pThisCmdNode->cmd, pThisCmdNode->desc);
        printf("\033[40;37m\033[5m");
        pThisCmdNode = (tCmdNode *)GetNextLinkNode(pLinkTable, (tLinkNode *)pThisCmdNode);
    }
    return 0;
}

/*the condition of search the matched command*/
int InputCondition(tLinkNode *pLinkNode)
{
    tCmdNode *pNode = (tCmdNode *)pLinkNode;
    if(!strcmp(pNode->cmd, pInputCmd))
    {
        return 1;  
    }
    return 0;	       
}

/*start the menu program*/
int MenuStart(tMenu *pMenu)
{
    printf("\n\033[40;32m******** Menu program start ********\033[5m\n");
    printf("\033[40;37m\033[5m");
    ShowAllInfo(pMenu);
    tCmdNode *pThisNode;
    while(1)
    {
        printf("\nPlease enter a command --->");
        scanf("%s", pInputCmd);
        if((pThisNode = (tCmdNode *)SearchLinkNode(pMenu->pMenuHead, InputCondition)) != NULL)
        {
            if(pThisNode->fPoint != NULL)
            {
                pThisNode->fPoint(pMenu);
            }
        }
        else
        {
            printf("\n\033[40;31mError: This is a wrong cmd!\033[5m\n");
            printf("\033[40;37m\033[5m");
	        continue;
        }
        if(out)
        {
            out = 0;
            break;           
        } 
    }
}

/*stop the menu program*/
int MenuStop(tMenu *pMenu)
{

    printf("\033[2J\033[0;0H");
    printf("\033[40;32m******** Exit Successfully ********\033[5m\n");
    printf("\033[40;37m\033[5m");
    out = 1;
}

/*the condition of delete the matched command*/
int DeleteCondition(tLinkNode *pLinkNode)
{
    tCmdNode *pNode = (tCmdNode *)pLinkNode;
    if(!strcmp(pNode->cmd, deleteCmd))
    {
        return 1;
    }
    return 0;
}

/*delete command named pCommand*/
int DeleteCommand(tMenu *pMenu, char* pCommand)
{

    deleteCmd = pCommand;
    tLinkNode *pLinkNode = SearchLinkNode(pMenu->pMenuHead, DeleteCondition);
    if(!DeleteLinkNode(pMenu->pMenuHead, pLinkNode))
    {
        printf("\n\033[40;32mDelete command (%s) success\033[5m\n\n", pCommand);
        printf("\033[40;37m\033[5m");
        return 0;
    }
    else
    {
        printf("\n\033[40;31mDelete command (%s) failed\033[5m\n\n", pCommand);
        printf("\033[40;37m\033[5m");
        return -1;
    }
}

/*delete menu*/
int DeleteMenu(tMenu *pMenu)
{
    if(!DeleteLinkTable(pMenu->pMenuHead))
    {
        printf("\n\033[40;32mDelete menu success\033[5m\n\n");
        printf("\033[40;37m\033[5m");
        free(pMenu);
        return 0;
    }
    else
    {
        printf("\n\033[40;31mDelete menu failed\033[5m\n\n");
        printf("\033[40;37m\033[5m");
        return -1;
    }
}
