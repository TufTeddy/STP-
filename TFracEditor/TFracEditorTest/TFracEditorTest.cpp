#include "stdafx.h"
#include "CppUnitTest.h"
#include <assert.h>
#include "../TFracEditor/TFracEditor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TFracEditorTest
{		
	TEST_CLASS(TFracEditorTest)
	{
	public:
		
		TEST_METHOD(Constructor)
		{
			TFracEditor test;
			Assert::AreEqual(test.getNumber(), (std::string)"0/1");
		}

		TEST_METHOD(IsZero)
		{
			TFracEditor test;
			Assert::AreEqual(test.isZero(), true);
			test.addDigit(5);
			Assert::AreEqual(test.isZero(), false);
		}

		TEST_METHOD(AddSignAndAddDigit)
		{
			TFracEditor test;
			test.addDigit(5);
			Assert::AreEqual(test.changeSign(), (std::string)"-5");
			Assert::AreEqual(test.changeSign(), (std::string)"5");
		}

		TEST_METHOD(AddZeroAndAddSplit)
		{
			TFracEditor test;
			test.addDigit(5);
			test.addZero();
			Assert::AreEqual(test.getNumber(), (std::string)"50/1");
			test.addSplit();
			test.addZero();
			test.addDigit(2);
			Assert::AreEqual(test.getNumber(), (std::string)"50/2");
		}

		TEST_METHOD(BackSpace)
		{
			TFracEditor test;
			test.addDigit(5);
			test.changeSign();
			Assert::AreEqual(test.backspace(), (std::string)"0");
		}

		TEST_METHOD(Clear)
		{
			TFracEditor test;
			test.addDigit(5);
			test.addDigit(6);
			test.changeSign();
			Assert::AreEqual(test.clear(), (std::string)"0");
		}

		TEST_METHOD(WriteString)
		{
			TFracEditor test;
			std::string number = "3/1";
			test.setNumber(number);
			Assert::AreEqual(test.getNumber(), (std::string)"3/1");
		}


	};
}