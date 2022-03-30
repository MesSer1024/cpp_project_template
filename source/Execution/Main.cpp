#include <example_lib/Library.h>
#include "../foo/FooInternal.h"

namespace ddahlkvist
{

class MainApplication
{
public:
	void run()
	{
		Library::createLibrary();

		auto* foo = Library::instance();
		DD_ASSERT(foo != nullptr);

		Library::destroyLibrary();

		foo = Library::instance();
		DD_ASSERT(foo == nullptr);
	}

	void checkFooExposure()
	{
		FooMixed foo;
		foo.getPublic();
		//foo.getNothing(); // function is not exported [linker error]
		//foo.getInternal(); // private from ifdef, function is "maybe" exported [no linker error if we do not explicitly generate error]

		FooPublic bar;
		bar.getPublic();
		bar.getInternal();
		bar.getNothing();
	}
};

}

int main(int argc, char** argv)
{
	ddahlkvist::MainApplication application;
	application.run();

	application.checkFooExposure();
	return 0;
}