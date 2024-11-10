cmake_minimum_required(VERSION 3.20)

# 如果支持，请为 MSVC 编译器启用热重载。
if(POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project("LeetCode")

aux_source_directory(. SRC)
# aux_source_directory(archive/2023-11 SRC_202311)
# aux_source_directory(archive/2023-12 SRC_202312)
# aux_source_directory(archive/2024-01 SRC_202401)
# aux_source_directory(archive/2024-02 SRC_202402)
# aux_source_directory(archive/2024-03 SRC_202403)
# aux_source_directory(archive/2024-05 SRC_202405)
# aux_source_directory(archive/2024-09 SRC_202409)
aux_source_directory(archive/2024-11 SRC_202411)

add_executable(LeetCode ${SRC} ${SRC_202311} ${SRC_202312} ${SRC_202401} ${SRC_202402} ${SRC_202403} ${SRC_202405} ${SRC_202409} ${SRC_202411})

target_include_directories(LeetCode PRIVATE
                                            # archive/2023-11
                                            # archive/2023-12
                                            # archive/2024-01
                                            # archive/2024-02
                                            # archive/2024-03
                                            # archive/2024-05
                                            # archive/2024-09
                                            archive/2024-11
                                            .)

if(CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET LeetCode PROPERTY CXX_STANDARD 20)
endif()
