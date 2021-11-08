# CMakePdfDemo

# 这是个demo
vs2019编译器（3rdparty里是msvc编译的，所以本工程也得是vs2019编译
# 编译依赖
## 本地依赖
- 编译器 msvc2019
- Qt5.0 或者更高

## 编译前准备
需要手动修改cmakelist中的两个Qt的参数

```cmake
	set(CMAKE_PREFIX_PATH "C:\\Qt\\5.15.2\\msvc2019_64\\bin")
	set(Qt5_DIR "C:\\Qt\\5.15.2\\msvc2019_64\\lib\\cmake\\Qt5")
```

# 编译
```shell
git clone https://github.com/QPdfReader/CMakePdfDemo.git
cd CMakePdfDemo
mkdir build
cd build
cmake ../
msbuild CMakePdfDemo.sln
```

## 编译后需要拷贝运行后需要提示的

- Qt5Widgets.dll
- Qt5Core.dll
- Qt5Gui.dll

别忘了把plugins\platforms这个文件夹拷贝到运行目录


# 这只是个demo，后面会统一处理这些恶心的地方