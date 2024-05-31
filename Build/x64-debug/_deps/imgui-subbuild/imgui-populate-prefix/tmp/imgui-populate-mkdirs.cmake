# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/Projects/DX11-Editor/Build/x64-debug/_deps/imgui-src"
  "D:/Projects/DX11-Editor/Build/x64-debug/_deps/imgui-build"
  "D:/Projects/DX11-Editor/Build/x64-debug/_deps/imgui-subbuild/imgui-populate-prefix"
  "D:/Projects/DX11-Editor/Build/x64-debug/_deps/imgui-subbuild/imgui-populate-prefix/tmp"
  "D:/Projects/DX11-Editor/Build/x64-debug/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp"
  "D:/Projects/DX11-Editor/Build/x64-debug/_deps/imgui-subbuild/imgui-populate-prefix/src"
  "D:/Projects/DX11-Editor/Build/x64-debug/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/Projects/DX11-Editor/Build/x64-debug/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/Projects/DX11-Editor/Build/x64-debug/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()