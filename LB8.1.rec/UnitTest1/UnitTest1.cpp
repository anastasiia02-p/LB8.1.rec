#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include "CppUnitTest.h"
#include "../LB8.1.rec/main.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char str[] = "BASIC is replaced with Delphi, also BASIC again";
			char expected[] = "Delphi is replaced with Delphi, also Delphi again";

			char dest[151] = { 0 };
			char* result = ReplaceBASIC(dest, str, dest, 0);
			Assert::AreEqual(expected, result, L"Expected replacement of 'BASIC' with 'Delphi'");

		}
	};
}
