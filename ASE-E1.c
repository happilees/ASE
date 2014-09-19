/**************************************************************************************************/
/*  Copyright (C) mc2lab.com, SSE@USTC, 2014-2015                                                 */
/*                                                                                                */
/*  FILE NAME             :  ASE-E1.c                                                             */
/*  PRINCIPAL AUTHOR      :  Lixiaolin                                                            */
/*  SUBSYSTEM NAME        :  ASE-E1                                                               */
/*  MODULE NAME           :  ASE-E1                                                               */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  Linux                                                                */
/*  DATE OF FIRST RELEASE :  2014/09/12                                                           */
/*  DESCRIPTION           :  This is a simple menu program                                        */
/**************************************************************************************************/

/**************************************************************************************************/
/*                                                                                                */
/*                              Please open the RAW by IE Browser                                 */
/*                                                                                                */
/**************************************************************************************************/


/*
 * Revision log : add function of "exit"
 *
 * Coding by Lixiaolin, 2014/09/12
 *
 */


#include <stdio.h>
#include <stdlib.h>

#define CMD_MAX_LEN 128
#define DESC_LEN    1024
#define CMD_NUM     10

int exit_signal = 0;

typedef struct DataNode
{
    char*   cmd;
    char*   desc;
    struct  DataNode *next;
} tDataNode;

static tDataNode head[] = 
{
    {"help", "Show all cmd", &head[1]},
    {"exit", "Exit this program", &head[2]},
    {"writer", "Show the information of writer", &head[3]},
    {"version", "Show the version of this program", NULL}
};

/* Show the list of all the available command */

int ShowAllCmd(tDataNode * head)
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

int Exit()
{
    exit_signal = 1;
    printf("\033[2J\033[0;0H");
    printf("\033[40;32m***Exit Successfully***\033[5m\n");
    printf("\033[40;37m\033[5m");
    return 0;
}

main()
{
    ShowAllCmd(head);

    while(exit_signal == 0)
    {
        /* Get a command */
        char cmdin[CMD_MAX_LEN];
        printf("Please input a cmd ---> ");
        scanf("%s", cmdin);
        
        /* distinguish the command */
        if(!strcmp("help", cmdin))
        {
            ShowAllCmd(head);
        }
        else if(!strcmp("exit", cmdin))
        { 
            Exit();
        }
        else if(!strcmp("writer", cmdin))
        {
            WriterCmd();
        }
        else if(!strcmp("version", cmdin))
        {
            VersionCmd();
        }
        else
        {
            WrongCmd();
        }
    }
}






