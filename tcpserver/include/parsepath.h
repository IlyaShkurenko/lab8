//
// Created by Illia Shkurenko on 25.05.17.
//
/** @file
    @brief functions to parse url
*/
#include <stdbool.h>
#include "result.h"

#ifndef TCP_PARSEPATH_H
#define TCP_PARSEPATH_H
enum {
    NOTFOUND = 0, SENDSERVERINFORM = 1, SENDFAVOURITES = 2, SENDFAVKEVAL = 3, READFILE = 4, SENDFILEDATA = 5, SENDFAVFORID = 6

/**
    @brief returning needed function
    @returns int val of function

*/

};
int returnFunctionFromPath(char * path, Result * res);

/**
    @returns true if strings are equals

*/

bool EqualsOfStr(char *str1, char *str2);
/**
    @returns true if ints are equals

*/

bool EqualsOfInt(char *int1, int int2);

/**
    @brief check path on valid

*/

bool check(char * path, Result * res);
/**
    @returns true if first parth of url is /favorites

*/

bool checkFavOnBegin(char * path, int index);

/**
    @returns true if key was find

*/

bool foundKey(char *path, int before, int after, Result * res);

/**
    @returns true if string doesn't have any symbol

*/


bool checkValOnInt(char * str);

/**
    @returns true if string doesn't have any digit

*/

bool checkValOnIsAlpha(char * str);
#endif //TCP_PARSEPATH_H
