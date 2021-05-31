/**
 * p1.c -- добавляет строку в начало текста
 *
 * Copyright (c) 2021, Nikolay Belenkov <nikbelen6299@gmail.com>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <string>
#include "common.h"
#include "text/_text.h"
#include "text/text.h"  

void p1(text txt,std::string contents)
{
    txt->liist.push_front(contents);
}
 
