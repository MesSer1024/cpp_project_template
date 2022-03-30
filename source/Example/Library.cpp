#include <example_lib/Library.h>
#include <memory>
#include <iostream>

namespace ddahlkvist
{
std::unique_ptr<Library> Library::_instance;

Library::Library() {}

void Library::createLibrary() {
	DD_ASSERT(_instance.get() == nullptr);

	_instance.reset(new Library());

	std::cout << "[Library] Hello!"  << std::endl;
}

void Library::destroyLibrary() {
	DD_ASSERT(_instance.get() != nullptr);
	_instance.reset(nullptr);

	std::cout << "[Library] Good Bye!" << std::endl;
}

Library* Library::instance() {
	return _instance.get();
}

}