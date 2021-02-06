#include <cassert>
#include <gtest/gtest.h>

#include "../db_handling/dbData.h"
 
TEST(DBConnection, ConnectionSuccess) 
{ 
    assert((dbData::getInstance() != nullptr));
}

int main(int argc, char **argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
