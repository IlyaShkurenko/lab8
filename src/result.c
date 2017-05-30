//
// Created by Illia Shkurenko on 26.05.17.
//
#include <stdlib.h>
#include <string.h>
#include "result.h"
Result *Result_new(char *name, char *value) {
    Result *self = malloc(sizeof(Result));
    strcpy(self->value, value);
    strcpy(self->name, name);
    return self;
}

void Result_free(Result **selfPtr) {
    free(*selfPtr);
    *selfPtr = NULL;
}