#ifndef ple_test_H
#define ple_test_H

#include <gtest/gtest.h>
#include "common.h"
#include "text/text.h"
#include "text/_text.h"

TEST (ple_test, from_start)
{
    text txt = create_text();
    txt->liist.push_back("1st line");
    txt->liist.push_back("2nd line");
    txt->liist.push_back("3rd line");
    txt->liist.push_back("4th line");
    txt->liist.push_back("5th line");
    txt->cursor->line = txt->liist.begin();
    txt->cursor->position = 0;

    m(txt,0,0);

    testing::internal::CaptureStdout();
    ple(txt);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(output.c_str(),"1st line");

    free (txt);
}

TEST(ple_test, empty_text)
{
    text txt = create_text();
    txt->cursor->line = txt->liist.begin();
    txt->cursor->position = 0;

    testing::internal::CaptureStdout();
    ple(txt);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(output.c_str(),"");

    free(txt);
}

TEST (ple_test, random_place)
{
    text txt = create_text();
    txt->liist.push_back("1st line");
    txt->liist.push_back("2nd line");
    txt->liist.push_back("3rd line");
    txt->liist.push_back("4th line");
    txt->liist.push_back("5th line");
    txt->cursor->line = txt->liist.begin();
    txt->cursor->position = 0;

    m(txt,3,4);

    testing::internal::CaptureStdout();
    ple(txt);
    std::string output = testing::internal::GetCapturedStdout();
    std::cout<<output;

    EXPECT_STREQ(output.c_str(),"line");

    free (txt);
}



#endif

