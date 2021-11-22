#include "EndianSafeBinaryStream.hpp"

#include <iostream>
#include <string>
#include <vector>

struct ExampleStruct
{
    int32_t a;
    bool b;
    uint64_t c;

    float f;
};

// a custom extension for the struct above
namespace esbs
{
    template <>
    struct EndianSafeBinaryStreamExtension<ExampleStruct>
    {

        template <typename Stream>
        static EndianSafeBinaryStream<Stream> &serialize(EndianSafeBinaryStream<Stream> &stream, const ExampleStruct &v)
        {
            stream << v.a << v.b << v.c << v.f;
            return stream;
        }

        template <typename Stream>
        static EndianSafeBinaryStream<Stream> &deserialize(EndianSafeBinaryStream<Stream> &stream, ExampleStruct &v)
        {
            stream >> v.a >> v.b >> v.c >> v.f;
            return stream;
        }
    };
}

int main(int argc, char **args)
{

    // serialize (write) data
    {
        // create the stream
        esbs::EndianSafeBinaryStream<std::fstream> stream = esbs::output_to_file("test.bin");

        // basic data types
        uint32_t number1 = 123456789;
        int16_t number2 = -16;
        double number3 = 15.89;

        stream << number1 << number2 << number3;

        // advanced data type using the optional (activated by default) extensions
        std::string example_message = "Hello World :)";
        stream << example_message;

        std::vector<uint64_t> multiples_of_two;
        uint64_t multiple = 1;
        for (int i = 0; i < 64; i++)
        {
            multiples_of_two.push_back(multiple);
            multiple *= 2;
        }
        stream << multiples_of_two;

        // using a custom implemented extension for a custom object
        ExampleStruct s;
        s.a = -5555555;
        s.b = true,
        s.c = 1357913579;
        s.f = 42.42f;

        stream << s;
    }

    // deserialize (read) data
    {

        // create the stream
        esbs::EndianSafeBinaryStream<std::fstream> stream = esbs::input_from_file("test.bin");

        // basic data types
        uint32_t number1;
        int16_t number2;
        double number3;

        stream >> number1 >> number2 >> number3;

        std::cout << "number1: " << number1 << std::endl;
        std::cout << "number2: " << number2 << std::endl;
        std::cout << "number3: " << number3 << std::endl;

        // advanced data type using the optional (activated by default) extensions
        std::string example_message;
        stream >> example_message;

        std::cout << "example_message: " << example_message << std::endl;

        std::vector<uint64_t> multiples_of_two;
        stream >> multiples_of_two;

        std::cout << "multiples_of_two: [";
        for (int i = 0; i < multiples_of_two.size(); i++)
        {
            std::cout << " " << multiples_of_two[i];
        }
        std::cout << " ]" << std::endl;

        // using a custom implemented extension for a custom object
        ExampleStruct s;
        stream >> s;

        std::cout << "ExampleStruct s: { a: " << s.a << ", b: " << s.b << ", c: "
                  << s.c << ", f: " << s.f << " }" << std::endl;
    }

    return 0;
}
