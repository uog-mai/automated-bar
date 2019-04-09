cmake_minimum_required(VERSION 3.7)

execute_process(COMMAND bash -c "echo `python3 -m pybind11 --includes`" OUTPUT_VARIABLE outVar)

#execute_process (
#    COMMAND bash -c "'`python3-config --extension-suffix`'"
#    OUTPUT_VARIABLE outVar
#)

#execute_process (
#	COMMAND bash -c "echo $var"
#)

#set(outVar `python3-config --extension-suffix`)

#message( ${outVar} )


string(REPLACE "-I" "" outVar ${outVar})
string(REPLACE " " ";" ARG_LIST ${outVar})
message( ${ARG_LIST} )
list(GET ARG_LIST 0 DIR1)
list(GET ARG_LIST 1 DIR2)
list(GET ARG_LIST 2 DIR3)

message( ${DIR1} )

