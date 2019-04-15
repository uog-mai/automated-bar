enable_testing()

include_directories("${source_dir}/googletest/include")


execute_process(COMMAND bash -c "echo `python3-config --extension-suffix`" OUTPUT_VARIABLE extension)

string(REGEX REPLACE "\n$" "" extension "${extension}")
string(REPLACE ".so" "" extension ${extension})

add_executable(runDrinksConfigUnitTests Test_DrinksConfig.cpp  main.cpp)
target_link_libraries(runDrinksConfigUnitTests libgtest libgmock DrinksConfig)
add_test(DrinksConfigUnitTests runDrinksConfigUnitTests)

