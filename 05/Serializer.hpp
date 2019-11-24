#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<string>
#include <sstream>
#include<assert.h>

enum class Error
{
    NoError,
    CorruptedArchive
};
struct Data
{
    uint64_t a;
    bool b;
    uint64_t c;

    template <class Serializer>
    Error serialize(Serializer& serializer)
    {
        return serializer(a, b, c);
    }

    template <class Deserializer>
    Error deserialize(Deserializer& deserializer)
    {
        return deserializer(a, b, c);
    }
};
class Serializer
{
    static constexpr char Separator = ' ';
    std::ostream& out_;
public:
    explicit Serializer(std::ostream& out)
        : out_(out)
    {
    }

    template <class T>
    Error save(T& object)
    {
        return object.serialize(*this);
    }

    template <class... ArgsT>
    Error operator()(ArgsT&&... args)
    {
        return process(std::forward<ArgsT>(args)...);
    }

private:

    template<class ArgT>
    Error process(ArgT&& val)
    {
        return print(val);
    }
    template <class ArgT, class... Args>
    Error process(ArgT&& val, Args&&... args)
    {
        if (process(val) == Error::CorruptedArchive) return Error::CorruptedArchive;
        process(std::forward<Args>(args)...);
        return Error::NoError;
    }

    Error print(uint64_t val)
    {
        out_ << val << Separator;
        return (out_)? Error::NoError: Error::CorruptedArchive;
    }
    Error print(bool val)
    {

        val? out_ << "true" << Separator: out_ << "false" << Separator;
        return (out_)? Error::NoError: Error::CorruptedArchive;
    }
};
class Deserializer
{
    static constexpr char Separator = ' ';
    std::istream& in_;
    public:
        explicit Deserializer(std::istream& in)
            : in_(in)
        {
        }

        template <class T>
        Error load(T& object)
        {
            return object.deserialize(*this);
        }

        template <class... ArgsT>
        Error operator()(ArgsT&&... args)
        {
            return process(std::forward<ArgsT>(args)...);
        }

    private:

        template<class ArgT>
        Error process(ArgT&& val)
        {
            return read(val);
        }
        template <class ArgT, class... Args>
        Error process(ArgT&& val, Args&&... args)
        {
            if (process(val) == Error::CorruptedArchive) return Error::CorruptedArchive;
            process(std::forward<Args>(args)...);
            return Error::NoError;
        }

        Error read(uint64_t& val)
        {
            //std::string text;
            in_ >> val;

            //std:: cout << val << std::endl;
            return (in_)? Error::NoError: Error::CorruptedArchive;
        }
        Error read(bool& val)
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

};
