/**
 * showalphaonly.c -- реализует команду вывода хранимого текста на экран, опуская небуквенные символы
 *
 * Copyright (c) 2021, Nikolay Belenkov <nikbelen6299@gmail.com>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"

static void show_line(int index,std::string contents, int cursor, void *data);

/**
 * Выводит содержимое указанного файла на экран
 */
void showalphaonly(text txt)
{
    /* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, show_line, NULL);
}

/**
 * Выводит содержимое указанного файла на экран
 */
static void show_line(int index,std::string contents, int cursor, void *data)
{
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(cursor);
    UNUSED(data);
        int e =0;
        while(contents[e])
        {
            if(isalpha(contents[e]))
                std::cout<<contents[e];
            e++;
        }
        std::cout<<'\n';
} 
