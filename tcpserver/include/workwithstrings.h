//
// Created by Illia Shkurenko on 25.05.17.
//
/** @file
    @brief functions to work with strings
*/
#ifndef TCP_WORKWITHSTRINGS_H
#define TCP_WORKWITHSTRINGS_H
/**
    @brief clearing strings
    @param str - string that will be cleared
    @param index - from this index will deleted another part of string

*/

void clearString(char* str, int index);

/**
    @brief clearing first part of string
    @param str - string that will be cleared
    @param index - from 0 to index will bbe cleared string

*/

void clearStringFromBegin(char * str, int count);

/**
    @brief function that compares strings and returns key
    @returns int value that will be used to use needed function

*/

int returnKey(char* str);
#endif //TCP_WORKWITHSTRINGS_H
