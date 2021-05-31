#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <string>

#include "common.h"
#include "text/text.h"
#include "text/_text.h"

TEST(save_test, multiple_lines)
{
    text txt = create_text();
    txt->liist.push_back("1st line");
    txt->liist.push_back("2nd line");
    txt->liist.push_back("3rd line");
    txt->liist.push_back("4th line");
    txt->liist.push_back("5th line");
    txt->cursor->line = txt->liist.begin();
    txt->cursor->position = 0;
    save(txt, "savefile.txt");

    text txt2 = create_text();
    load(txt2, "savefile.txt");

    EXPECT_EQ(txt->liist.size(), txt2->liist.size()-1);

    std::string* txt_arr = new std::string[txt->liist.size()];
    std::string* txt2_arr = new std::string[txt2->liist.size()];

    copy(txt->liist.begin(), txt->liist.end(), txt_arr);
    copy(txt2->liist.begin(), txt2->liist.end(), txt2_arr);

    for(unsigned int i = 0; i < txt->liist.size(); i++)
        EXPECT_STREQ(txt_arr[i].c_str(), txt2_arr[i].c_str());

    free(txt);
    free(txt2);
}

TEST(save_test, single_line)
{
    text txt = create_text();
    txt->liist.push_back("1st line");
    txt->cursor->line = txt->liist.begin();
    txt->cursor->position = 0;
    save(txt, "savefile.txt");

    text txt2 = create_text();
    load(txt2, "savefile.txt");

    EXPECT_EQ(txt->liist.size(), txt2->liist.size()-1);

    std::string* txt_arr = new std::string[txt->liist.size()];
    std::string* txt2_arr = new std::string[txt2->liist.size()];

    copy(txt->liist.begin(), txt->liist.end(), txt_arr);
    copy(txt2->liist.begin(), txt2->liist.end(), txt2_arr);

    for(unsigned int i = 0; i < txt->liist.size(); i++)
        EXPECT_STREQ(txt_arr[i].c_str(), txt2_arr[i].c_str());

    free(txt);
    free(txt2);
}

TEST(save_test, empty_file)
{
    text txt = create_text();
    txt->cursor->line = txt->liist.begin();
    txt->cursor->position = 0;
    save(txt, "savefile.txt");

    text txt2 = create_text();
    load(txt2, "savefile.txt");

    EXPECT_EQ(txt->liist.size(), txt2->liist.size()-1);

    std::string* txt_arr = new std::string[txt->liist.size()];
    std::string* txt2_arr = new std::string[txt2->liist.size()];

    copy(txt->liist.begin(), txt->liist.end(), txt_arr);
    copy(txt2->liist.begin(), txt2->liist.end(), txt2_arr);

    for(unsigned int i = 0; i < txt->liist.size(); i++)
        EXPECT_STREQ(txt_arr[i].c_str(), txt2_arr[i].c_str());

    free(txt);
    free(txt2);
}

