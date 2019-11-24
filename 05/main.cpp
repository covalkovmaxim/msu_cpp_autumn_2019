#include "Serializer.hpp"

int main()
{
    Data x { 1, true, 2 };

    std::stringstream stream;

    Serializer serializer(stream);
    serializer.save(x);

    assert( stream.str()=="1 true 2 ");
    std::cout << "Serialixer is correct" << std::endl;
    Data y { 7, false, 0 };

    Deserializer deserializer(stream);
    const Error err = deserializer.load(y);

    assert(err == Error::NoError);

    assert(x.a == y.a);
    assert(x.b == y.b);
    assert(x.c == y.c);
    std::cout << "Deserialixer is correct" << std::endl;
    return 0;
}
