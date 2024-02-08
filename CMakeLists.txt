cmake_minimum_required(VERSION 3.20)

# このプロジェクトの概要を設定する
project(OutlineUI
    VERSION 0.0.1
    LANGUAGES CXX
    DESCRIPTION "Personal cpp template repository."
)

# ビルド周りの設定
option(BUILD_SHARED_LIBS "Build shared libraries." OFF)
option(CMAKE_BUILD_TYPE "Build type." Release)
option(CMAKE_EXPORT_COMPILE_COMMANDS "Generate `compile_commands.json` in build directories." 1)

# CMakeのポリシーを設定する
cmake_policy(SET CMP0076 NEW)
cmake_policy(SET CMP0128 NEW)
set(CMAKE_POLICY_DEFAULT_CMP0128 NEW)
cmake_policy(SET CMP0074 NEW)
set(CMAKE_POLICY_DEFAULT_CMP0074 NEW)
cmake_policy(SET CMP0077 NEW)
set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)

# C++コンパイラに渡すオプションを設定する
add_compile_options(-Wall $<$<CONFIG:Debug>:-g3>)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD 20)

# CPMをダウンロードする
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/DownloadFile.cmake)
DownloadFile(
    "https://github.com/cpm-cmake/CPM.cmake/releases/download/v0.38.7/CPM.cmake"
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/CPM.cmake
    83e5eb71b2bbb8b1f2ad38f1950287a057624e385c238f6087f94cdfc44af9c5
)

# CPMを有効にする
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/CPM.cmake)

# CPMを用いてネット上のパッケージを取り込む
CPMAddPackage(
    NAME fmt
    GITHUB_REPOSITORY fmtlib/fmt
    GIT_TAG 10.2.1
)

# システム内のパッケージを読み込む
find_package(Threads REQUIRED)

# 自作ライブラリAtmを定義
add_library(${PROJECT_NAME} INTERFACE)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

# ヘッダファイルのディレクトリを追加
target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# プログラムが利用するターゲットを追加
target_link_libraries(
    ${PROJECT_NAME} INTERFACE
    Threads::Threads Boost::boost
)

# Add sub directories
add_subdirectory(src)
