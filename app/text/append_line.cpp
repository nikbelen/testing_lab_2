/**
 * append_line.c -- функции для добавления строк
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"



/**
 * Добавляет одну строку к тексту
 * @param txt текст
 * @param contents новая строка
 * @returns none
 */
void append_line(text txt, std::string contents)
{
    /* Если список пуст, создаем первый элемент */
    txt->liist.push_back(contents);
    txt->cursor->line=txt->liist.end();
    txt->cursor->position=contents.size();
}
