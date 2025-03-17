include(FetchContent)
macro(fetch_content LIB_NAME GIT_URL GIT_TAG)
	FetchContent_Declare(${LIB_NAME}
			GIT_REPOSITORY ${GIT_URL}
			GIT_TAG ${GIT_TAG}
			GIT_SHALLOW TRUE
	)
	FetchContent_MakeAvailable(${LIB_NAME})
endmacro()
set(BUILD_SHARED_LIBS ON)

# FMT
set(FMT_MODULE ON)
fetch_content(fmt https://github.com/fmtlib/fmt 11.2.0)
target_compile_options(fmt PRIVATE -Wno-include-angled-in-module-purview)

# SDL3
find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)

# imgui
fetch_content(imgui https://github.com/ocornut/imgui v1.91.9b)
add_library(imgui
		${imgui_SOURCE_DIR}/imgui.cpp
		${imgui_SOURCE_DIR}/imgui_demo.cpp
		${imgui_SOURCE_DIR}/imgui_draw.cpp
		${imgui_SOURCE_DIR}/imgui_tables.cpp
		${imgui_SOURCE_DIR}/imgui_widgets.cpp
		${imgui_SOURCE_DIR}/backends/imgui_impl_sdl3.cpp
		${imgui_SOURCE_DIR}/backends/imgui_impl_sdlrenderer3.cpp
)
target_include_directories(imgui PUBLIC
		${imgui_SOURCE_DIR}
		${imgui_SOURCE_DIR}/backends
)
target_link_libraries(imgui PUBLIC SDL3::SDL3)
