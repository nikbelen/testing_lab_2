#ifndef p1_test_H
#define p1_test_H

#include <gtest/gtest.h>
#include "common.h"
#include "text/text.h"
#include "text/_text.h"

TEST (p1_test, common)
{
    text txt = create_text();
    txt->liist.push_back("1st line");
    txt->liist.push_back("2nd line");
    txt->liist.push_back("3rd line");
    txt->liist.push_back("4th line");
    txt->liist.push_back("5th line");
    txt->cursor->line = txt->liist.begin();
    txt->cursor->position = 0;

    p1(txt,"zero line");
    EXPECT_EQ(txt->liist.size(),6);

    std::list<std::string>::iterator it = txt->liist.begin();
    EXPECT_STREQ((*it).c_str(),"zero line");
    std::advance(it,1);
    EXPECT_STREQ((*it).c_str(),"1st line");
    std::advance(it,1);
    EXPECT_STREQ((*it).c_str(),"2nd line");
    std::advance(it,1);
    EXPECT_STREQ((*it).c_str(),"3rd line");
    std::advance(it,1);
    EXPECT_STREQ((*it).c_str(),"4th line");
    std::advance(it,1);
    EXPECT_STREQ((*it).c_str(),"5th line");

    free (txt);
}

TEST(p1_test, empty_text)
{
    text txt = create_text();
    txt->cursor->line = txt->liist.begin();
    txt->cursor->position = 0;

    p1(txt,"zero line");

    EXPECT_EQ(txt->liist.size(),1);
    EXPECT_STREQ(txt->liist.front().c_str(),"zero line");

    free(txt);
}



#endif
