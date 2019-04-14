enable_testing()

include_directories("${source_dir}/googletest/include")

add_executable(runDrinksConfigUnitTests Test_DrinksConfig.cpp  main.cpp)
target_link_libraries(runDrinksConfigUnitTests libgtest libgmock DrinksConfig)
add_test(DrinksConfigUnitTests runDrinksConfigUnitTests)