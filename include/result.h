//
// Created by Illia Shkurenko on 26.05.17.
//
/** @file
    @brief struct result
*/
#ifndef TCP_RESULT_H
#define TCP_RESULT_H
/**
    @struct Result
    @brief defines a key and key value from URL
*/
struct Result {
    char name[100];
    char value[100];
};

typedef struct Result Result;

/**
    @brief Result constructor
*/

Result *Result_new(char *name, char *value);

void Result_free(Result **selfPtr);
#endif //TCP_RESULT_H
