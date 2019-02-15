#include "gtest/gtest.h"

#include <iostream>
#include <math.h>
#include <ctime>

#include "date.h"


class DateTest : public ::testing::Test {
 public:
  void SetUp( ) {
    // code here will execute just before the test ensues
	first_day = Date(2018, 9, 4);
	last_day = Date(2018, 12, 11);
	CHAN_B_DAY = Date(1993,06,17);
  }
 protected:
  Date first_day;          // first day of classes
  Date last_day;           // last day of classes
};

//PART I AM STARTING, WRITING---------------------------------------------------------------------------------

TEST_F (DateTest, CHAN_GetDateTest){
  Date birthday_chan (1993,6,17);
  std::string expected_out_1 = "1993-06-17";
  std::string actual_out_1 = birthday_chan.GetDate();
  EXPECT_EQ(actual_out_1, expected_out_1);
}

TEST_F(DateTest, CHAN_GetUSDateTest){
  Date birthday_chan (1993,6,17);
  std::string expected_out_1 = "06-17-1993";
  std::string actual_out_1 = birthday_chan.GetUsDate();
  EXPECT_EQ(actual_out_1, expected_out_1);
}

TEST_F (DateTest, CHAN_PrintUSDateTest_NewLine){
  Date birthday_chan (1993,6,17);
  std::string expected_out_1 = "06-17-1993\n";
  testing::internal::CaptureStdout();
  birthday_chan.PrintUsDate(true);
  std::string actual_out_1 = testing::internal::GetCapturedStdout();
  EXPECT_EQ(actual_out_1, expected_out_1);
}

TEST_F (DateTest, CHAN_PrintUSDateTest_NO_NewLine){
  Date birthday_chan (1993,6,17);
  std::string expected_out_1 = "06-17-1993";
  testing::internal::CaptureStdout();
  birthday_chan.PrintUsDate(false);
  std::string actual_out_1 = testing::internal::GetCapturedStdout();
  EXPECT_EQ(actual_out_1, expected_out_1);
}

TEST_F (DateTest, CHAN_PlusOperatorTest){
  Date birthday_chan (1993,6,17);
  Date birthday_day_after = birthday_chan.operator+(1);
  std::string expected_out_1 = birthday_day_after.GetUsDate();
  std::string actual_out = "06-18-1993"; // string without newline.
  EXPECT_EQ(actual_out, expected_out_1);

}

//PART I AM DONE, WRITING---------------------------------------------------------------------------------


TEST_F(DateTest, PrintDateTests) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween

  std::string expected_out_1 = "1999-12-31\n";
  std::string expected_out_2 = "1776-07-04\n";
  std::string expected_out_3 = "2018-10-31\n";

  testing::internal::CaptureStdout();
  y2k.PrintDate(true);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout(); // You must do this EVERY TIME, or else it will segfault
  ind_day.PrintDate(true);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  best_holiday.PrintDate(true);
  std::string output3 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

TEST_F(DateTest, PrintDateTestsWithoutNewline) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween

  std::string expected_out_1 = "1999-12-31";
  std::string expected_out_2 = "1776-07-04";
  std::string expected_out_3 = "2018-10-31";

  testing::internal::CaptureStdout();
  y2k.PrintDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  ind_day.PrintDate(false);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  best_holiday.PrintDate(false);
  std::string output3 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

/**
  *
  * Note, this is the only provided test case which actually uses our test fixture
  *
  * However, it is illegal to mix TEST() and TEST_F() in the same test case (file).
  *
  */

TEST_F(DateTest, DaysBetweenTests) {
  EXPECT_EQ(first_day.GetUsDate(), "09-04-2018") << "First day of class not setup properly";
  EXPECT_EQ(last_day.GetUsDate(), "12-11-2018") << "Last day of class not setup properly";
  EXPECT_EQ(first_day.DaysBetween(last_day), 98) << "Days between is not calculated properly";
}

/**
  *
  * NOPE!  Can't test PRIVATE methods
  *
  */
/*
TEST(DateTest, ConvertFromDays) {
	Date convert_first_day = ConvertToDays(2458365);
	EXPECT_STREQ(convert_first_day.GetUsDate(), "09-04-2018");
}
*/
