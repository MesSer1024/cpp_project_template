#pragma once

#include <example_lib/example_module.h>
#include <example_lib/Types.h>
#include <memory>

namespace ddahlkvist
{
	class Library
	{
	public:
		EXAMPLE_PUBLIC static void createLibrary();
		EXAMPLE_PUBLIC static void destroyLibrary();
		EXAMPLE_PUBLIC static Library* instance();
		~Library() = default;

	private:
		Library();
		static std::unique_ptr<Library> _instance;
	};
}