#include "IntervalMap.hpp"

#include <gtest/gtest.h>

void IntervalMapTest() {
  IntervalMap<int, char> map('A');

  EXPECT_EQ(map.val_begin_, 'A');
  EXPECT_EQ(map[0], 'A');
  EXPECT_EQ(map.map_.size(), 0);

  map.assign(1, 10, 'B');
  EXPECT_EQ(map[0], 'A');
  EXPECT_EQ(map[1], 'B');
  EXPECT_EQ(map[9], 'B');
  EXPECT_EQ(map[10], 'A');
  EXPECT_EQ(map.map_.size(), 3);

  map.assign(5, 9, 'C');
  EXPECT_EQ(map[0], 'A');
  EXPECT_EQ(map[1], 'B');
  EXPECT_EQ(map[4], 'B');
  EXPECT_EQ(map[5], 'C');
  EXPECT_EQ(map[8], 'C');
  EXPECT_EQ(map[9], 'B');
  EXPECT_EQ(map[10], 'A');
  EXPECT_EQ(map.map_.size(), 5);

  map.assign(3, 5, 'A');
  EXPECT_EQ(map[0], 'A');
  EXPECT_EQ(map[1], 'B');
  EXPECT_EQ(map[2], 'B');
  EXPECT_EQ(map[3], 'A');
  EXPECT_EQ(map[4], 'A');
  EXPECT_EQ(map[5], 'C');
  EXPECT_EQ(map[9], 'B');
  EXPECT_EQ(map[10], 'A');
  EXPECT_EQ(map.map_.size(), 6);

  map.assign(8, 9, 'D');
  EXPECT_EQ(map[0], 'A');
  EXPECT_EQ(map[1], 'B');
  EXPECT_EQ(map[2], 'B');
  EXPECT_EQ(map[3], 'A');
  EXPECT_EQ(map[4], 'A');
  EXPECT_EQ(map[5], 'C');
  EXPECT_EQ(map[7], 'C');
  EXPECT_EQ(map[8], 'D');
  EXPECT_EQ(map[9], 'B');
  EXPECT_EQ(map[10], 'A');
  EXPECT_EQ(map.map_.size(), 7);

  map.assign(8, 12, 'B');
  EXPECT_EQ(map[0], 'A');
  EXPECT_EQ(map[1], 'B');
  EXPECT_EQ(map[2], 'B');
  EXPECT_EQ(map[3], 'A');
  EXPECT_EQ(map[4], 'A');
  EXPECT_EQ(map[5], 'C');
  EXPECT_EQ(map[7], 'C');
  EXPECT_EQ(map[8], 'B');
  EXPECT_EQ(map[11], 'B');
  EXPECT_EQ(map[12], 'A');
  EXPECT_EQ(map.map_.size(), 6);

  IntervalMap<int, char> imap('A');

  EXPECT_EQ(imap[std::numeric_limits<int>::lowest()], 'A');
  EXPECT_EQ(imap[0], 'A');
  EXPECT_EQ(imap[std::numeric_limits<int>::max()], 'A');

  imap.assign(1, 5, 'B');
  EXPECT_EQ(imap[0], 'A');
  EXPECT_EQ(imap[1], 'B');
  EXPECT_EQ(imap[4], 'B');
  EXPECT_EQ(imap[5], 'A');

  imap.assign(3, 7, 'C');
  EXPECT_EQ(imap[2],'B');
  EXPECT_EQ(imap[3],'C');
  EXPECT_EQ(imap[6],'C');
  EXPECT_EQ(imap[7],'A');

  imap.assign(6, 10, 'D');
  EXPECT_EQ(imap[5],'C');
  EXPECT_EQ(imap[6],'D');
  EXPECT_EQ(imap[9],'D');
  EXPECT_EQ(imap[10], 'A');

  imap.assign(1, 5, 'E');
  EXPECT_EQ(imap[0], 'A');
  EXPECT_EQ(imap[1], 'E');
  EXPECT_EQ(imap[4], 'E');
  EXPECT_EQ(imap[5], 'C');

  imap.assign(std::numeric_limits<int>::lowest(), 2, 'F');
  EXPECT_EQ(imap[std::numeric_limits<int>::lowest()], 'F');
  EXPECT_EQ(imap[1], 'F');
  EXPECT_EQ(imap[2], 'E');

  imap.assign(5, 5, 'G');
  EXPECT_EQ(imap[5], 'C');

  imap.assign(20, 25, 'H');
  EXPECT_EQ(imap[19],'A');
  EXPECT_EQ(imap[20],'H');
  EXPECT_EQ(imap[24],'H');
  EXPECT_EQ(imap[25],'A');

  imap.assign(std::numeric_limits<int>::lowest(), std::numeric_limits<int>::max(), 'A');
  EXPECT_EQ(imap[std::numeric_limits<int>::lowest()], 'A');
  EXPECT_EQ(imap[0], 'A');
  EXPECT_EQ(imap[std::numeric_limits<int>::max() - 1], 'A');
}

TEST(IntervalMapTest, interval_map_test)
{
  IntervalMapTest();
}


int main(int argc, char ** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}