/**
 * _text.h -- внутренние структуры представления текста
 * 
 * Этот файл не должен включаться в клиентские модули
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef _TEXT_H
#define _TEXT_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <list>
#include <iterator>
#include <assert.h>

#include "text.h"


/**
 * @struct 
 * @brief Представление курсора
 * 
 */
typedef struct _crsr {
    std::list<std::string>::iterator line;         /**< указатель на строку с курсором */
    int position;               /**< позиция курсора в строке */
} crsr;


typedef struct teeext{
std::list <std::string> liist;
struct _crsr *cursor;
}teeeext;

typedef struct teeext *text;


#endif
