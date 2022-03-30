#include <gtest/gtest.h>
#include <foo/FooInternal.h>

namespace ddahlkvist
{

	class FooInternalFixture : public testing::Test 
	{
	public:
		FooInternalFixture()
		{}

	protected:
		void SetUp() override
		{
		}

		void TearDown() override
		{
		}
	};

	TEST_F(FooInternalFixture, canAccessInternalFunction)
	{
		FooMixed foo;
		ASSERT_EQ(foo.getInternal(), 42u);
		//ASSERT_EQ(foo.getNothing(), 42u); // this is not exported inside dll
		ASSERT_EQ(foo.getPublic(), 42u);
	}

}

