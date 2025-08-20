cmake_minimum_required(VERSION 3.16)
project(cpp_pool CXX)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

function(add_exercise EX_DIR)
    set(INC_DIR "${EX_DIR}/includes")
    set(SRC_DIR "${EX_DIR}/srcs")

    # Récupère aussi les headers
    file(GLOB_RECURSE SRCS "${SRC_DIR}/*.cpp")
    file(GLOB_RECURSE HDRS "${INC_DIR}/*.hpp")

    if (SRCS OR HDRS)
        string(REPLACE "/" "_" TARGET_NAME "${EX_DIR}")
        add_executable(${TARGET_NAME} ${SRCS} ${HDRS})

        if (EXISTS "${INC_DIR}")
            target_include_directories(${TARGET_NAME} PRIVATE "${INC_DIR}")
        endif()

        # Nom du binaire plus court (ex00, ex01…)
        get_filename_component(EX_BASENAME "${EX_DIR}" NAME)
        set_target_properties(${TARGET_NAME} PROPERTIES OUTPUT_NAME "${EX_BASENAME}")
    endif()
endfunction()

# Cherche tous les dossiers CPP-**/ex**
file(GLOB CPP_DIRS RELATIVE ${CMAKE_SOURCE_DIR} "CPP-*")

foreach(CPP IN LISTS CPP_DIRS)
    if (IS_DIRECTORY "${CMAKE_SOURCE_DIR}/${CPP}")
        file(GLOB EX_DIRS RELATIVE ${CMAKE_SOURCE_DIR} "${CPP}/ex*")
        foreach(EX IN LISTS EX_DIRS)
            if (IS_DIRECTORY "${CMAKE_SOURCE_DIR}/${EX}")
                add_exercise("${EX}")
            endif()
        endforeach()
    endif()
endforeach()
