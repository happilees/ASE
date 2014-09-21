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

static tDataNode head[] = 
{
    {"help", "Show all cmd", &head[1]},
    {"exit", "Exit this program", &head[2]},
    {"writer", "Show the information of writer", &head[3]},
    {"version", "Show the version of this program", NULL}
};

int ShowAll(tDataNode * head)
{
    printf("\n\033[40;32mMenu List:\033[5m\n\n");
    tDataNode *p = head;
    while (p != NULL)
    {
        printf("\033[40;32m\t%s\t--->  %s\033[5m\n", p->cmd, p->desc);
        printf("\033[40;37m\033[5m");
        p = p->next;
    }
    printf("\n");
    return 0;
}

int ShowAllCmd()
{
    ShowAll(head);
};

int HelpCmd()
{
    ShowAll(head);
}

int WriterCmd()
{
    printf("\n\033[40;32mThis code write by Lixiaolin\033[5m\n\n");
    printf("\033[40;37m\033[5m");
    return 0;
}

int VersionCmd()
{
    printf("\n\033[40;32mThis is menu program V1.0\033[5m\n\n");
    printf("\033[40;37m\033[5m");
    return 0;
}

int WrongCmd()
{
    printf("\n\033[40;31mThis is a wrong cmd!\033[5m\n\n");
    printf("\033[40;37m\033[5m");
    return 0;
}

int ExitCmd()
{ 
    printf("\033[2J\033[0;0H");
    printf("\033[40;32m***Exit Successfully***\033[5m\n");
    printf("\033[40;37m\033[5m");
    exit(1);
    return 0;
}






