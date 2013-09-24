FIND_PROGRAM(SED_EXECUTABLE sed PATHS /usr/bin)

SET(SED_COMMAND ${SED_EXECUTABLE} -n $p ${CMAKE_CURRENT_BINARY_DIR}/${FILENAME})

EXECUTE_PROCESS(COMMAND ${SED_COMMAND}
   OUTPUT_VARIABLE SED_LINE)

IF("${SED_LINE}" MATCHES "</VTKFile>")
   RETURN()
ELSE()
   message(FATAL_ERROR "Test failed: PVD file truncated!")
ENDIF()
