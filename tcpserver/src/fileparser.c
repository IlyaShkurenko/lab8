//
// Created by Illia Shkurenko on 26.05.17.
//

#include <stdio.h>
#include <convert.h>
#include <string.h>
#include <ctype.h>
#include "fileparser.h"
#include "jsonparser.h"
void getInfoFromFile(char * str){
    char *content = (char *) malloc(BUF_SIZE * 100 * sizeof(char));
    getContentFromFile(content);
    jsonWithFileInfo(str,content);
    free(content);
}

void getJsonWithDigits(char * str) {
    char *text = (char*)malloc(BUF_SIZE* sizeof(char));
    getContentFromFile(text);
    List * list = List_new();
    int length = strlen(text);
    int textIndex = 0;

    for (textIndex = 0; textIndex < length; textIndex++) {
        char ch = text[textIndex];
        char nextCh = text[textIndex + 1];
        if (isdigit(ch) || ('-' == ch && isdigit(nextCh))) {
            int number = atoi(text + textIndex);
            int count = sizeof(number);
            List_add(list,number);
            puts("");
            textIndex += count - 1;
        }
    }
    free(text);
   jsonWithArrayofDigits(str,list);
}
void getContentFromFile(char * content){
    char *buf = (char *) malloc(BUF_SIZE * sizeof(char));
    char* filepath = "data/data";
    FILE *fout = fopen(filepath, "r");
    if (fout) {
        while (fgets(buf, BUF_SIZE, fout) != NULL) {
            strcat(content,buf);
        }
    } else {
        puts("File wasn't open\n");
    }
    free(buf);
    fclose(fout);
}


