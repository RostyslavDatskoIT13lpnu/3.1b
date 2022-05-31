#include "pch.h"
#include "CppUnitTest.h"
#include "../3.1b/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Student a;
			a.spec = (Spec)0;
			a.physics = 5;
			a.math = 5;
			a.progr = 5;
			Assert::AreEqual(check(a), true);
		}
	};
}
