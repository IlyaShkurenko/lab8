//
// Created by Illia Shkurenko on 29.05.17.
//

#include <string.h>
#include <stdio.h>
#include "fav.h"
Composition *Composition_new(char *place, char *title, int len, int index, float salary) {
    Composition *self = malloc(sizeof(Composition));
    strcpy(self->place.place, place);
    strcpy(self->title, title);
    self->lengthSeconds = len;
    self->place.index = index;
    self->salary = salary;
    return self;
}

void Composition_free(Composition **selfPtr) {
    free(*selfPtr);
    *selfPtr = NULL;
}

void Composition_print(Composition *self, int index) {
    printf("%i) Name: %s, Place: %s, Index: %i, Length: %i, Salary %f\n", index,
           self->title,
           self->place.place,
           self->place.index,
           self->lengthSeconds,
           self->salary);
}

char *Composition_toString(Composition *self, char *buffer) {
    sprintf(buffer, "%s,%s,%i,%i,%f.",
            self->title,
            self->place.place,
            self->place.index,
            self->lengthSeconds,
            self->salary);
    return buffer;
}

Composition *Composition_newFromString(char *str) {
    Composition *self = Composition_new("", "", 0, 0, 0);
    char *strcp = (char *) malloc(BUF_SIZE * sizeof(char));
    strcpy(strcp, str);
    char **array = split(strcp);
    strcpy(self->title, array[0]);
    strcpy(self->place.place, array[1]);
    self->place.index = atoi(array[2]);
    self->lengthSeconds = atoi(array[3]);
    self->salary = atof(array[4]);
    free(strcp);
    return self;
}

Composition *enterCompose(char *str) {
    Composition *composition = Composition_newFromString(str);
    return composition;
}

void findComposion(Composition *self, int index, double x) {
    if (self != NULL && self->salary > x) {
        printf("Questionnaires with salary > %f     ", x);
        Composition_print(self, index);
    }
}


void changeField(List *self, char* fieldname, char * value, int index) {
    Composition *set = List_get(self, index);
    setField(set, fieldname, value);
}

void setField(Composition *quest, char *fieldName, char *value) {
    if (strcmp(fieldName, "Name") == 0) {
        strcpy(quest->title, value);
    } else if (strcmp(fieldName, "Place") == 0) {
        strcpy(quest->place.place, value);
    } else if (strcmp(fieldName, "Index") == 0) {
        quest->place.index = atoi(value);
    } else if (strcmp(fieldName, "Length") == 0) {
        quest->lengthSeconds = atoi(value);
    } else if (strcmp(fieldName, "Salary") == 0) {
        quest->salary = atof(value);
    }
}

void clearField(List *self, char * buf, int index) {
    Composition *set = List_get(self, index);
    delField(set, buf);
}

void delField(Composition *quest, char *fieldName) {
    if (strcmp(fieldName, "Name") == 0) {
        strcpy(quest->title, "");
    } else if (strcmp(fieldName, "Place") == 0) {
        strcpy(quest->place.place, "");
    } else if (strcmp(fieldName, "Index") == 0) {
        quest->place.index = 0;
    } else if (strcmp(fieldName, "Length") == 0) {
        quest->lengthSeconds = 0;
    } else if (strcmp(fieldName, "Salary") == 0) {
        quest->salary = 0;
    }
}
char **split(char *str) {
    char **words;
    words = (char **) malloc(10 * sizeof(char *));
    char *text = strtok(str, ",");
    int i = 0;
    while (text != NULL) {
        words[i] = text;
        text = strtok(NULL, ",");
        i++;

    }

    return words;
}

