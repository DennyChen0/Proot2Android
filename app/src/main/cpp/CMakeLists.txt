# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.18.1)

# Declares and names the project.

project("testforsvctrace")

enable_language(C ASM) #设置支持的语言，C 和 ASM（内联汇编）
#add_definitions(-DHAVE_SECCOMP_FILTER)
add_definitions(-D_GNU_SOURCE)
include_directories(
        proot
        proot/cli
        proot/execve
        proot/extension
        #    proot/extension/care
        proot/extension/portmap
        proot/extension/python
        proot/loader
        proot/path
        proot/ptrace
        proot/syscall
        proot/tracee
        proot/lib/uthash/include/

        talloc/
        talloc/lib/replace/
        #        talloc/lib/replace/test/
        talloc/bin/default/

)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
        testforsvctrace

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        native-lib.cpp
        proot/loader/assembly.S
        proot/loader/loader.c
        proot/.check_seccomp_filter.c
        proot/ptrace/ptrace.c
        proot/ptrace/wait.c
        proot/ptrace/user.c
        proot/execve/elf.c
        proot/execve/enter.c
        proot/execve/ldso.c
        proot/execve/exit.c
        proot/execve/aoxp.c
        proot/execve/shebang.c
        proot/execve/auxv.c
        proot/path/canon.c
        proot/path/path.c
        proot/path/glue.c
        proot/path/temp.c
        proot/path/binding.c
        proot/path/proc.c
        proot/.check_process_vm.c
        proot/syscall/sysnum.c
        proot/syscall/chain.c
        proot/syscall/enter.c
        proot/syscall/seccomp.c
        proot/syscall/exit.c
        proot/syscall/rlimit.c
        proot/syscall/heap.c
        proot/syscall/socket.c
        proot/syscall/syscall.c
        proot/tracee/tracee.c
        proot/tracee/reg.c
        proot/tracee/mem.c
        proot/tracee/event.c
        proot/cli/cli.c
        proot/cli/note.c
        proot/cli/care.c
        proot/cli/proot.c
        proot/extension/python/proot.i
        #        proot/extension/python/python.c
        proot/extension/link2symlink/link2symlink.c
        proot/extension/kompat/kompat.c
        proot/extension/fake_id0/fake_id0.c
        proot/extension/care/archive.c
        proot/extension/care/care.c
        proot/extension/care/final.c
        proot/extension/care/extract.c
        proot/extension/extension.c
        proot/extension/portmap/portmap.c
        proot/extension/portmap/map.c
        # talloc src
        talloc/lib/replace/cwrap.c
        talloc/lib/replace/replace.c
        #        lib/replace/test/testsuite.c
        #        lib/replace/test/strptime.c
        #        lib/replace/test/os2_delete.c
        #        lib/replace/test/getifaddrs.c
        #        testsuite_main.c
        #        testsuite.c
        talloc/talloc.c
        )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.


find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
        testforsvctrace

        # Links the target library to the log library
        # included in the NDK.
        ${log-lib}
        archive
        )

add_subdirectory(libarchive)