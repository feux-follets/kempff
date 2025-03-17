include(${CMAKE_CURRENT_LIST_DIR}/FetchDependency.cmake)

set(BUILD_SHARED_LIBS ON)

# FMT
set(FMT_MODULE ON)
fetch_dependency(
		NAME fmt
		GIT_URL https://github.com/fmtlib/fmt
		GIT_TAG 11.2.0
		PATCH_OPTIONS -Wno-error=include-angled-in-module-purview
)

# Boost
set(BOOST_INCLUDE_LIBRARIES asio)
fetch_dependency(
		NAME Boost
		URL https://github.com/boostorg/boost/releases/download/boost-1.88.0/boost-1.88.0-cmake.7z
		URL_HASH SHA256=feba537f6d32c062ed0f26b4d6e5b8e8450d51ef81492369a101ab99fcead278
)