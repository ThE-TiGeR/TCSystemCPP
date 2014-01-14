set (TC_SYSTEM_LIB_INSTALL_DIR bin)
set (TC_SYSTEM_BIN_INSTALL_DIR bin)

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/${TC_SYSTEM_LIB_INSTALL_DIR})
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/${TC_SYSTEM_LIB_INSTALL_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/${TC_SYSTEM_BIN_INSTALL_DIR})

# set our compiler flags
if (ANDROID)
   set (TC_COMPILE_FLAGS "-DTCOS_ANDROID -Wall -Wno-multichar -DHAVE_UNIT_TESTS -fvisibility=hidden -std=c++0x")
   set (TC_COMPILE_FLAGS_DEBUG "")
   set (TC_COMPILE_FLAGS_RELEASE "")

   set (CATFemHex_EXE_LINK_FLAGS         "")
   set (CATFemHex_EXE_LINK_FLAGS_DEBUG   "")
   set (CATFemHex_EXE_LINK_FLAGS_RELEASE "")
elseif (UNIX)
   set (TC_COMPILE_FLAGS "-fPIC -Wall -Wno-multichar -DHAVE_UNIT_TESTS -fvisibility=hidden -std=c++0x")
   set (TC_COMPILE_FLAGS_DEBUG "-ggdb -DDEBUG")
   set (TC_COMPILE_FLAGS_RELEASE "-O3 -DNDEBUG -flto")

   if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
      set (TC_COMPILE_FLAGS "${TC_COMPILE_FLAGS} -DTCOS_LINUX")
   endif ()

   set (TC_EXE_LINK_FLAGS         "")
   set (TC_EXE_LINK_FLAGS_DEBUG   "-ggdb")
   set (TC_EXE_LINK_FLAGS_RELEASE "-flto")

   set (TC_SHARED_LINK_FLAGS         "-Wl,--no-undefined -pthread")
   set (TC_SHARED_LINK_FLAGS_DEBUG   "-ggdb")
   set (TC_SHARED_LINK_FLAGS_RELEASE "-flto")
elseif (WIN32)
   set (TC_COMPILE_FLAGS         "/DHAVE_UNIT_TESTS /EHsc /W4 /D_WIN32_WINNT=0x0600 /D_SCL_SECURE_NO_WARNINGS /D_CRT_SECURE_NO_WARNINGS /Gm- /MP")
   set (TC_COMPILE_FLAGS_DEBUG   "/DDEBUG /FR")
   set (TC_COMPILE_FLAGS_RELEASE "/DNDEBUG /Ox /Ob2 /Ot /Oi /GL /GS- /fp:fast /D_SECURE_SCL=0")
   
   set (TC_EXE_LINK_FLAGS         "")
   set (TC_EXE_LINK_FLAGS_DEBUG   "/debug")
   set (TC_EXE_LINK_FLAGS_RELEASE "/LTCG")

   set (TC_SHARED_LINK_FLAGS         "")
   set (TC_SHARED_LINK_FLAGS_DEBUG   "/debug")
   set (TC_SHARED_LINK_FLAGS_RELEASE "/LTCG")
endif()

if (BUILD_SHARED_LIBS)
else ()
   set (TC_COMPILE_FLAGS "${TC_COMPILE_FLAGS} -DTC_COMPILE_STATIC_LIBS")
endif ()

set (CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} ${TC_COMPILE_FLAGS}")
set (CMAKE_CXX_FLAGS_DEBUG   "${CMAKE_CXX_FLAGS_DEBUG} ${TC_COMPILE_FLAGS_DEBUG}")
set (CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${TC_COMPILE_FLAGS_RELEASE}")

set (CMAKE_C_FLAGS           "${CMAKE_C_FLAGS} ${TC_COMPILE_FLAGS}")
set (CMAKE_C_FLAGS_DEBUG     "${CMAKE_C_FLAGS_DEBUG} ${TC_COMPILE_FLAGS_DEBUG}")
set (CMAKE_C_FLAGS_RELEASE   "${CMAKE_C_FLAGS_RELEASE} ${TC_COMPILE_FLAGS_RELEASE}")

set (CMAKE_EXE_LINKER_FLAGS         "${CMAKE_EXE_LINKER_FLAGS} ${TC_EXE_LINK_FLAGS}")
set (CMAKE_EXE_LINKER_FLAGS_DEBUG   "${CMAKE_EXE_LINKER_FLAGS_DEBUG} ${TC_EXE_LINK_FLAGS_DEBUG}")
set (CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} ${TC_EXE_LINK_FLAGS_RELEASE}")

set (CMAKE_SHARED_LINKER_FLAGS         "${CMAKE_SHARED_LINKER_FLAGS} ${TC_SHARED_LINK_FLAGS}")
set (CMAKE_SHARED_LINKER_FLAGS_DEBUG   "${CMAKE_SHARED_LINKER_FLAGS_DEBUG} ${TC_SHARED_LINK_FLAGS_DEBUG}")
set (CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_SHARED_LINKER_FLAGS_RELEASE} ${TC_SHARED_LINK_FLAGS_RELEASE}")

message(STATUS "----------------- TCSystem Compiler --------------------------------")
message(STATUS "CMAKE_C_COMPILER                  = ${CMAKE_C_COMPILER}")
message(STATUS "CMAKE_CXX_COMPILER                = ${CMAKE_CXX_COMPILER}")
message(STATUS "CMAKE_AR                          = ${CMAKE_AR}")
message(STATUS "CMAKE_RANLIB                      = ${CMAKE_RANLIB}")
message(STATUS "----------------- TCSystem Compile Flags ---------------------------")
message(STATUS "CMAKE_CXX_FLAGS                   = ${CMAKE_CXX_FLAGS}")
message(STATUS "CMAKE_CXX_FLAGS_DEBUG             = ${CMAKE_CXX_FLAGS_DEBUG}")
message(STATUS "CMAKE_CXX_FLAGS_RELEASE           = ${CMAKE_CXX_FLAGS_RELEASE}")
message(STATUS "CMAKE_C_FLAGS                     = ${CMAKE_C_FLAGS}")
message(STATUS "CMAKE_C_FLAGS_DEBUG               = ${CMAKE_C_FLAGS_DEBUG}")
message(STATUS "CMAKE_C_FLAGS_RELEASE             = ${CMAKE_C_FLAGS_RELEASE}")
message(STATUS "----------------- TCSystem Exe Link Flags --------------------------")
message(STATUS "CMAKE_EXE_LINKER_FLAGS            = ${CMAKE_EXE_LINKER_FLAGS}")
message(STATUS "CMAKE_EXE_LINKER_FLAGS_DEBUG      = ${CMAKE_EXE_LINKER_FLAGS_DEBUG}")
message(STATUS "CMAKE_EXE_LINKER_FLAGS_RELEASE    = ${CMAKE_EXE_LINKER_FLAGS_RELEASE}")
message(STATUS "----------------- TCSystem Shared Lib Link Flags -------------------")
message(STATUS "CMAKE_SHARED_LINKER_FLAGS         = ${CMAKE_SHARED_LINKER_FLAGS}")
message(STATUS "CMAKE_SHARED_LINKER_FLAGS_DEBUG   = ${CMAKE_SHARED_LINKER_FLAGS_DEBUG}")
message(STATUS "CMAKE_SHARED_LINKER_FLAGS_RELEASE = ${CMAKE_SHARED_LINKER_FLAGS_RELEASE}")
