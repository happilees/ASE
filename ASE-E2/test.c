/**************************************************************************************************/
/*  Copyright (C) mc2lab.com, SSE@USTC, 2014-2015                                                 */
/*                                                                                                */
/*  FILE NAME             :  test.c                                                               */
/*  PRINCIPAL AUTHOR      :  Lixiaolin                                                            */
/*  SUBSYSTEM NAME        :  ASE-E2                                                               */
/*  MODULE NAME           :  menu                                                                 */
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
#include <stdlib.h>
#include "menu.h"

int VersionInfo(tMenu *pMenu);
int WriterInfo(tMenu *pMenu);

int main()
{
    tMenu *pMenu = CreateMenu();
    
    AddCommand(pMenu, "help", "Show all the command can be used", ShowAllInfo);
    AddCommand(pMenu, "writer", "Show the information of writer", WriterInfo);
    AddCommand(pMenu, "version", "Show the version of this program", VersionInfo);
    AddCommand(pMenu, "exit", "Exit this program", MenuStop);
    
    MenuStart(pMenu);
    
    DeleteCommand(pMenu, "version");
    
    MenuStart(pMenu);
    
    DeleteMenu(pMenu);
    
    return 0;
}

int VersionInfo(tMenu *pMenu)
{
    printf("\n\033[40;32mThis is menu program V1.0\033[5m\n");
    printf("\033[40;37m\033[5m");
    return 0;
}

int WriterInfo(tMenu *pMenu)
{
    printf("\n\033[40;32mThis code write by Lixiaolin\033[5m\n");
    printf("\033[40;37m\033[5m");
    return 0;
}


