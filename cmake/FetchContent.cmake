include(FetchContent)
set(BUILD_SHARED_LIBS ON)
FetchContent_Declare(
		fmt
		GIT_REPOSITORY https://github.com/fmtlib/fmt
		GIT_TAG 11.1.4)
set(FMT_MODULE ON)
FetchContent_MakeAvailable(fmt)