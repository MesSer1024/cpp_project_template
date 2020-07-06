-- premake5.lua

workspace "CppTemplateSolutionName"
  language "C++"
  architecture "x64"   
  location "local" -- where to place sln-files etc
  targetdir "local/%{cfg.buildcfg}"
  configurations { "Debug", "Release", "Final" }
  flags { "C++14"}
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
      flags { "Symbols"}

   filter {"configurations:Release"}
      defines { "DD_RELEASE", "RELEASE" }
      optimize "On"
      symbols "On"

   filter {"configurations:Final"}
      defines { "DD_FINAL", "FINAL" }
      optimize "On"
      symbols "Off"

      -- Done with global project settings

project "GoogleTest"
  kind "StaticLib"
  files { "googletest/src/gtest-all.cc" }
  includedirs { "googletest/include", "googletest" }

project "TemplateLib"
  defines { "BUILD_EXPORT_TEMPLATE_MODULE"}
  files { "template_lib/**.h", "template_lib/**.cpp" }
  removefiles { "template_lib/_Test/**" }

  includedirs { "template_lib/_Public", "template_lib" }

-- each test project should be separate exe file ...
project "TemplateLib.Test"
  defines { "BUILD_INTERNAL_ACCESS_TEMPLATE_MODULE"}
  kind "ConsoleApp"
  files { "template_lib/_Test/**" }

  links { "TemplateLib", "GoogleTest" }
  includedirs { "template_lib/_Public", "template_lib", "googletest/include" }

project "template_main"
   kind "ConsoleApp"
   files { "template_main/**.h", "template_main/**.cpp" }

   links { "TemplateLib", "GoogleTest" }
   includedirs { "template_lib/_Public", "googletest/include" }

