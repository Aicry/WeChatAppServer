# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/hms/muduo-tutorial(final)/cmake-submodule"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/hms/muduo-tutorial(final)/cmake-submodule"

# Include any dependencies generated for this target.
include muduo/muduo/net/protobuf/CMakeFiles/muduo_protobuf_codec.dir/depend.make

# Include the progress variables for this target.
include muduo/muduo/net/protobuf/CMakeFiles/muduo_protobuf_codec.dir/progress.make

# Include the compile flags for this target's objects.
include muduo/muduo/net/protobuf/CMakeFiles/muduo_protobuf_codec.dir/flags.make

muduo/muduo/net/protobuf/CMakeFiles/muduo_protobuf_codec.dir/ProtobufCodecLite.cc.o: muduo/muduo/net/protobuf/CMakeFiles/muduo_protobuf_codec.dir/flags.make
muduo/muduo/net/protobuf/CMakeFiles/muduo_protobuf_codec.dir/ProtobufCodecLite.cc.o: muduo/muduo/net/protobuf/ProtobufCodecLite.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/hms/muduo-tutorial(final)/cmake-submodule/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object muduo/muduo/net/protobuf/CMakeFiles/muduo_protobuf_codec.dir/ProtobufCodecLite.cc.o"
	cd "/home/hms/muduo-tutorial(final)/cmake-submodule/muduo/muduo/net/protobuf" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/muduo_protobuf_codec.dir/ProtobufCodecLite.cc.o -c "/home/hms/muduo-tutorial(final)/cmake-submodule/muduo/muduo/net/protobuf/ProtobufCodecLite.cc"

muduo/muduo/net/protobuf/CMakeFiles/muduo_protobuf_codec.dir/ProtobufCodecLite.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/muduo_protobuf_codec.dir/ProtobufCodecLite.cc.i"
	cd "/home/hms/muduo-tutorial(final)/cmake-submodule/muduo/muduo/net/protobuf" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/hms/muduo-tutorial(final)/cmake-submodule/muduo/muduo/net/protobuf/ProtobufCodecLite.cc" > CMakeFiles/muduo_protobuf_codec.dir/ProtobufCodecLite.cc.i

muduo/muduo/net/protobuf/CMakeFiles/muduo_protobuf_codec.dir/ProtobufCodecLite.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/muduo_protobuf_codec.dir/ProtobufCodecLite.cc.s"
	cd "/home/hms/muduo-tutorial(final)/cmake-submodule/muduo/muduo/net/protobuf" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/hms/muduo-tutorial(final)/cmake-submodule/muduo/muduo/net/protobuf/ProtobufCodecLite.cc" -o CMakeFiles/muduo_protobuf_codec.dir/ProtobufCodecLite.cc.s

muduo/muduo/net/protobuf/CMakeFiles/muduo_protobuf_codec.dir/ProtobufCodecLite.cc.o.requires:

.PHONY : muduo/muduo/net/protobuf/CMakeFiles/muduo_protobuf_codec.dir/ProtobufCodecLite.cc.o.requires

muduo/muduo/net/protobuf/CMakeFiles/muduo_protobuf_codec.dir/ProtobufCodecLite.cc.o.provides: muduo/muduo/net/protobuf/CMakeFiles/muduo_protobuf_codec.dir/ProtobufCodecLite.cc.o.requires
	$(MAKE) -f muduo/muduo/net/protobuf/CMakeFiles/muduo_protobuf_codec.dir/build.make muduo/muduo/net/protobuf/CMakeFiles/muduo_protobuf_codec.dir/ProtobufCodecLite.cc.o.provides.build
.PHONY : muduo/muduo/net/protobuf/CMakeFiles/muduo_protobuf_codec.dir/ProtobufCodecLite.cc.o.provides

muduo/muduo/net/protobuf/CMakeFiles/muduo_protobuf_codec.dir/ProtobufCodecLite.cc.o.provides.build: muduo/muduo/net/protobuf/CMakeFiles/muduo_protobuf_codec.dir/ProtobufCodecLite.cc.o


# Object files for target muduo_protobuf_codec
muduo_protobuf_codec_OBJECTS = \
"CMakeFiles/muduo_protobuf_codec.dir/ProtobufCodecLite.cc.o"

# External object files for target muduo_protobuf_codec
muduo_protobuf_codec_EXTERNAL_OBJECTS =

muduo/lib/libmuduo_protobuf_codec.a: muduo/muduo/net/protobuf/CMakeFiles/muduo_protobuf_codec.dir/ProtobufCodecLite.cc.o
muduo/lib/libmuduo_protobuf_codec.a: muduo/muduo/net/protobuf/CMakeFiles/muduo_protobuf_codec.dir/build.make
muduo/lib/libmuduo_protobuf_codec.a: muduo/muduo/net/protobuf/CMakeFiles/muduo_protobuf_codec.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/hms/muduo-tutorial(final)/cmake-submodule/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../../lib/libmuduo_protobuf_codec.a"
	cd "/home/hms/muduo-tutorial(final)/cmake-submodule/muduo/muduo/net/protobuf" && $(CMAKE_COMMAND) -P CMakeFiles/muduo_protobuf_codec.dir/cmake_clean_target.cmake
	cd "/home/hms/muduo-tutorial(final)/cmake-submodule/muduo/muduo/net/protobuf" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/muduo_protobuf_codec.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
muduo/muduo/net/protobuf/CMakeFiles/muduo_protobuf_codec.dir/build: muduo/lib/libmuduo_protobuf_codec.a

.PHONY : muduo/muduo/net/protobuf/CMakeFiles/muduo_protobuf_codec.dir/build

muduo/muduo/net/protobuf/CMakeFiles/muduo_protobuf_codec.dir/requires: muduo/muduo/net/protobuf/CMakeFiles/muduo_protobuf_codec.dir/ProtobufCodecLite.cc.o.requires

.PHONY : muduo/muduo/net/protobuf/CMakeFiles/muduo_protobuf_codec.dir/requires

muduo/muduo/net/protobuf/CMakeFiles/muduo_protobuf_codec.dir/clean:
	cd "/home/hms/muduo-tutorial(final)/cmake-submodule/muduo/muduo/net/protobuf" && $(CMAKE_COMMAND) -P CMakeFiles/muduo_protobuf_codec.dir/cmake_clean.cmake
.PHONY : muduo/muduo/net/protobuf/CMakeFiles/muduo_protobuf_codec.dir/clean

muduo/muduo/net/protobuf/CMakeFiles/muduo_protobuf_codec.dir/depend:
	cd "/home/hms/muduo-tutorial(final)/cmake-submodule" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/hms/muduo-tutorial(final)/cmake-submodule" "/home/hms/muduo-tutorial(final)/cmake-submodule/muduo/muduo/net/protobuf" "/home/hms/muduo-tutorial(final)/cmake-submodule" "/home/hms/muduo-tutorial(final)/cmake-submodule/muduo/muduo/net/protobuf" "/home/hms/muduo-tutorial(final)/cmake-submodule/muduo/muduo/net/protobuf/CMakeFiles/muduo_protobuf_codec.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : muduo/muduo/net/protobuf/CMakeFiles/muduo_protobuf_codec.dir/depend
