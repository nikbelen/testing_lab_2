#ifndef m_test_H
#define m_test_H

#include <gtest/gtest.h>
#include "common.h"
#include "text/text.h"
#include "text/_text.h"

TEST (move_test, common)
{
    text txt = create_text();
    txt->liist.push_back("1st line \n");
    txt->liist.push_back("2nd line \n");
    txt->liist.push_back("3rd line \n");
    txt->liist.push_back("4th line \n");
    txt->liist.push_back("5th line \n");
    txt->cursor->line = txt->liist.begin();
    txt->cursor->position = 0;

    std::list<std::string>::iterator current = txt->liist.begin();


    m(txt,0,0);
    EXPECT_EQ(txt->cursor->line,current);
    EXPECT_EQ(txt->cursor->position, 0);

    std::advance(current,3);

    m(txt,3,4);
    EXPECT_EQ(txt->cursor->line,current);
    EXPECT_EQ(txt->cursor->position, 4);

    free (txt);
}

TEST(move_test, out_of_range)
{
    text txt = create_text();
    txt->liist.push_back("1st line \n");
    txt->liist.push_back("2nd line \n");
    txt->liist.push_back("3rd line \n");
    txt->liist.push_back("4th line \n");
    txt->liist.push_back("5th line \n");
    txt->cursor->line = txt->liist.begin();
    txt->cursor->position = 0;

    std::list<std::string>::iterator current = txt->liist.begin();

    m(txt,10,10);
    EXPECT_EQ(txt->cursor->line,current);
    EXPECT_EQ(txt->cursor->position, 0);

    m(txt,-1,-2);
    EXPECT_EQ(txt->cursor->line,current);
    EXPECT_EQ(txt->cursor->position, 0);

    m(txt,1000,1000);
    EXPECT_EQ(txt->cursor->line,current);
    EXPECT_EQ(txt->cursor->position, 0);

    free(txt);
}



#endif
