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
		FooInternal foo;
		ASSERT_EQ(foo.getIdentifier(), 42u);
	}

}

