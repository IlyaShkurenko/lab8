//
// Created by Illia Shkurenko on 29.05.17.
//

#ifndef TCP_FAV_H
#define TCP_FAV_H

#include "list.h"

typedef struct Composition Composition;
enum {
    BUF_SIZE = 10000, INDEX_SIZE = 1000, ARRAY_SIZE = 100
};
struct Place {
    char place[BUF_SIZE];
    int index;
};
struct Composition {
    struct Place place;
    char title[BUF_SIZE];
    int lengthSeconds;
    float salary;
};

Composition * Composition_new(char * place, char * title, int len, int index, float salary);
void Composition_free(Composition ** selfPtr);

void Composition_print(Composition * self, int index);

char * Composition_toString(Composition * self, char * buffer);

Composition * Composition_newFromString(char * str);

Composition * enterCompose(char * str);

void findComposion(Composition * self, int index, double x);

double enterSalary();

int indexToRemove();

void setField(Composition * quest, char *fieldName, char *value);

void changeField(List *self, char* fieldname, char * value, int index);

void delField(Composition *quest, char *fieldName);

void clearField(List *self, char * buf, int index);

char **split(char *str);

#endif //TCP_FAV_H
