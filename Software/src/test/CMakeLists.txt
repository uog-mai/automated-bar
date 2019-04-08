cmake_minimum_required(VERSION 3.7)

execute_process(COMMAND bash -c "echo `python3-config --extension-suffix`" OUTPUT_VARIABLE outVar)

#execute_process (
#    COMMAND bash -c "'`python3-config --extension-suffix`'"
#    OUTPUT_VARIABLE outVar
#)

#execute_process (
#	COMMAND bash -c "echo $var"
#)

#set(outVar `python3-config --extension-suffix`)

message( ${outVar} )

string(REGEX REPLACE "\n$" "" outVar "${outVar}")

message( ${outVar} )

