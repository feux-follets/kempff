include(FetchContent)
set(BUILD_SHARED_LIBS ON)
set(FMT_MODULE ON)
FetchContent_Declare(
		fmt
		GIT_REPOSITORY https://github.com/fmtlib/fmt
		GIT_TAG 11.2.0
)
FetchContent_MakeAvailable(fmt)
target_compile_options(fmt PRIVATE -Wno-include-angled-in-module-purview)