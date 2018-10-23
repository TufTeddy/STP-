#include "stdafx.h"
#include "CppUnitTest.h"
#include <assert.h>
#include "../StaticLib1/tcomplex.h"

#define _USE_MATH_DEFINES

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestComplex
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(getInt)
		{
			TComplex a(2, 4);
			Assert::AreEqual(a.getRealDouble(), 2.);
			Assert::AreEqual(a.getImaginaryDouble(), 4.);
		}

		TEST_METHOD(getStr)
		{
			TComplex a(4.5, 9.3);
			double real = 4.5;
			double image = 9.3;
			std::string frst = std::to_string(real);
			std::string imge = std::to_string(image);
			Assert::AreEqual(a.getRealStr(), frst);
			Assert::AreEqual(a.getImaginaryStr(), imge);
		}

		TEST_METHOD(sum)
		{
			TComplex a(2, 10);
			TComplex b(-2, -10);
			a = a.summ(a, b);
			Assert::AreEqual(a.getRealDouble(), 0.);
			Assert::AreEqual(a.getImaginaryDouble(), 0.);
		}

		TEST_METHOD(sub)
		{
			TComplex a(5, -5);
			TComplex b(1, -5);
			a = a.subtract(a, b);
			Assert::AreEqual(a.getRealDouble(), 4.);
			Assert::AreEqual(a.getImaginaryDouble(), 0.);
		}

		TEST_METHOD(multi)
		{
			TComplex a(3, 4);
			TComplex b(1, 0);
			a.multi(a, b);
			Assert::AreEqual(a.getRealDouble(), 3.);
			Assert::AreEqual(a.getImaginaryDouble(), 4.);
		}

		TEST_METHOD(div)
		{
			TComplex a(5, 4);
			TComplex b(-6, 2);
			a = a.divide(a, b);
			Assert::AreEqual(a.getRealDouble(), ((double)-22 / 40));
			Assert::AreEqual(a.getImaginaryDouble(), ((double)-34 / 40));
		}

		TEST_METHOD(radians)
		{
			TComplex a(1, 1);
			Assert::AreEqual((double)a.angleRadians(a), (double)0.79, 0.01);
		}

		TEST_METHOD(degrees)
		{
			TComplex a(1, 1);
			Assert::AreEqual(a.angleDegrees(a), 45.);
		}

		TEST_METHOD(equal)
		{
			TComplex a(1, 9);
			TComplex b = b.copy(a);
			Assert::AreEqual(a.equal(b), true);
		}

		TEST_METHOD(notEqual)
		{
			TComplex a(1, 9);
			TComplex b = b.copy(a);
			Assert::AreEqual(a.notEqual(b), false);
		}

		TEST_METHOD(root)
		{
			TComplex a(3, 5);
			TComplex b = a.root(5, 0);
			Assert::AreEqual(1.3927, b.getRealDouble(), 0.01);
		}

	};
}