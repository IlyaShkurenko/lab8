//
// Created by Illia Shkurenko on 26.05.17.
//

#include <string.h>
#include <parsepath.h>
#include <jsonparser.h>
#include <fileparser.h>
#include <fav.h>
#include "choosefunction.h"
void choose(List* list, Result*res, char* strToCopy, char * content, char* json){
    char * str = "HTTP/1.1 404 \n"
            "Content-Length: 880000 \n"
            "Content-Type: text/html \n"
            "<!DOCTYPE HTML\n"
            "<html>\n"
            " <head>\n"
            "  <meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">\n"
            "  <title>NOT found</title>\n"
            " </head>\n"
            " <body>\n"
            "\n"
            "  <H1 style=\"font-size: 200%; text-align: center; font-family: Verdana, Arial, Helvetica, sans-serif; color: red\">\n"
            "  404 NOT FOUND</H1>\n"
            "\n";
    " </body>\n"
            "</html>";
    char * status = (char*)malloc(BUF_SIZE*100* sizeof(char));
    int function = returnFunctionFromPath(strToCopy,res);
    memset(json,0,strlen(json));
    if(function == SENDSERVERINFORM){
        JsonInfo(json);
    } else if(function == SENDFAVOURITES){
        JsonList(list,json);
    } else if(function == SENDFAVKEVAL){
        JsonListUnderList(list,json,res);
    } else if(function == READFILE){
        getInfoFromFile(json);
    } else if(function == SENDFILEDATA){
        getJsonWithDigits(json);
    }
    printf("%i\n",strlen(json));
    if(function == NOTFOUND || strlen(json) == 21){
        strcpy(status,"HTTP/1.1 404 NOT FOUND");
    } else strcpy(status,"HTTP/1.1 200 OK");
    sprintf(content,"%s \n"
            "Server: Apache/2.2.14 (Win32) \n"
            "Last-Modified: Wed, 22 Jul 2009 19:15:56 GMT \n"
            "Content-Length: 10000 \n"
            "Content-Type: text \n"
            "Connection: Closed \n",status);
    strcat(content,json);
    if(function == NOTFOUND || strlen(json) == 21){
        strcpy(json,str);
    }
}