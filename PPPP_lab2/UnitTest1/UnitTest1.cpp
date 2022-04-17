#include "pch.h"
#include "../PPPP_lab2/Source.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(Main_test_TEST0)
		{
			Logger::WriteMessage(L"TEST0 (0, 1, 0, 1, 1, 2)");
			Assert::IsTrue(Method(0, 1, 0, 1, 1, 2) == "0", L"Assert");
		}
		
		TEST_METHOD(Main_test_TEST1_1)//+
		{
			Logger::WriteMessage(L"TEST1_1 (0, 0, 1, 1, 0, 1)");
			Assert::IsTrue(Method(0, 0, 1, 1, 0, 1) == "1 " + to_string(-1.0) + " " + to_string(1.0), L"Assert");
		}

		TEST_METHOD(Main_test_TEST1_2)//+
		{
			Logger::WriteMessage(L"TEST1_2 (1, 1, 0, 0, 1 ,0)");
			Assert::IsTrue(Method(1, 1, 0, 0, 1, 0) == "1 " + to_string(-1.0) + " " + to_string(1.0), L"Assert");
		}

		TEST_METHOD(Main_test_TEST1_3)//+
		{
			Logger::WriteMessage(L"TEST1_3 (0, 45, 45, 45, 0, 0)");
			Assert::IsTrue(Method(0, 2, 20, 1, 0, 0) == "1 " + to_string(-1.0) + " " + to_string(0.0), L"Assert");
		}

		TEST_METHOD(Main_test_TEST1_4)//+
		{
			Logger::WriteMessage(L"TEST1_4 (10, 10, 0, 2, 0, 0)");
			Assert::IsTrue(Method(10, 10, 0, 2, 0, 0) == "1 " + to_string(-1.0) + " " + to_string(0.0), L"Assert");
		}

		TEST_METHOD(Main_test_TEST1_5)//+
		{
			Logger::WriteMessage(L"TEST1_5 (1, 1, 1, 1, 1, 1)");
			Assert::IsTrue(Method(1, 1, 1, 1, 1, 1) == "1 " + to_string(-1.0) + " " + to_string(1.0), L"Assert");
		}

		TEST_METHOD(Main_test_TEST2_1)//+
		{
			Logger::WriteMessage(L"TEST2 (1, 2, 1, 1, 1, 1)");
			Assert::IsTrue(Method(1, 2, 1, 1, 1, 1) == "2 " + to_string(1.0) + " " + to_string(0.0), L"Assert");
		}

		TEST_METHOD(Main_test_TEST3_1)//+
		{
			Logger::WriteMessage(L"TEST3_1 (1, 0, 1, 0, 1, 1)");
			Assert::IsTrue(Method(1, 0, 1, 0, 1, 1) == "3 " + to_string(1.0), L"Assert");
		}

		TEST_METHOD(Main_test_TEST4_1)//+
		{
			Logger::WriteMessage(L"TEST4_1 (0, 0, 0, 1, 0, 1)");
			Assert::IsTrue(Method(0, 0, 0, 1, 0, 1) == "4 " + to_string(1.0), L"Assert");
		}

		TEST_METHOD(Main_test_TEST4_2)//+
		{
			Logger::WriteMessage(L"TEST4_2 (0, 1, 0, 1, 1, 1)");
			Assert::IsTrue(Method(0, 1, 0, 1, 1, 1) == "4 " + to_string(1.0), L"Assert");
		}

		
		TEST_METHOD(Main_test_TEST5_1)//+
		{
			Logger::WriteMessage(L"TEST5_1 (0, 0, 0, 0, 0, 0)");
			Assert::IsTrue(Method(0, 0, 0, 0, 0, 0) == "5", L"Assert");
		}
		
	};
}
