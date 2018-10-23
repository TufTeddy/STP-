#include "stdafx.h"
#include "CppUnitTest.h"
#include <assert.h>
#include "../StaticLib1/fraction.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

Fraction a(9, 5), b(17, 9), c(13, 19), d(78, 105);
Fraction fromstr("13/9");
Fraction fromstr2("105/123");
namespace FractionTest
{
	TEST_CLASS(UnitTest1)
	{
	public:


		TEST_METHOD(TestgetNum)
		{
			Assert::AreEqual(a.getNum(), 9);
			Assert::AreEqual(b.getNum(), 17);
		}

		TEST_METHOD(TestgetDen)
		{
			Assert::AreEqual(c.getDen(), 19);
			Assert::AreEqual(d.getDen(), 105);
		}
		TEST_METHOD(TestgetString)
		{
			Assert::AreEqual(fromstr.getNum(), 13);
			Assert::AreEqual(fromstr2.getDen(), 123);
		}
		TEST_METHOD(TestSum)
		{
			Fraction sumres = sumres.sum(a, b);
			Assert::AreEqual(sumres.getNum(), 166);
			sumres = sumres.sum(c, d);
			Assert::AreEqual(sumres.getNum(), 13 * 105 + 19 * 78);
		}
		TEST_METHOD(TestReroll)
		{
			a.reroll();
			Assert::AreEqual(a.getNum(), 5);
			Assert::AreEqual(a.getDen(), 9);
			a.reroll();
		}
		TEST_METHOD(TestDivide)
		{
			Fraction sumres = sumres.divide(a, b);
			Assert::AreEqual(sumres.getNum(), (9 * 9));
			sumres = sumres.divide(c, d);
			Assert::AreEqual(sumres.getDen(), (19 * 78));
		}
		TEST_METHOD(TestMulti)
		{
			Fraction sumres = sumres.multi(a, b);
			Assert::AreEqual(sumres.getNum(), 9 * 17);
			sumres = sumres.multi(c, d);
			Assert::AreEqual(sumres.getDen(), 19 * 105);
		}
		TEST_METHOD(TestSquare)
		{
			Fraction sumres = a;
			sumres = sumres.square(sumres);
			Assert::AreEqual(sumres.getNum(), 81);
			Assert::AreEqual(sumres.getDen(), 25);
		}
		TEST_METHOD(TestDenstr)
		{
			Assert::AreEqual(a.getDenString(), std::string("5"));
		}

	};
}