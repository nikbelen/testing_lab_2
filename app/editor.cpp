/**
 * editor.c -- строковый текстовый редактор
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <list>
#include "text/text.h"
#include "common.h"
using namespace std;
#define MAXLINE 255

int main()
{
    string cmdline,cmd,arg;
    int i=0;

    
    /* Создаем объект для представления текста */
    text txt = create_text();
    
    /* Цикл обработки команд */
    while (1) {
        printf("ed > ");
        
        /* Получаем команду */
        cin>>cmdline;
        
        i=0;
    
        while(cmdline[i]==' ')
            i++;
        while(cmdline[i]!=' ')
            cmd[i]=cmdline[i];
        while(cmdline[i]==' ')
            i++;
        while(cmdline[i]!=' ')
            arg[i]=cmdline[i];
        /* Распознаем поддерживаемую команду */
        
        /* Завершаем работу редактора */
        if (cmd=="quit") {
            fprintf(stderr, "Bye!\n");
            break;
        }

        /* Загружаем содержимое файла, заданного параметром */
        if (cmd=="load") {
            if (arg=="") {
                fprintf(stderr, "Usage: load filename\n");
            } else {
                load(txt, arg);
            }
            continue;
        }

        /* Выводим текст */
        if (cmd=="show") {
            show(txt);
            continue;
        }
        
        if (cmd=="save") {
            if (arg=="") {
                fprintf(stderr, "Usage: save filename\n");
            } else {
                save(txt, arg);
            }
            continue;
        }
        
        
        /* Если команда не известна */
        cout<<"Unknown command: "<<cmd<<endl;
    }
    


    return 0;
}
