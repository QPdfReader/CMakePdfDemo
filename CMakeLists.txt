cmake_minimum_required(VERSION 3.1.0)

project(CMakePdfDemo)

set(CMAKE_CXX_STANDARD 14)

IF (WIN32)
	MESSAGE(STATUS "Now is windows")
	set(CMAKE_PREFIX_PATH "C:\\Qt\\5.15.2\\msvc2019_64\\bin")
	set(Qt5_DIR "C:\\Qt\\5.15.2\\msvc2019_64\\lib\\cmake\\Qt5")
	set(PDFium_DIR "${CMAKE_SOURCE_DIR}/3rdparty/pdfium-win-x64")
ELSEIF (APPLE)
	MESSAGE(STATUS "Now is Apple systens.")
ELSEIF (UNIX)
	MESSAGE(STATUS "Now is UNIX-like OS's.")
ENDIF ()

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)
get_target_property(QtCore_location Qt5::Widgets LOCATION)


find_package(Qt5 COMPONENTS Core REQUIRED)
get_target_property(QtCore_location Qt5::Core LOCATION)

add_executable(CMakePdfDemo
	mainwindow.ui
	mainwindow.cpp
	mainwindow.h
	main.cpp
)

find_package(PDFium)

target_link_libraries(CMakePdfDemo Qt5::Widgets Qt5::Core Qt5::GuiPrivate Qt5::CorePrivate pdfium)

#todo windows copy
add_custom_command(TARGET ${PROJECT_NAME}
  PRE_BUILD 
  COMMAND echo "executing a fake command"
  COMMENT "This command will be executed before building target Test1"
 )
