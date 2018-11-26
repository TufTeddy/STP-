#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "../app/addressbook.h"

using namespace testing;

TEST(AddressBook, InsertRemoveClearFind) {
    AddressBook test;
    test.insert("first", "111");
    EXPECT_EQ(test.find("first"), "111");
    test.remove("second");
    EXPECT_EQ(test.find("first"), "111");
    test.remove("first");
    EXPECT_EQ(test.find("first"), "");

}

TEST(AddressBook, Change) {
    AddressBook test;
    test.insert("first", "111");
    test.change("first", "123");
    EXPECT_EQ(test.find("first"), "123");
    test.change("second", "123");
    EXPECT_EQ(test.find("second"), "");
}

TEST(AddressBook, Clear) {
    AddressBook test;
    test.insert("second", "222");
    test.insert("third", "333");
    EXPECT_EQ(test.find("second"), "222");
    EXPECT_EQ(test.find("third"), "333");
    test.clear();
    EXPECT_EQ(test.find("second"), "");
    EXPECT_EQ(test.find("third"), "");
}
