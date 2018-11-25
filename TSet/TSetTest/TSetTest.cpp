#include "stdafx.h"
#include <ctime>
#include <iterator>
#include <random>
#include "CppUnitTest.h"
#include "../TSet/TSet.h"
#include "../TSet/TSetInh.h"
#include "../../lab1/StaticLib1/fraction.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
namespace TSetTest
{		
	TEST_CLASS(TSetTest)
	{
	public:
		
		TEST_METHOD(EraseTest) {
			srand(time(NULL));
			TSet< Fraction > testClass;
			set< Fraction > testSet;
			for (int i = 0; i < 10; ++i) {
				Fraction frac(rand() % 10, rand() % 10);
				testClass.add(frac);
				testSet.insert(frac);
			}
			int numberOfElems = rand() % 10 + 10;
			for (int i = 0; i < 10; ++i)
				testSet.erase(testClass.elem(i));
			Assert::AreEqual(testSet.size(), (size_t)0);
		}
		TEST_METHOD(AdditionTest) {
			srand(time(NULL));
			TSet<Fraction> testClass1;
			TSet<Fraction> testClass2;
			TSet<Fraction> testClassResult;
			set<Fraction> testSet1;
			set<Fraction> testSet2;
			set<Fraction> testSetResult;
			int numberOfElems = rand()%10 + 10;
			for (int i = 0; i < numberOfElems; ++i) {
				Fraction frac(rand() % 100, rand() % 100);
				testClass1.add(frac);
				testSet1.insert(frac);
			}
			for (int i = 0; i < numberOfElems; ++i) {
				Fraction frac(rand() % 100, rand() % 100);
				testClass2.add(frac);
				testSet2.insert(frac);
			}
			testClassResult = testClass1.addition(testClass2);
			set_union(testSet1.begin(), testSet1.end(),
				testSet2.begin(), testSet2.end(), inserter(testSetResult, testSetResult.begin()));
			for (int i = 0; i < numberOfElems*2; ++i)
				testSetResult.erase(testClassResult.elem(i));
			Assert::AreEqual(testSetResult.size(), (size_t)0);
		}

		TEST_METHOD(SubtractionTest) {
			srand(time(NULL));
			TSet<Fraction> testClass1;
			TSet<Fraction> testClass2;
			TSet<Fraction> testClassResult;
			set<Fraction> testSet1;
			set<Fraction> testSet2;
			set<Fraction> testSetResult;
			int numberOfElems = rand() % 10 + 10;
			for (int i = 0; i < numberOfElems; ++i) {
				Fraction frac(rand() % 100, rand() % 100);
				testClass1.add(frac);
				testSet1.insert(frac);
			}
			for (int i = 0; i < numberOfElems; ++i) {
				Fraction frac(rand() % 100, rand() % 100);
				testClass2.add(frac);
				testSet2.insert(frac);
			}
			testClassResult = testClass1.subtraction(testClass2);
			set_difference(testSet1.begin(), testSet1.end(),
				testSet2.begin(), testSet2.end(), inserter(testSetResult, testSetResult.begin()));
			for (int i = 0; i < numberOfElems; ++i)
				testSetResult.erase(testClassResult.elem(i));
			Assert::AreEqual(testSetResult.size(), (size_t)0);
		}

		TEST_METHOD(MultiplyTest) {
			srand(time(NULL));
			TSet<Fraction> testClass1;
			TSet<Fraction> testClass2;
			TSet<Fraction> testClassResult;
			set<Fraction> testSet1;
			set<Fraction> testSet2;
			set<Fraction> testSetResult;
			int numberOfElems = rand()%10 + 10;
			for (int i = 0; i < numberOfElems; ++i) {
				Fraction frac(rand() % 100, rand() % 100);
				testClass1.add(frac);
				testSet1.insert(frac);
			}
			for (int i = 0; i < numberOfElems; ++i) {
				Fraction frac(rand() % 100, rand() % 100);
				testClass2.add(frac);
				testSet2.insert(frac);
			}
			testClassResult = testClass1.multiply(testClass2);
			set_intersection(testSet1.begin(), testSet1.end(),
				testSet2.begin(), testSet2.end(), inserter(testSetResult, testSetResult.begin()));
			for (int i = 0; i < testSetResult.size(); ++i)
				testSetResult.erase(testClassResult.elem(i));
			Assert::AreEqual(testSetResult.size(), (size_t)0);
		}

		TEST_METHOD(MultiplyTestInh) {
			srand(time(NULL));
			TSetInh<Fraction> testClass1;
			TSetInh<Fraction> testClass2;
			TSetInh<Fraction> testClassResult;
			set<Fraction> testSet1;
			set<Fraction> testSet2;
			set<Fraction> testSetResult;
			int numberOfElems = rand() % 10 + 10;
			for (int i = 0; i < numberOfElems; ++i) {
				Fraction frac(rand() % 100, rand() % 100);
				testClass1.insert(frac);
				testSet1.insert(frac);
			}
			for (int i = 0; i < numberOfElems; ++i) {
				Fraction frac(rand() % 100, rand() % 100);
				testClass2.insert(frac);
				testSet2.insert(frac);
			}
			testClassResult = testClass1.multiply(testClass2);
			set_intersection(testSet1.begin(), testSet1.end(),
				testSet2.begin(), testSet2.end(), inserter(testSetResult, testSetResult.begin()));
			for (int i = 0; i < testSetResult.size(); ++i)
				testSetResult.erase(testClassResult.elemAt(i));
			Assert::AreEqual(testSetResult.size(), (size_t)0);
		}

		TEST_METHOD(SubtractionTestInh) {
			srand(time(NULL));
			TSetInh<Fraction> testClass1;
			TSetInh<Fraction> testClass2;
			TSetInh<Fraction> testClassResult;
			set<Fraction> testSet1;
			set<Fraction> testSet2;
			set<Fraction> testSetResult;
			int numberOfElems = rand() % 10 + 10;
			for (int i = 0; i < numberOfElems; ++i) {
				Fraction frac(rand() % 100, rand() % 100);
				testClass1.insert(frac);
				testSet1.insert(frac);
			}
			for (int i = 0; i < numberOfElems; ++i) {
				Fraction frac(rand() % 100, rand() % 100);
				testClass2.insert(frac);
				testSet2.insert(frac);
			}
			testClassResult = testClass1.substraction(testClass2);
			set_difference(testSet1.begin(), testSet1.end(),
				testSet2.begin(), testSet2.end(), inserter(testSetResult, testSetResult.begin()));
			for (int i = 0; i < numberOfElems; ++i)
				testSetResult.erase(testClassResult.elemAt(i));
			Assert::AreEqual(testSetResult.size(), (size_t)0);
		}

		TEST_METHOD(AdditionTestInh) {
			srand(time(NULL));
			TSetInh<Fraction> testClass1;
			TSetInh<Fraction> testClass2;
			TSetInh<Fraction> testClassResult;
			set<Fraction> testSet1;
			set<Fraction> testSet2;
			set<Fraction> testSetResult;
			int numberOfElems = rand() % 10 + 10;
			for (int i = 0; i < numberOfElems; ++i) {
				Fraction frac(rand() % 100, rand() % 100);
				testClass1.insert(frac);
				testSet1.insert(frac);
			}
			for (int i = 0; i < numberOfElems; ++i) {
				Fraction frac(rand() % 100, rand() % 100);
				testClass2.insert(frac);
				testSet2.insert(frac);
			}
			testClassResult = testClass1.addition(testClass2);
			set_union(testSet1.begin(), testSet1.end(),
				testSet2.begin(), testSet2.end(), inserter(testSetResult, testSetResult.begin()));
			for (int i = 0; i < numberOfElems * 2; ++i)
				testSetResult.erase(testClassResult.elemAt(i));
			Assert::AreEqual(testSetResult.size(), (size_t)0);
		}

	};
}