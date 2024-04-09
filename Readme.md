# outline UI

Outline UI (OUI) は、 C++のクラスで表現されたUIの管理に必要な機能を提供するC++20 のライブラリだ．
このライブラリは扱いやすく簡潔に実装されており、利用者に与える制約が少ない．
また、特定のGUIライブラリに依存せず、既存のプログラムに組み込みやすい．

## 利用方法
OUIはBoostライブラリに依存しており、これを前もって用意する．
またビルドツールにはCMakeを用いるので、これも用意する．

Outline UIが提供するCMakeターゲットの一覧は以下の通り．

- `OutlineUI::OutlineUI`: ライブラリのインターフェイスターゲット．

### サブプロジェクトとして扱う場合
下の図のとおりにこのプロジェクトを配置する．
以下`your-project`を利用者のプロジェクトディレクトリとする．

```
your-project/
└── outline-ui/
    ├── CMakeLists.txt
    ├── Readme.md
    ├── bin
    ├── build
    ├── cmake
    ├── include
    └── src
```

`your-project`に`CMakeLists.txt`を以下のコードように作成する．


```CMake
# VERSIO>=3.20
cmake_minimum_required(VERSION 3.20)

# このプロジェクトの概要を設定する
project(your-project
    VERSION 0.0.1
    LANGUAGES CXX
)

# ビルドターゲット名を設定する
set(${TARGET} your_target)

# "XYZ"には"executable/library"が入る
add_XYZ(${TARGET})

# ${TARGET}にOutline UIをリンクする．
# PRIVATEでも問題ないかも...
target_link_libraries(${TARGET} PUBLIC OutlineUI::OutlineUI)
```

### ライブラリをインストールして使う場合
ライブラリをインストールして使う場合を想定していないため、インストールはサポートしていません．
サブプロジェクトとして使ってください．

## 使用しているライブラリのライセンス
# Personal Cpp Template

## ライセンス表記
- fmt
Copyright (c) 2012 - present, Victor Zverovich and {fmt} contributors

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

--- Optional exception to the license ---

As an exception, if, as a result of your compiling your source code, portions
of this Software are embedded into a machine-executable object form of such
source code, you may redistribute such embedded portions in such object form
without including the above copyright and permission notices.

- CPM.cmake
MIT License

Copyright (c) 2019-2022 Lars Melchior and contributors

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
