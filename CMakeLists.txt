cmake_minimum_required(VERSION 3.15)

project(HelloWorld)

set(CMAKE_BINARY_DIR bin)
set(CMAKE_CXX_STANDARD 20)


add_compile_options(-Wall -Wextra -O0 -g)
# add_compile_options(-fstack-protector-all)
# 为所有target添加编译器选项
add_compile_options(-fsanitize=address)
# 为所有target添加链接选项
add_link_options(-fsanitize=address)

# 查找当前目录下所有以数字开头的.cpp文件
file(GLOB NUMBER_CPP_FILES "src/[0-9]*.cpp")

# 遍历找到的每个.cpp文件
foreach(source_file ${NUMBER_CPP_FILES})
    # replace "src/*.cpp" with "*"
    get_filename_component(file_base_name ${source_file} NAME)
    string(REPLACE ".cpp" "" file_base_name ${file_base_name})

    message(STATUS "Configuring executable: ${file_base_name} from source: ${source_file}")
    add_executable("${file_base_name}"
        ${source_file}
        src/comm.cpp
    )
endforeach()

# 查找当前目录下所有以数字开头的.cpp文件
file(GLOB NUMBER_CPP_FILES "data_struct/[0-9]*.cpp")

# 遍历找到的每个.cpp文件
foreach(source_file ${NUMBER_CPP_FILES})
    get_filename_component(file_base_name ${source_file} NAME)
    string(REPLACE ".cpp" "" file_base_name ${file_base_name})

    message(STATUS "Configuring executable: ${file_base_name} from source: ${source_file}")
    add_executable("${file_base_name}"
        ${source_file}
        comm/comm.cpp
    )
    target_include_directories("${file_base_name}" PRIVATE comm)
endforeach()
