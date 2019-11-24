#include"Serializer.hpp"
template <class T>
Error Serializer::save(T& object)
{
    return object.serialize(*this);
}

template <class... ArgsT>
Error Serializer::operator()(ArgsT&&... args)
{
    return process(std::forward<ArgsT>(args)...);
}

template<class ArgT>
Error Serializer::process(ArgT&& val)
{
    return print(val);
}
template <class ArgT, class... Args>
Error Serializer::process(ArgT&& val, Args&&... args)
{
    if (process(val) == Error::CorruptedArchive) return Error::CorruptedArchive;
    process(std::forward<Args>(args)...);
    return Error::NoError;
}

Error Serializer::print(uint64_t val)
{
    out_ << val << Separator;
    return (out_)? Error::NoError: Error::CorruptedArchive;
}
Error Serializer::print(bool val)
{

    val? out_ << "true" << Separator: out_ << "false" << Separator;
    return (out_)? Error::NoError: Error::CorruptedArchive;
}

template <class T>
Error Deserializer::load(T& object)
{
    return object.deserialize(*this);
}

template <class... ArgsT>
Error Deserializer:: operator()(ArgsT&&... args)
{
    return process(std::forward<ArgsT>(args)...);
}

template<class ArgT>
Error Deserializer:: process(ArgT&& val)
{
    return read(val);
}
template <class ArgT, class... Args>
Error Deserializer::process(ArgT&& val, Args&&... args)
{
    if (process(val) == Error::CorruptedArchive) return Error::CorruptedArchive;
    process(std::forward<Args>(args)...);
    return Error::NoError;
}

Error Deserializer:: read(uint64_t& val)
{
    //std::string text;
    in_ >> val;

    //std:: cout << val << std::endl;
    return (in_)? Error::NoError: Error::CorruptedArchive;
}
Error Deserializer:: read(bool& val)
{
    std::string reading_string;
    in_ >> reading_string ;
    //std:: cout << reading_string << std::endl;
    if("true"==reading_string)
    {
        val=true;
    }
    else if ("false"==reading_string)
    {
        val=false;
    }
    else
    {
        return Error::CorruptedArchive;
    }
    //std:: cout << val << std::endl;
    return (in_)? Error::NoError: Error::CorruptedArchive;
}

template <class Serializer>
Error Data::serialize(Serializer& serializer)
{
    return serializer(a, b, c);
}

template <class Deserializer>
Error Data::deserialize(Deserializer& deserializer)
{
    return deserializer(a, b, c);
}

