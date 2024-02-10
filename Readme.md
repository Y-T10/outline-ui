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