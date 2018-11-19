#include "stdafx.h"
#include "CppUnitTest.h"
#include "../TPoly/TPoly.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TPolyTest
{		
	TEST_CLASS(TPolyTMember_Tests)
	{
	public:
		
		TEST_METHOD(TMemConstructor)
		{
			TPoly::TMember test;
			TPoly::TMember test2(2, 1);
			Assert::AreEqual(test.getFactor(), 0);
			Assert::AreEqual(test.getExp(), 0);
			Assert::AreEqual(test2.getFactor(), 2);
			Assert::AreEqual(test2.getExp(), 1);
		}
		TEST_METHOD(TMemSets)
		{
			TPoly::TMember test;
			test.setFactor(2);
			test.setExp(3);
			Assert::AreEqual(test.getFactor(), 2);
			Assert::AreEqual(test.getExp(), 3);
		}
		TEST_METHOD(TMemEqual)
		{
			TPoly::TMember test(2, 3);
			TPoly::TMember test2(2, 3);
			TPoly::TMember test3(3, 4);
			Assert::IsTrue(test == test2);
			Assert::IsFalse(test == test3);
		}
		TEST_METHOD(TMemDifferentiate)
		{
			TPoly::TMember test(3, 2);
			TPoly::TMember res(6, 1);
			Assert::IsTrue(test.differentiate() == res);
		}
		TEST_METHOD(TMemCalculate)
		{
			TPoly::TMember test(4, 3);
			Assert::IsTrue(test.calculate(-2) == -32);
		}
		TEST_METHOD(TMemString)
		{
			TPoly::TMember test(4, 3);
			Assert::AreEqual(test.toString(), (std::string)"4*x^3");
		}
		TEST_METHOD(TPolyConstructor)
		{
			TPoly test(4, 3);
			TPoly test2;
			Assert::IsTrue(test.elemAt(0) == TPoly::TMember(4, 3));
			Assert::AreEqual(test2.getExp(), 0);
			Assert::AreEqual(test2.getFactor(0), 0);
		}
		TEST_METHOD(TPolyClear)
		{
			TPoly test(4, 3);
			test.clear();
			Assert::AreEqual(test.getExp(), 0);
			Assert::AreEqual(test.getFactor(0), 0);
		}
		TEST_METHOD(TPolyPlus)
		{
			TPoly test(4, 3);
			TPoly test2 = test + TPoly::TMember(2, 4);
			Assert::AreEqual(test2.getExp(), 4);
			Assert::AreEqual(test2.getFactor(4), 2);
			Assert::AreEqual(test2.getFactor(3), 4);
			Assert::AreEqual(test2.calculate(2), 64.0);
			TPoly test3 = test + test;
			Assert::AreEqual(test3.getExp(), 3);
			Assert::AreEqual(test3.getFactor(3), 8);
		}
		TEST_METHOD(TPolyMinus)
		{
			TPoly test(4, 3);

			TPoly test2 = test - TPoly::TMember(2, 4);
			Assert::AreEqual(test2.getExp(), 4);
			Assert::AreEqual(test2.getFactor(4), -2);
			Assert::AreEqual(test2.getFactor(3), 4);
			Assert::AreEqual(test2.calculate(2), 0.0);

			TPoly test3 = test2 - TPoly::TMember(2, 4);
			TPoly test4 = test - test;
			TPoly test5 = test - TPoly::TMember(4, 3);
			Assert::AreEqual(test3.getExp(), 4);
			Assert::AreEqual(test3.getFactor(4), -4);
			Assert::AreEqual(test3.getFactor(3), 4);
			Assert::AreEqual(test3.calculate(2), -32.0);
			Assert::AreEqual(test4.getExp(), 0);
			Assert::AreEqual(test4.getFactor(0), 0);
			Assert::AreEqual(test5.getExp(), 0);
			Assert::AreEqual(test5.getFactor(0), 0);
		}
		TEST_METHOD(TPolyMulti)
		{
			TPoly test = TPoly(2, 2) + TPoly::TMember(3, 1); // 2x^2 + 3x
			TPoly test2 = TPoly(3, 2) + TPoly::TMember(2, 1); // 3x^2 + 2x
			TPoly test3 = test * test2; // 6x^4 + 13x^3 + 6x^2

			Assert::AreEqual(test3.getFactor(4), 6);
			Assert::AreEqual(test3.getFactor(3), 13);
			Assert::AreEqual(test3.getFactor(2), 6);
			Assert::AreEqual(test3.getFactor(1), 0);
			Assert::AreEqual(test3.getFactor(0), 0);
		}
		TEST_METHOD(TPolyEqual)
		{
			TPoly test(2, 2);
			TPoly test2(3, 2);
			TPoly test3(3, 2);
			Assert::IsFalse(test == test2);
			Assert::IsFalse(test == test3);
			Assert::IsFalse(test == test2 + test3);
			Assert::IsTrue(test2 == test3);
			Assert::IsTrue(test3 == test3);
		}
		TEST_METHOD(TPolyDifferentiate)
		{
			TPoly test = (TPoly(2, 2) + TPoly::TMember(3, 4)).differentiate();
			Assert::AreEqual(test.getFactor(0), 0);
			Assert::AreEqual(test.getFactor(1), 4);
			Assert::AreEqual(test.getFactor(2), 0);
			Assert::AreEqual(test.getFactor(3), 12);
			Assert::AreEqual(test.getFactor(4), 0);
		}
		TEST_METHOD(TPolyCalculate)
		{
			TPoly test = TPoly(2, 1) + TPoly::TMember(1, 2);
			Assert::AreEqual(test.calculate(3), 15.0);
		}

	};
}