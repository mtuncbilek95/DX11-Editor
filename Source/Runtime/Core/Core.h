#pragma once

#include "Definitions.h"
#include "StdFix.h"
#include "GlobalConsole.h"

#if defined(HOLLOW_DEBUG)

#define HE_INFO Editor::ConsoleType::Info
#define HE_VERBOSE Editor::ConsoleType::Verbose
#define HE_WARNING Editor::ConsoleType::Warning
#define HE_ERROR Editor::ConsoleType::Error

#define CORE_LOG(level, title, message, ...) Editor::GlobalConsole::Log(level, title, message, __VA_ARGS__)
#define CORE_PRINT(message, ...) Editor::GlobalConsole::Print(message, __VA_ARGS__)
#define CORE_ASSERT(condition, title, message, ...) Editor::GlobalConsole::Assert(condition, title, message, __VA_ARGS__)
#else

#define HE_INFO
#define HE_VERBOSE
#define HE_WARNING
#define HE_ERROR

#define CORE_LOG(level, title, message, ...) 
#define PRINT_LOG(message, ...)
#define CORE_ASSERT(condition, title, message, ...) (condition)
#endif

