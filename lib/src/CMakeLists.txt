

ot_add_current_dir_to_include_dirs ()

ot_add_source_file (SlicedInverseRegression.cxx)
ot_add_source_file (SlicedInverseRegressionResult.cxx)

ot_install_header_file (SlicedInverseRegression.hxx)
ot_install_header_file (SlicedInverseRegressionResult.hxx)


include_directories (${INTERNAL_INCLUDE_DIRS})

add_library (otsliced ${SOURCEFILES})
set_target_properties (otsliced PROPERTIES POSITION_INDEPENDENT_CODE ON)
if (BUILD_SHARED_LIBS)
  set_target_properties (otsliced PROPERTIES COMPILE_DEFINITIONS "OTSLICED_DLL_EXPORTS")
endif ()

if (NOT DEFINED LIB_VERSION) 
  set (LIB_VERSION 0.0.0)
endif ()
if (NOT DEFINED LIB_SOVERSION) 
  set (LIB_SOVERSION 0 )
endif ()
set_target_properties (otsliced PROPERTIES VERSION ${LIB_VERSION})
set_target_properties (otsliced PROPERTIES SOVERSION ${LIB_SOVERSION})
target_link_libraries (otsliced PUBLIC ${OPENTURNS_LIBRARY})

# Add targets to the build-tree export set
export (TARGETS otsliced FILE ${PROJECT_BINARY_DIR}/otsliced-Targets.cmake)

# Install the export set for use with the install-tree
install(EXPORT otsliced-Targets
        DESTINATION "${OTSLICED_CONFIG_CMAKE_PATH}"
        COMPONENT Development)

install(TARGETS otsliced
        EXPORT  otsliced-Targets 
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION ${OTSLICED_LIBRARY_PATH}
        ARCHIVE DESTINATION ${OTSLICED_LIBRARY_PATH}
)

