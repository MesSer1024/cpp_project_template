#include <gtest/gtest.h>

namespace ddahlkvist
{

class MainApplication
{
public:
	void run()
	{
		//auto value = template_lib_header::getProjectId();
		//std::cout << "Project Identifier: " << value << std::endl;
	}

};

}

int main(int argc, char** argv)
{
	ddahlkvist::MainApplication application;
	application.run();
	return 0;
}