add_executable(config_test test.cpp)

target_link_libraries(config_test PRIVATE config)

# Dodaj direktorijum za zaglavlja
# target_include_directories(config_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../lib)
