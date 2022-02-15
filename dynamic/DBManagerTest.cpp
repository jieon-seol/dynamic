#include "gtest/gtest.h"
#include "DBManager.h"

TEST(DBManagerTest, NullTest) {
	DBManager manager;
	EXPECT_EQ(manager.Query(""), "");
}