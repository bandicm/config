cmake_minimum_required(VERSION 3.15)
project(config LANGUAGES CXX)

# Postavi standard za C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Dodaj glavnu biblioteku
add_library(config STATIC
    src/config.cpp
)

# Uključi zaglavlja
target_include_directories(config
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/lib>
        $<INSTALL_INTERFACE:include>
)


# # Generiši export fajl za lokalnu upotrebu
# export(TARGETS config
#     FILE ${CMAKE_CURRENT_BINARY_DIR}/configTargets.cmake
#     NAMESPACE config::
# )

# Generiši configConfig.cmake
# include(CMakePackageConfigHelpers)

# configure_package_config_file(
#     ${CMAKE_CURRENT_SOURCE_DIR}/cmake/configConfig.cmake.in
#     ${CMAKE_CURRENT_BINARY_DIR}/configConfig.cmake
#     INSTALL_DESTINATION lib/cmake/config
# )

# write_basic_package_version_file(
#     ${CMAKE_CURRENT_BINARY_DIR}/configConfigVersion.cmake
#     VERSION 1.0.0
#     COMPATIBILITY SameMajorVersion
# )

# Instalacija za lokalnu upotrebu
install(TARGETS config
    EXPORT configTargets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

install(EXPORT configTargets
    FILE configTargets.cmake
    NAMESPACE config::
    DESTINATION lib/cmake/config
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/configConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/configConfigVersion.cmake
    DESTINATION lib/cmake/config
)

# Opcionalno dodaj testove
# enable_testing()
# add_subdirectory(test)

add_subdirectory(test)