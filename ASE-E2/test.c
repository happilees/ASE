/**************************************************************************************************/
/*  Copyright (C) mc2lab.com, SSE@USTC, 2014-2015                                                 */
/*                                                                                                */
/*  FILE NAME             :  test.c                                                               */
/*  PRINCIPAL AUTHOR      :  Lixiaolin                                                            */
/*  SUBSYSTEM NAME        :  ASE-E2                                                               */
/*  MODULE NAME           :  test                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  Linux                                                                */
/*  DATE OF FIRST RELEASE :  2014/09/21                                                           */
/*  DESCRIPTION           :  This is a test program for menu                                      */
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

#include "menu.h"

main()
{
    /* show all command at the begin of this program */
    ShowAllCmd();

    while(1)
    {
        /* get a command */
        char cmdin[CMD_MAX_LEN];
        printf("Please input a cmd ---> ");
        scanf("%s", cmdin);
        
        /* distinguish the command */
        if(!strcmp("help", cmdin))
        {
            HelpCmd();
        }
        else if(!strcmp("exit", cmdin))
        { 
            ExitCmd();
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






