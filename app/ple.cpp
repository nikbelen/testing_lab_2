/**
 * ple.c -- выводит текст от курсора до конца строки
 *
 * Copyright (c) 2021, Nikolay Belenkov <nikbelen6299@gmail.com>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <assert.h>
#include "common.h"
#include "text/text.h"

static void show_line(int index,std::string contents, int cursor, void *data);

void ple(text txt)
{
    /* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, show_line, NULL);
}

static void show_line(int index,std::string contents, int cursor, void *data)
{
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(cursor);
    UNUSED(data);
    UNUSED(index);
    if(cursor!=-1)
    {
        int e = cursor;
        while(contents[e])
        {
            printf("%c",contents[e]);
            e++;
        }
    }
} 
 
