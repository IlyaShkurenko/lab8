//
// Created by Illia Shkurenko on 26.05.17.
//
/** @file
    @brief find element
*/
#ifndef TCP_FINDELEMENTS_H
#define TCP_FINDELEMENTS_H

#include <stdbool.h>
#include <convert.h>
#include "parsepath.h"
/** @file
    return true if element was find
*/
bool findElement(Composition *self, char * name, int find);
#endif //TCP_FINDELEMENTS_H
