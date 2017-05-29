//
// Created by Illia Shkurenko on 25.05.17.
//

#include <string.h>
#include "jsonparser.h"
#include <time.h>
#include <stdio.h>
#include <jsonstorage.h>
#include "findelements.h"
#include "workwithstrings.h"
#include "fav.h"

void JsonInfo(char *str){
    time_t rawtime;
    struct tm *info;
    char buffer[80];
    time( &rawtime );
    info = localtime( &rawtime );
    strftime(buffer, 80, "%x - %I:%M%p", info);
    sprintf(str,"{\n"
                    "    \"title\": \"Server\", \n"
                    "    \"developer\": \"Ilya Shkurenko\", \n"
                    "    \"time\": \"%s\"\n"
                    "}",buffer);

}

void JsonList(List * list, char * str){

    jsonSaveToString(list,str);
}

void JsonListUnderList(List * list, char * str,Result * res){
    List *list2 = List_new();
    int key = returnKey(res->name);
    for(int i = 0; i < List_count(list2); i++){
        List_free(List_get(list,i));
    }
    if(key != NOTFOUND){}
    for (int i = 0; i < List_count(list); i++) {
        Composition *set = List_get(list, i);
        if(findElement(set,res->value,key)){
            List_add(list2,set);
        }
    }
    jsonSaveToString(list2,str);

}

void jsonWithFileInfo(char *jsonString, char *str ){
    json_t * json = json_object();
    json_object_set_new(json, "name", json_string("data.txt"));
    json_object_set_new(json, "length", json_integer((int)strlen(str)* sizeof(char)));
    json_object_set_new(json, "content", json_string(str));
    // create JSON document string
    char * jsonStrhere = json_dumps(json, JSON_INDENT(2));
    strcpy(jsonString,jsonStrhere);
    free(jsonStrhere);
    // decrease reference count (free's memory when count is 0')
    json_decref(json);
}

void jsonWithArrayofDigits(char *str, List * list){
    json_t * studObj;
    json_t * json = json_object();
    json_t * groupobj = json_array();
    json_object_set_new(json, "Digits", groupobj);
    for(int i = 0; i < List_count(list); i++) {
       // studObj = json_object();
        int digit = (int)List_get(list, i);
        //json_object_set_new(groupobj, "digit", json_integer(digit));
        json_array_append(groupobj,json_integer(digit));
       // json_array_append(groupobj,studObj);
        // create JSON document string

    }
    char * jsonString = json_dumps(json, JSON_INDENT(2));
    strcat(str, jsonString);
    free(jsonString);
    // decrease reference count (free's memory when count is 0')
    json_decref(json);

}
void jsonSaveToString(List * list, char * text){
    // object construction
    char *str;
    json_t * studObj;
    str = malloc(1000*sizeof(char));
    json_t * json = json_object();
    json_t * groupobj = json_array();
    json_object_set_new(json, "Favorites", groupobj);
    for(int i = 0; i < List_count(list); i++) {
        studObj = json_object();
        Composition *st = List_get(list, i);
        json_object_set_new(studObj, "id", json_integer(st->lengthSeconds));
        json_object_set_new(studObj, "name", json_string(st->title));
        json_object_set_new(studObj, "country", json_string(st->place.place));
        json_object_set_new(studObj, "index", json_integer(st->place.index));
        json_array_append(groupobj,studObj);
        // create JSON document string

    }
    char *jsonString = json_dumps(json, JSON_INDENT(2));
    strcat(text, jsonString);
    free(jsonString);
    // decrease reference count (free's memory when count is 0')
    json_decref(json);
}