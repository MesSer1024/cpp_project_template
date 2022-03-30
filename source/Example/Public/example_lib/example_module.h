#pragma once

namespace ddahlkvist
{

#define MSVC_COMPILER 1

#if defined(MSVC_COMPILER)
#define IMPORT_DLL __declspec(dllimport)
#define EXPORT_DLL __declspec(dllexport)
#else
#define IMPORT_DLL __attribute__ ((visibility("default")))
#define EXPORT_DLL __attribute__ ((visibility("default")))
#endif

#if defined(BUILD_COMPILE_DLL)
#if defined(BUILD_EXAMPLE_EXPORT)
#define EXAMPLE_PUBLIC EXPORT_DLL
#else
#define EXAMPLE_PUBLIC IMPORT_DLL
#endif
#else
#define EXAMPLE_PUBLIC
#endif

#if defined(BUILD_EXAMPLE_INTERNAL_ACCESS) || defined(BUILD_EXAMPLE_EXPORT)
#define EXAMPLE_INTERNAL EXAMPLE_PUBLIC
#else
#define EXAMPLE_INTERNAL private: //[error diagnostics] since I'm primarily using this keyword for class functions "private:" will provide best error diagnostics inside VS since it showcases the function trying to invoke this method
#endif

}