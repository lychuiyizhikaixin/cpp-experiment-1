cmake_minimum_required(VERSION 3.16)
# The course bundles an older GoogleTest; CMake 4 requires an explicit policy floor.
if(CMAKE_VERSION VERSION_GREATER_EQUAL "4.0")
    set(CMAKE_POLICY_VERSION_MINIMUM 3.5 CACHE STRING "Legacy dependency policy floor")
endif()

# Use the selected Command Line Tools SDK alias on macOS, while respecting overrides.
if(CMAKE_HOST_APPLE AND NOT CMAKE_OSX_SYSROOT AND NOT DEFINED ENV{SDKROOT})
    execute_process(COMMAND xcode-select -p OUTPUT_VARIABLE CLT_DIRECTORY
                    OUTPUT_STRIP_TRAILING_WHITESPACE)
    if(EXISTS "${CLT_DIRECTORY}/SDKs/MacOSX.sdk")
        set(CMAKE_OSX_SYSROOT "${CLT_DIRECTORY}/SDKs/MacOSX.sdk" CACHE PATH "macOS SDK")
    endif()
endif()
PROJECT(cpp-training VERSION 0.1.0)

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS "-Wno-deprecated-declarations -Wall -Werror -Wnon-virtual-dtor -Woverloaded-virtual")

ENABLE_TESTING()
ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(tests)
