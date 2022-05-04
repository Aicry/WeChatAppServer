# Install script for directory: /home/hms/muduo-tutorial(final)/cmake-submodule/muduo/muduo/base

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/hms/muduo-tutorial(final)/cmake-submodule/muduo/lib/libmuduo_base.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/muduo/base" TYPE FILE FILES
    "/home/hms/muduo-tutorial(final)/cmake-submodule/muduo/muduo/base/AsyncLogging.h"
    "/home/hms/muduo-tutorial(final)/cmake-submodule/muduo/muduo/base/Atomic.h"
    "/home/hms/muduo-tutorial(final)/cmake-submodule/muduo/muduo/base/BlockingQueue.h"
    "/home/hms/muduo-tutorial(final)/cmake-submodule/muduo/muduo/base/BoundedBlockingQueue.h"
    "/home/hms/muduo-tutorial(final)/cmake-submodule/muduo/muduo/base/Condition.h"
    "/home/hms/muduo-tutorial(final)/cmake-submodule/muduo/muduo/base/CountDownLatch.h"
    "/home/hms/muduo-tutorial(final)/cmake-submodule/muduo/muduo/base/CurrentThread.h"
    "/home/hms/muduo-tutorial(final)/cmake-submodule/muduo/muduo/base/Date.h"
    "/home/hms/muduo-tutorial(final)/cmake-submodule/muduo/muduo/base/Exception.h"
    "/home/hms/muduo-tutorial(final)/cmake-submodule/muduo/muduo/base/FileUtil.h"
    "/home/hms/muduo-tutorial(final)/cmake-submodule/muduo/muduo/base/GzipFile.h"
    "/home/hms/muduo-tutorial(final)/cmake-submodule/muduo/muduo/base/LogFile.h"
    "/home/hms/muduo-tutorial(final)/cmake-submodule/muduo/muduo/base/LogStream.h"
    "/home/hms/muduo-tutorial(final)/cmake-submodule/muduo/muduo/base/Logging.h"
    "/home/hms/muduo-tutorial(final)/cmake-submodule/muduo/muduo/base/Mutex.h"
    "/home/hms/muduo-tutorial(final)/cmake-submodule/muduo/muduo/base/ProcessInfo.h"
    "/home/hms/muduo-tutorial(final)/cmake-submodule/muduo/muduo/base/Singleton.h"
    "/home/hms/muduo-tutorial(final)/cmake-submodule/muduo/muduo/base/StringPiece.h"
    "/home/hms/muduo-tutorial(final)/cmake-submodule/muduo/muduo/base/Thread.h"
    "/home/hms/muduo-tutorial(final)/cmake-submodule/muduo/muduo/base/ThreadLocal.h"
    "/home/hms/muduo-tutorial(final)/cmake-submodule/muduo/muduo/base/ThreadLocalSingleton.h"
    "/home/hms/muduo-tutorial(final)/cmake-submodule/muduo/muduo/base/ThreadPool.h"
    "/home/hms/muduo-tutorial(final)/cmake-submodule/muduo/muduo/base/TimeZone.h"
    "/home/hms/muduo-tutorial(final)/cmake-submodule/muduo/muduo/base/Timestamp.h"
    "/home/hms/muduo-tutorial(final)/cmake-submodule/muduo/muduo/base/Types.h"
    "/home/hms/muduo-tutorial(final)/cmake-submodule/muduo/muduo/base/WeakCallback.h"
    "/home/hms/muduo-tutorial(final)/cmake-submodule/muduo/muduo/base/copyable.h"
    "/home/hms/muduo-tutorial(final)/cmake-submodule/muduo/muduo/base/noncopyable.h"
    )
endif()

