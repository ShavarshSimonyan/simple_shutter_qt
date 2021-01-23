#include <cmath>
#include <cassert>
#include <gtest/gtest.h>

#include "../db_handling/dbData.h"
 
TEST(SquareRootTest, PositiveNos) 
{ 
    assert((6 == std::sqrt(36.0)));
    assert((18.0 == std::sqrt(324.0)));
    assert((25.4 == std::sqrt(645.16)));
    assert((0 == std::sqrt(0.0)));
}
 
TEST(DBConnection, ConnectionSuccess) 
{ 
    assert((dbData::getInstance() != nullptr));
}

int main(int argc, char **argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
