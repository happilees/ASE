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
/*  DESCRIPTION           :  This is a menu.h                                                     */
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
 * command node struct
 */
typedef struct CmdNode tCmdNode;

/*
 * menu struct
 */
typedef struct Menu tMenu;

/*
 * create a menu
 */
tMenu* CreateMenu();

/*
 * add a command into menu
 */
int AddCommand(tMenu *pMenu, char* pCommand, char* pDesc, int (*pOpt)());

/*
 * print all commands and their functions on screen
 */
int ShowAllInfo(tMenu *pMenu);

/*
 * start the menu program
 */
int MenuStart(tMenu *Menu);

/*
 * stop the menu program
 */
int MenuStop(tMenu *pMenu);

/*
 * delete command named pCommand
 */
int DeleteCommand(tMenu *pMenu, char* pCommand);

/*
 * delete menu
 */
int DeleteMenu(tMenu *pMenu);
