


cmake_minimum_required(VERSION 3.23)


set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(PetConsoleApp VERSION ${PROJECT_VERSION})## @fn project(NAME)
## @brief Set the project name.
project(PetConsoleApp)

# Include the FetchContent module to download external dependencies
include(FetchContent)

# Declare an external dependency on the nlohmann/json library
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)

# Make the declared external dependencies available for use in this project
FetchContent_MakeAvailable(json)


configure_file(
        versiondef.h.in
        ${CMAKE_CURRENT_BINARY_DIR}/versiondef.h
)

add_executable(PetConsoleApp main.cpp)


set_target_properties(PetConsoleApp PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
        )


## @fn target_link_libraries(TARGET LIBRARIES)
## @brief Link the PetConsoleApp executable target with the nlohmann_json library.
target_link_libraries(PetConsoleApp PRIVATE nlohmann_json::nlohmann_json)


if (MSVC)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    target_compile_options(PetConsoleApp PRIVATE
            /W4
            )

else ()
    target_compile_options(PetConsoleApp PRIVATE
            -Wall -Wextra -pedantic -Werror
            )
endif ()

install(TARGETS PetConsoleApp RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)