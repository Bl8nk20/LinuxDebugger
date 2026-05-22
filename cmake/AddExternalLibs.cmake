include(FetchContent)

FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog
        GIT_TAG v1.13.0
        GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(spdlog)

FetchContent_Declare(
        cxxopts
        GIT_REPOSITORY https://github.com/jarro2783/cxxopts
        GIT_TAG v3.1.1
        GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(cxxopts)

FetchContent_Declare(
        linenoise
        GIT_REPOSITORY https://github.com/antirez/linenoise
        GIT_TAG 2.0
        GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(linenoise)

FetchContent_Declare(
        libelfin
        GIT_REPOSITORY https://github.com/aclements/libelfin
        GIT_TAG v0.3
        GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(libelfin)

if(ENABLE_TESTING)
	FetchContent_Declare(
		Catch2
		GIT_REPOSITORY https://github.com/catchorg/Catch2
		GIT_TAG v3.5.3
		GIT_SHALLOW TRUE)
        FetchContent_MakeAvailable(Catch2)
        list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
endif()