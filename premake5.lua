-- premake5.lua

workspace "CppTemplateSolutionName"
  language "C++"
  architecture "x64"   
  location "_local" -- where to place sln-files etc
  targetdir "_local/%{cfg.buildcfg}"
  configurations { "Debug", "Release", "Final" }
  cppdialect "C++17"
  platforms { "Static", "DLL" }

  -- setup the different build configurations
  filter { "platforms:Static" }
    kind "StaticLib"
    defines { "BUILD_COMPILE_STATIC" }

  filter { "platforms:DLL" }
    kind "SharedLib"
    defines { "BUILD_COMPILE_DLL" }   

   filter { "configurations:Debug" }
      defines { "DD_DEBUG", "DEBUG" }
      symbols "On"

   filter {"configurations:Release"}
      defines { "DD_RELEASE", "RELEASE", "NDEBUG" }
      optimize "On"
      symbols "On"

   filter {"configurations:Final"}
      defines { "DD_FINAL", "FINAL", "NDEBUG" }
      optimize "On"
      symbols "Off"

      -- Done with global project settings

group "External"
  project "GoogleTest"
    kind "StaticLib"
    files { "_external/googletest/src/gtest-all.cc" }
    includedirs { "_external/googletest/include", "_external/googletest" }
group "" -- back to "default scope"

project "TemplateLib"
  defines { "BUILD_EXPORT_TEMPLATE_MODULE"}
  files { "template_lib/**.h", "template_lib/**.cpp" }
  removefiles { "template_lib/_Test/**" }

  includedirs { "template_lib/_Public", "template_lib" }

-- each test project should be separate exe file ...
group "Tests"
project "TemplateLib.Test"
  defines { "BUILD_INTERNAL_ACCESS_TEMPLATE_MODULE"}
  kind "ConsoleApp"
  files { "template_lib/_Test/**" }

  links { "TemplateLib", "GoogleTest" }
  includedirs { "template_lib/_Public", "template_lib", "_external/googletest/include" }
group "" -- back to "default scope"

project "template_main"
   kind "ConsoleApp"
   files { "template_main/**.h", "template_main/**.cpp" }

   links { "TemplateLib", "GoogleTest" }
   includedirs { "template_lib/_Public", "_external/googletest/include" }

