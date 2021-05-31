#include "m_test.h"
#include "p1_test.h"
#include "save_test.h"
#include "ple_test.h"
#include "showalphaonly_test.h"

#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
