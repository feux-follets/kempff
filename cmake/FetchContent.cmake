include(FetchContent)
set(BUILD_SHARED_LIBS ON)
FetchContent_Declare(
		fmt
		GIT_REPOSITORY https://github.com/fmtlib/fmt
		GIT_TAG 11.2.0
		OVERRIDE_FIND_PACKAGE
)
set(FMT_MODULE ON)
find_package(fmt)