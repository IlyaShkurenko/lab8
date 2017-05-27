//
// Created by Illia Shkurenko on 25.05.17.
//
/** @file
    @brief json parsing
*/
#ifndef TCP_JSONPARSER_H
#define TCP_JSONPARSER_H

#include <list.h>
#include <jansson.h>
#include "result.h"

enum {
    ID = 1, INDEX = 2, NAME = 3, COUNTRY = 4
};
/**
    @brief writes in string information about server in json format

*/
void JsonInfo(char* str);

/**
    @brief write in json data from list

*/

void JsonList(List * list,char * str);

/**
    @brief creating sub-listings and ad it to json

*/

void JsonListUnderList(List * list, char * str, Result * res);

/**
    @brief aditing to json information about text file

*/

void jsonWithFileInfo(char *jsonString, char *str );

/**
    @brief adding to json array of digits from text file

*/

void jsonWithArrayofDigits(char *str, List * list);

/**
    @brief creating json document
    @param list - list that converts to json string

*/

void jsonSaveToString(List * list, char * text);
#endif //TCP_JSONPARSER_H
