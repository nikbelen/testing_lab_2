#ifndef showalphaonly_test_H
#define showalphaonly_test_H

#include <gtest/gtest.h>
#include "common.h"
#include "text/text.h"
#include "text/_text.h"

TEST (showalphaonly_test, from_start)
{
    text txt = create_text();
    txt->liist.push_back("1st line");
    txt->liist.push_back("2nd line");
    txt->liist.push_back("3rd line");
    txt->liist.push_back("4th line");
    txt->liist.push_back("5th line");
    txt->cursor->line = txt->liist.begin();
    txt->cursor->position = 0;

    testing::internal::CaptureStdout();
    showalphaonly(txt);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(output.c_str(),"stline\nndline\nrdline\nthline\nthline\n");

    free (txt);
}

TEST(showalphaonly_test, empty_text)
{
    text txt = create_text();
    txt->cursor->line = txt->liist.begin();
    txt->cursor->position = 0;

    testing::internal::CaptureStdout();
    showalphaonly(txt);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(output.c_str(),"");

    free(txt);
}

TEST (showalphaonly_test, only_numbers)
{
    text txt = create_text();
    txt->liist.push_back("12345");
    txt->liist.push_back("23456");
    txt->liist.push_back("34567");
    txt->liist.push_back("45678");
    txt->liist.push_back("56789");
    txt->cursor->line = txt->liist.begin();
    txt->cursor->position = 0;

    testing::internal::CaptureStdout();
    showalphaonly(txt);
    std::string output = testing::internal::GetCapturedStdout();
    std::cout<<output;

    EXPECT_STREQ(output.c_str(),"\n\n\n\n\n");

    free (txt);
}



#endif
