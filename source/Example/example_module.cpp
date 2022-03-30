#include <example_lib/example_module.h>

namespace ddahlkvist::template_lib_module
{
	EXAMPLE_PUBLIC void dummy() {} // dummy function to guarantee that we are exporting something [will generate .lib-file that other projects require]
}