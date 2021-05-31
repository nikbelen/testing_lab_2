/**
 * m.c -- реализует команду перемещения курсора в указанную позицию
 *
 * Copyright (c) 2021, Nikolay Belenkov <nikbelen6299@gmail.com>
 *
 * This code is licensed under a MIT-style license.
 */


#include <stdio.h>
#include <string.h>
#include "_text.h"

int m(text txt, int line_num, int cursor_pos) 
{
    if (line_num < 0 || cursor_pos < 0) return -1;

    std::list<std::string>::iterator current = txt->liist.begin();
    int index = 0;
    
    while (current!=txt->liist.end()) {
        if (line_num == index) break;
        std::advance(current,1);
        index++;
    }

    if (current == txt->liist.end()) return -1;

    if ((*current).length() < (long unsigned int)cursor_pos) return -1;

    txt->cursor->line = current;
    txt->cursor->position = cursor_pos;

    return 0;
} 
