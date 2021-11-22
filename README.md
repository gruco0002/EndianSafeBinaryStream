# EndianSafeBinaryStream

A C++ implementation of a platform independent endian safe binary stream
that can save primitive types and is easily extendable.
The data is always written as little endian encoded (since most platforms are
little-endian based) independent of the endianess of the platform that is
running the code. This ensures interoperability between systems of different
endianess.

The implementation is template based and can be used for different kind of
streams (not only std::fstream), as long as they support some of the basic
operations that are required.

The sources require the C++17 standard due to the filesystem header and some
minor things. This can easily be changed if you require compatibility to
previous standards.

## How to install
The easiest way is copying the source file (`EndianSafeBinaryStream.hpp`)
to your project and include it where you need it in your other source files.

## Example
See the `example.cpp` file of this repository. To compile and run the example
yourself, just run `make compile` and then `make run`. To clean any files
created by this process run `make clean`.

## Extensions and Helpers
There are currently two default extensions for writing/reading std::vector
and std::string. You can turn them off by removing the
`ENDIAN_SAFE_BINARY_STREAM_DEFAULT_EXTENSIONS` define from the top of the
`EndianSafeBinaryStream.hpp` file. By default they are turned on. You can
also write your own extensions as shown in the `example.cpp` file.

For reading from or writing to a file the implementation provides two helper
functions that can be turned off by removing the
`ENDIAN_SAFE_BINARY_STREAM_FSTREAM_HELPER` define from the top of the
`EndianSafeBinaryStream.hpp` file. By default they are turned on.

## License
See the `LICENSE` file.
