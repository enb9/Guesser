/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(GuesserTest, Constructor_character)
{
  Guesser object("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
  ASSERT_EQ( object.distance("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"),0);
}


TEST(GuesserTest, distance_same_string)
{
  Guesser object("Secret");
  ASSERT_EQ( object.distance("Secret"),0);
}

TEST(GuesserTest, Counts_diiference)
{
  Guesser object("elijah");
  ASSERT_EQ( object.distance("elibah"),1);
}


TEST(GuesserTest, Count_add_character)
{
  Guesser object("12345");
  ASSERT_EQ( object.distance("1234567"),2);
}

TEST(GuesserTest, Special_character)
{
  Guesser object("");
  ASSERT_EQ( object.distance("$$"),0);
}
TEST(GuesserTest, RepeatedSymbols)
{
  Guesser object("$$$b");
  ASSERT_EQ( object.distance("$$b$"),2);
}

TEST(GuesserTest, Same_returns_true)
{
    Guesser object("burger");
    ASSERT_TRUE(object.match("burger"));
}

TEST(GuesserTest, Incorrect_changes_remain)
{
    Guesser object("Warrior");
    (object.match("Warriors"));
	 ASSERT_FALSE(object.match("Warriors")); 
}


