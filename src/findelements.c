//
// Created by Illia Shkurenko on 26.05.17.
//

#include <string.h>
#include "findelements.h"
#include "jsonparser.h"
bool findElement(Composition *self, char * name, int find) {
   for(int i = 0; i < strlen(name);i++){
       if(name[i] == ' ') name[i] = '\0';
   }
    if (self != NULL) {
        if(find == NAME && EqualsOfStr(self->title,name)){
            return true;
        } else if(find == COUNTRY && EqualsOfStr(self->place.place,name)){
            return true;
        } else if(find == ID && EqualsOfInt(name,self->lengthSeconds)){
            return true;
        } else if(find == INDEX && EqualsOfInt(name,self->place.index)){
            return true;
        }
    } else return false;
}