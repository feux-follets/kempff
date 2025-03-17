include(FetchContent)
include_guard(GLOBAL)

function(fetch_dependency)
	cmake_parse_arguments(FD
			""
			"NAME;GIT_URL;GIT_TAG;URL;URL_HASH;PATCH_OPTIONS"
			"" ${ARGN})

	if (NOT FD_NAME)
		message(FATAL_ERROR "fetch_dependency(): NAME is required")
	endif ()

	if (FD_GIT_URL AND FD_GIT_TAG)
		FetchContent_Declare(${FD_NAME}
				GIT_REPOSITORY ${FD_GIT_URL}
				GIT_TAG ${FD_GIT_TAG}
				GIT_SHALLOW TRUE)
	elseif (FD_URL)
		FetchContent_Declare(${FD_NAME}
				URL ${FD_URL}
				URL_HASH ${FD_URL_HASH}
				DOWNLOAD_NO_EXTRACT FALSE
		)
	else ()
		message(FATAL_ERROR "fetch_dependency(): need GIT_URL+GIT_TAG or URL+URL_HASH")
	endif ()

	FetchContent_MakeAvailable(${FD_NAME})

	if (FD_PATCH_OPTIONS)
		target_compile_options(${FD_NAME} PRIVATE ${FD_PATCH_OPTIONS})
	endif ()
endfunction()