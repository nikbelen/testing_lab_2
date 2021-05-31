/**
 * load.c -- функция загрузки текста из файла
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "common.h"
#include "text/text.h"
#include <iostream>
#include <fstream>

/**
 * Загружает содержимое указанного файла
 */
void load(text txt,std::string filename)
{
    std::ifstream f;
    std::string buf;
    f.open(filename);

    if(!f.good())
    {
        std::cout<<"The file "<<filename<<" can not be opened.";
        return;
    }

    /* Удаляем предыдущее содержимое */
    remove_all(txt);

    /* Считываем содержимое строка за строкой */
    while (f.good()) {
        std::getline(f,buf);
        append_line(txt, buf);
    }
    f.close();
}
