#include <example_lib/Library.h>

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

};

}

int main(int argc, char** argv)
{
	ddahlkvist::MainApplication application;
	application.run();
	return 0;
}