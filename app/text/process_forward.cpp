/**
 * process_forward.c -- реализует обобщенную функцию обработки текста
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

/**
 * Обрабатывает список, применяя заданную функцию к каждой строке
 * 
 * @param txt текст
 * @param process функция-обработчик
 * @returns none
 */
void process_forward(
    text txt,
    void (*process)(int index,std::string contents, int cursor, void *data),
    void *data
)
{   
    /* Проверяем, имеется ли текст */
    if (txt == NULL || txt->liist.size() == 0) {
        fprintf(stderr, "There are already no any lines in the text!\n");
        return;
    } 
    
    
    /* Стартуем с начальной строки текста */
    std::list<std::string>::iterator current = txt->liist.begin();
    int index = 0;
    int cursor_position = -1;
    
    /* К каждой строке текста применяем обработчик */
    while (current!=txt->liist.end()) {
        if (txt->cursor->line == current) 
            cursor_position = txt->cursor->position;
        else
            cursor_position = -1;
        process(index, *current, cursor_position, data);
        std::advance(current,1);
        index++;
    }
}
