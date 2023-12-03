cmake_minimum_required(VERSION 3.8)

# 如果支持，请为 MSVC 编译器启用热重载。
if(POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project("LeetCode")

include_directories(archive/2023-12) 

aux_source_directory(. src)

# aux_source_directory(archive/2023-11 2023-11)

aux_source_directory(archive/2023-12 2023-12)

add_executable(LeetCode ${src} ${2023-11} ${2023-12}) 

if(CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET LeetCode PROPERTY CXX_STANDARD 20)
endif()

# TODO: 如有需要，请添加测试并安装目标。