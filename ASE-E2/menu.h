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

#define CMD_MAX_LEN 128
#define DESC_LEN    1024
#define CMD_NUM     10

typedef struct DataNode
{
    char*   cmd;
    char*   desc;
    struct  DataNode *next;
} tDataNode;

/* show all the command */
int ShowAllCmd();

/* show the help list */
int HelpCmd();

/* show the information of writer */
int WriterCmd();

/* show the version of this program*/
int VersionCmd();

/* if user input a wrong command, show this */
int WrongCmd();

/* exit this program */
int ExitCmd();






