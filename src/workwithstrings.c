//
// Created by Illia Shkurenko on 25.05.17.
//

#include <string.h>
#include <stdio.h>
#include "workwithstrings.h"
#include "parsepath.h"
#include "jsonparser.h"
void clearString(char* str, int index){
    int count = 0;
    int j = 0;
    for(int i = index; i < strlen(str); i++){
        str[i] = '\0';
    }

}

void clearStringFromBegin(char * str, int count){
    for(int k = 0; k < count; k++) {

        for (int i = 0; i < strlen(str); i++) {
            str[i] = str[i+1];
        }
    }
}
 int returnKey(char* str){
     if(EqualsOfStr(str,"id")){
         return ID;
     } else if(EqualsOfStr(str,"index")){
         return INDEX;
     } else if(EqualsOfStr(str,"name")){
         return NAME;
     } else if(EqualsOfStr(str,"country")){
         return COUNTRY;
     }
 }