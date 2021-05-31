/**
 * create_text.c -- создает в памяти структуры для представления текста
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

/**
 * Создает новый текстовый объект
 * @returns текст
 */
text create_text()
{  
    text txt;
    txt=new teeext;
    txt->cursor = new crsr;
    
    txt->cursor->line=txt->liist.begin();
    txt->cursor->position=0;
    return txt;
}
