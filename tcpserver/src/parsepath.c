//
// Created by Illia Shkurenko on 25.05.17.
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "parsepath.h"
#include "workwithstrings.h"
enum {
    SIZE = 100
};
int returnFunctionFromPath(char *path, Result * res) {
    //check(path,res);
    if (EqualsOfStr(path, "/favorites ")) {
        return SENDFAVOURITES;

    } else if (EqualsOfStr(path, "/ ")) {
        return SENDSERVERINFORM;

    } else if (check(path,res)) {
        return SENDFAVKEVAL;

    } else if (EqualsOfStr(path, "/file ")) {
        return READFILE;

    } else if (EqualsOfStr(path, "/file/data ")) {
        return SENDFILEDATA;

    } else return NOTFOUND;
}

bool EqualsOfStr(char *str1, char *str2) {
    return strcmp(str1, str2) == 0;
}

bool EqualsOfInt(char *int1, int int2) {
    return atoi(int1) == int2;
}

bool check(char *path, Result * res) {
    char *ch = strchr(path, '?');
    if (ch != NULL && checkFavOnBegin(path, abs(ch - path))) {
        char *equals = strchr(path, '=');
        if (equals != NULL) {
            if(foundKey(path,abs(equals-path), abs(ch - path),res)){
                return true;
            }
        }
    }
    return false;
}

bool checkFavOnBegin(char *path, int index) {
    char *check = "/favorites";
    char *pathtoCheck = (char *) malloc(SIZE * sizeof(char));
    strcpy(pathtoCheck, path);
    clearString(pathtoCheck, index);
    return EqualsOfStr(pathtoCheck, check);

}

bool foundKey(char *path, int before, int after, Result * res) {
    char *pathtoCheck = (char *) malloc(SIZE * sizeof(char));
    char *pathtoCheckVal = (char *) malloc(SIZE * sizeof(char));
    strcpy(pathtoCheck, path);
    strcpy(pathtoCheckVal, path);
    clearStringFromBegin(pathtoCheckVal,before+1);
    clearStringFromBegin(pathtoCheck,strlen("/favorites")+1);
    clearString(pathtoCheck,before - after-1);
    strcpy(res->name,pathtoCheck);
    strcpy(res->value,pathtoCheckVal);
    if(EqualsOfStr(res->name,"id") || EqualsOfStr(res->name,"index")){
        return checkValOnInt(res->value);
    } else if(EqualsOfStr(res->name,"name") || EqualsOfStr(res->name,"country")){
        return checkValOnIsAlpha(res->value);
    }
    return false;
}
bool checkValOnInt(char * str){
    for(int i = 0; i < strlen(str)-1; i++){
        if(isalpha(str[i])){
            return false;
        }
    }
    return true;
}

bool checkValOnIsAlpha(char * str){
    for(int i = 0; i < strlen(str)-1; i++){
        if(!isalpha(str[i])){
            return false;
        }
    }
    return true;
}