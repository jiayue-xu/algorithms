file( GLOB APP_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp )

foreach( testsourcefile ${APP_SOURCES} )
    string( REPLACE ".cpp" "" testname ${testsourcefile} )
    add_executable( ${testname} ${testsourcefile} )

    set_target_properties(${testname} PROPERTIES
        LINKER_LANGUAGE CXX)
    install(TARGETS ${testname} DESTINATION "bin/search")

endforeach( testsourcefile ${APP_SOURCES} )