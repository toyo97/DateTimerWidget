cmake_minimum_required(VERSION 3.8)
project(DateTimerWidget)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES DateTimerMain.cpp DateTimerMain.h DateTimerApp.cpp DateTimerApp.h Date.cpp Date.h Timer.cpp Timer.h FormatDialog.cpp FormatDialog.h Time.cpp Time.h)
add_executable(DateTimerWidget ${SOURCE_FILES})

set(wxWidgets_ROOT_DIR </usr/include/wx-3.1-unofficial>)
set(wxWidgets_CONFIGURATION mswu)
find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})

target_link_libraries(DateTimerWidget ${wxWidgets_LIBRARIES})