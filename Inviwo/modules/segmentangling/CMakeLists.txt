#--------------------------------------------------------------------
ivw_module(Segmentangling)

#--------------------------------------------------------------------
# Add header files
set(HEADER_FILES 
    ${CMAKE_CURRENT_SOURCE_DIR}/common.h
    ${CMAKE_CURRENT_SOURCE_DIR}/processors/contourfilter.h
    ${CMAKE_CURRENT_SOURCE_DIR}/processors/loadcontourtree.h
    ${CMAKE_CURRENT_SOURCE_DIR}/processors/segmentationidraycaster.h
    ${CMAKE_CURRENT_SOURCE_DIR}/processors/volumesliceoverlay.h

    ${CMAKE_CURRENT_SOURCE_DIR}/../../../ContourTree/constants.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../ContourTree/ContourTreeData.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../ContourTree/DisjointSets.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../ContourTree/Grid3D.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../ContourTree/MergeTree.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../ContourTree/Persistence.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../ContourTree/ScalarFunction.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../ContourTree/SimFunction.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../ContourTree/SimplifyCT.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../ContourTree/TopologicalFeatures.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../ContourTree/TriMesh.hpp
)
ivw_group("Header Files" ${HEADER_FILES})

#--------------------------------------------------------------------
# Add source files
set(SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/processors/contourfilter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/processors/loadcontourtree.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/processors/segmentationidraycaster.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/processors/volumesliceoverlay.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/../../../ContourTree/ContourTreeData.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../ContourTree/Grid3D.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../ContourTree/MergeTree.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../ContourTree/Persistence.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../ContourTree/SimplifyCT.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../ContourTree/TopologicalFeatures.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../ContourTree/TriMesh.cpp
)
ivw_group("Source Files" ${SOURCE_FILES})

#--------------------------------------------------------------------
# Add shaders
set(SHADER_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/glsl/segmentationraycaster.frag
)
ivw_group("Shader Files" ${SHADER_FILES})

#--------------------------------------------------------------------
# Add definition
ivw_add_definition(__CL_ENABLE_EXCEPTIONS)

#--------------------------------------------------------------------
# Create module
ivw_create_module(${SOURCE_FILES} ${HEADER_FILES} ${SHADER_FILES})

#--------------------------------------------------------------------
# Handle external resources
if(IVW_USE_GENERATED_RESOURCES)
#--------------------------------------------------------------------
# Generate shader resource (if GENERATE_SHADER_RESOURCES is checked)
ivw_generate_shader_resource(${CMAKE_CURRENT_SOURCE_DIR}/glsl ${SHADER_FILES})
else()
#--------------------------------------------------------------------
# Add shader directory to pack
ivw_add_to_module_pack(${CMAKE_CURRENT_SOURCE_DIR}/glsl)
endif()