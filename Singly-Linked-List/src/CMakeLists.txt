
# Create an executable from the driver program.
add_executable(main main.cpp)


# This controls the `-I` (include paths) switch of the compiler invocation.
# Since `include` is declared `PUBLIC` for the library, it is propagated to all the
# consumers of the library.
target_include_directories(main PUBLIC ${CMAKE_SOURCE_DIR}/include)


# Specify warnings flags to the compiler for the target library. As the warnings are specified as
# `PRIVATE`, they will only be used when compiling this library. The flags will not be propagated to
# the targets linking to it.
target_compile_options(main PRIVATE ${WARNING_FLAGS})


# Set the parent directory for the target binaries as `bin` directory inside the "installation directory".
# The installation directory is set to `/usr/local` by default. Installing softwares there ensures that
# those are automatically available to users. You may need root access (use `sudo`) for such.
# To specify a different parent installation directory, pass the directory as the value of the
# `-DCMAKE_INSTALL_PREFIX` with the `cmake` command.
install(TARGETS main
        DESTINATION bin
        )