# CMakeList.txt: Training 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

# 如果支持，请为 MSVC 编译器启用热重载。
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("LeetCode")

# 将源代码添加到此项目的可执行文件。
add_executable (LeetCode "LeetCodeMain.cpp" "LeetCodeMain.h" "LeetCode1768.cpp" "LeetCode1768.h" "LeetCode389.cpp" "LeetCode389.h" "LeetCode28.cpp" "LeetCode28.h" "LeetCode242.cpp" "LeetCode242.h" "LeetCode459.cpp" "LeetCode459.h" "LeetCode283.cpp" "LeetCode283.h" "LeetCode66.cpp" "LeetCode66.h" "LeetCode1822.cpp" "LeetCode1822.h" "LeetCode1502.cpp" "LeetCode1502.h" "LeetCode896.cpp" "LeetCode896.h" "LeetCode13.cpp" "LeetCode13.h" "LeetCode58.cpp" "LeetCode58.h" "LeetCode709.cpp" "LeetCode709.h" "LeetCode682.cpp" "LeetCode682.h" "LeetCode657.cpp" "LeetCode657.h" "LeetCode1275.cpp" "LeetCode1275.h" "LeetCode1672.cpp" "LeetCode1672.h" "LeetCode2235.cpp" "LeetCode2235.h" "LeetCode2469.cpp" "LeetCode2469.h" "LeetCode2413.cpp" "LeetCode2413.h" "LeetCode2236.cpp" "LeetCode2236.h" "LeetCode1486.cpp" "LeetCode1486.h" "LeetCode1512.cpp" "LeetCode1512.h" "LeetCode1534.cpp" "LeetCode1534.h" "LeetCode1281.cpp" "LeetCode1281.h" "LeetCode231.cpp" "LeetCode231.h" "LeetCode326.cpp" "LeetCode326.h" "LeetCode258.cpp" "LeetCode258.h" "LeetCode263.cpp" "LeetCode263.h" "LeetCode1470.cpp" "LeetCode1470.h" "LeetCode704.cpp" "LeetCode704.h" "LeetCode35.cpp" "LeetCode35.h" "LeetCode744.cpp" "LeetCode744.h" "LeetCode1351.cpp" "LeetCode1351.h" "LeetCode867.cpp" "LeetCode867.h" "LeetCode1422.cpp" "LeetCode1422.h" "LeetCode2586.cpp" "LeetCode2586.h" "LeetCode852.cpp" "LeetCode852.h" "LeetCode1572.cpp" "LeetCode1572.h" "LeetCode54.cpp" "LeetCode54.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET LeetCode PROPERTY CXX_STANDARD 20)
endif()

# TODO: 如有需要，请添加测试并安装目标。
