#include <template_lib/template_lib_module.h>

namespace ddahlkvist::template_lib_module
{
	TEMPLATE_PUBLIC void dummy() {} // dummy function to guarantee that we are exporting something [will generate .lib-file that other projects require]
}