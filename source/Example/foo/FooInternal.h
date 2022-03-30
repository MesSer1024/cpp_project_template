#pragma once

#include <example_lib/example_module.h>
#include <example_lib/Types.h>

namespace ddahlkvist
{
	// this is an example to specify when a project is requesting internal access [reachable from Example.Test but not Main]
	class FooMixed
	{
	public:
		EXAMPLE_PUBLIC u32 getPublic();
		u32 getNothing();
		EXAMPLE_INTERNAL u32 getInternal();
	};

	class EXAMPLE_PUBLIC FooPublic
	{
	public:
		u32 getPublic();
		u32 getInternal();
		u32 getNothing();
	};
}