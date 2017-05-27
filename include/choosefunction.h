//
// Created by Illia Shkurenko on 26.05.17.
//
/** @file
    @brief chose functions
*/
#include <list.h>
#include <result.h>

#ifndef TCP_CHOOSEFUNCTION_H
#define TCP_CHOOSEFUNCTION_H
/**
    @brief Function to choose command from path
    @param list - list of elements that will be converdet in json
    @param res - struct of result
    @param strToCopy - string that contains message
    @param content - content
    @param json - string with json object
*/
void choose(List* list, Result*res, char* strToCopy, char * content, char* json);

#endif //TCP_CHOOSEFUNCTION_H
