target_sources(${PROJECT_NAME}
		PRIVATE
		FILE_SET CXX_MODULES
		BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
		FILES
		Common.cppm
		File.cppm
		Utility.cppm
		Logger.cppm

		PRIVATE
		File.cpp
		Logger.cpp
)