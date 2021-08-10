file(GLOB SUBPROCESS_CXX "*.hpp")
add_library(subprocess_cxx SHARED ${SUBPROCESS_CXX})
set_target_properties(subprocess_cxx PROPERTIES LINKER_LANGUAGE CXX)