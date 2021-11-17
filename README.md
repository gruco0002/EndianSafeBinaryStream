# EndianSafeBinaryStream

A C++ implementation of a platform independent endian safe binary file stream
that can save primitive types and is easily extendable.
The data is always saved as little endian encoded (since most platforms are
little-endian based) independent of the endianess of the platform that is
running the code. This ensures interoperability between systems of different
endianess.

Currently the sources require the c++17 standard due to the filesystem header
and some minor things. This can easily be changed if you require compatibility
to previous standards.

## How to install
The easiest way is copying the two source files (`EndianSafeBinaryStream.cpp`
and `EndianSafeBinaryStream.hpp`) to your project and compile and link them
with your other source code files.

## Example
See the `example.cpp` file of this repository. To compile and run the example
yourself, just run `make compile` and then `make run`. To clean any files
created by this process run `make clean`.

## Extensions
There are currently two default extensions for writing/reading std::vector
and std::string. You can turn them off by removing the
`ENDIAN_SAFE_BINARY_STREAM_DEFAULT_EXTENSIONS` define from the top of the
`EndianSafeBinaryStream.hpp` file. By default they are turned on. You can
also write your own extensions as shown in the `example.cpp` file.

## License
See the `LICENSE` file.
