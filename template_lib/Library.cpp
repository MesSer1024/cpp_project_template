#include <template_lib/Library.h>

namespace ddahlkvist
{
std::unique_ptr<Library> Library::_instance;

Library::Library() {}

void Library::createLibrary() {
	DD_ASSERT(_instance.get() == nullptr);
}

void Library::destroyLibrary() {
	DD_ASSERT(_instance.get() != nullptr);
}

Library* Library::instance() {
	return _instance.get();
}

}