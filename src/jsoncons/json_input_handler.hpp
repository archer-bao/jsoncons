// Copyright 2013 Daniel Parker
// Distributed under the Boost license, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// See https://github.com/danielaparker/jsoncons for latest version

#ifndef JSONCONS_JSON_INPUT_HANDLER_HPP
#define JSONCONS_JSON_INPUT_HANDLER_HPP

#include <string>
#include <jsoncons/json_text_traits.hpp>
#include <jsoncons/parse_error_handler.hpp>

namespace jsoncons {

template <class CharT>
class basic_json_input_handler
{
private:
    basic_default_parse_error_handler<CharT> default_err_handler_;
    basic_parse_error_handler<CharT> *err_handler_;
public:
    basic_json_input_handler()
        : err_handler_(&default_err_handler_)
    {}

    virtual ~basic_json_input_handler() {}

    basic_parse_error_handler<CharT>& error_handler() 
    {
        return *err_handler_;
    }

    void error_handler(basic_parse_error_handler<CharT>& err_handler) 
    {
        err_handler_ = std::addressof(err_handler);
    }

    void begin_json()
    {
        do_begin_json();
    }

    void end_json()
    {
        do_end_json();
    }

    void begin_object(const basic_parsing_context<CharT>& context)
    {
        do_begin_object(context);
    }

    void end_object(const basic_parsing_context<CharT>& context)
    {
        do_end_object(context);
    }

    void begin_array(const basic_parsing_context<CharT>& context)
    {
        do_begin_array(context);
    }

    void end_array(const basic_parsing_context<CharT>& context)
    {
        do_end_array(context);
    }

    void name(const std::basic_string<CharT>& name, const basic_parsing_context<CharT>& context)
    {
        do_name(name.data(), name.length(), context);
    }

    void name(const CharT* p, size_t length, const basic_parsing_context<CharT>& context) 
    {
        do_name(p, length, context);
    }

    void value(const std::basic_string<CharT>& value, const basic_parsing_context<CharT>& context) 
    {
        do_string_value(value.data(), value.length(), context);
    }

    void value(const CharT* p, size_t length, const basic_parsing_context<CharT>& context) 
    {
        do_string_value(p, length, context);
    }

    void value(const CharT* p, const basic_parsing_context<CharT>& context) 
    {
        do_string_value(p, std::char_traits<CharT>::length(p), context);
    }

    void integer_value(const CharT* p, size_t length, 
                       const basic_parsing_context<CharT>& context) 
    {
        do_integer_value(p, length, context);
    }

    void value(int value, const basic_parsing_context<CharT>& context) 
    {
        do_integer_value(value,context);
    }

    void value(long value, const basic_parsing_context<CharT>& context) 
    {
        do_integer_value(value,context);
    }

    void value(long long value, const basic_parsing_context<CharT>& context) 
    {
        do_integer_value(value,context);
    }

    void value(unsigned int value, const basic_parsing_context<CharT>& context) 
    {
        do_uinteger_value(value,context);
    }

    void value(unsigned long value, const basic_parsing_context<CharT>& context) 
    {
        do_uinteger_value(value,context);
    }

    void value(unsigned long long value, const basic_parsing_context<CharT>& context) 
    {
        do_uinteger_value(value,context);
    }

    void value(float value, uint8_t precision, const basic_parsing_context<CharT>& context)
    {
        do_double_value(value, precision, context);
    }

    void value(double value, uint8_t precision, const basic_parsing_context<CharT>& context)
    {
        do_double_value(value, precision, context);
    }

    void value(bool value, const basic_parsing_context<CharT>& context) 
    {
        do_bool_value(value,context);
    }

    void value(null_type, const basic_parsing_context<CharT>& context)
    {
        do_null_value(context);
    }

private:
    virtual void do_begin_json() = 0;

    virtual void do_end_json() = 0;

    virtual void do_begin_object(const basic_parsing_context<CharT>& context) = 0;

    virtual void do_end_object(const basic_parsing_context<CharT>& context) = 0;

    virtual void do_begin_array(const basic_parsing_context<CharT>& context) = 0;

    virtual void do_end_array(const basic_parsing_context<CharT>& context) = 0;

    virtual void do_name(const CharT* name, size_t length, const basic_parsing_context<CharT>& context) = 0;

    virtual void do_null_value(const basic_parsing_context<CharT>& context) = 0;

    virtual void do_string_value(const CharT* value, size_t length, const basic_parsing_context<CharT>& context) = 0;

    virtual void do_double_value(double value, uint8_t precision, const basic_parsing_context<CharT>& context) = 0;

    virtual void do_integer_value(const CharT* p, size_t length,
                                  const basic_parsing_context<CharT>& context) = 0;

    virtual void do_integer_value(int64_t value, const basic_parsing_context<CharT>& context) = 0;

    virtual void do_uinteger_value(uint64_t value, const basic_parsing_context<CharT>& context) = 0;

    virtual void do_bool_value(bool value, const basic_parsing_context<CharT>& context) = 0;
};

template <class CharT>
class basic_null_json_input_handler : public basic_json_input_handler<CharT>
{
public:
    static basic_json_input_handler<CharT>& instance()
    {
        static basic_null_json_input_handler<CharT> instance;
        return instance;
    }
private:
    void do_begin_json() override
    {
    }

    void do_end_json() override
    {
    }

    void do_begin_object(const basic_parsing_context<CharT>&) override
    {
    }

    void do_end_object(const basic_parsing_context<CharT>&) override
    {
    }

    void do_begin_array(const basic_parsing_context<CharT>&) override
    {
    }

    void do_end_array(const basic_parsing_context<CharT>&) override
    {
    }

    void do_name(const CharT* p, size_t length, const basic_parsing_context<CharT>&) override
    {
        (void)p;
        (void)length;
    }

    void do_null_value(const basic_parsing_context<CharT>&) override
    {
    }

    void do_string_value(const CharT* p, size_t length, const basic_parsing_context<CharT>&) override
    {
        (void)p;
        (void)length;
    }

    void do_double_value(double, uint8_t, const basic_parsing_context<CharT>&) override
    {
    }

    void do_integer_value(const CharT*, size_t, 
                          const basic_parsing_context<CharT>&) override
    {
    }

    void do_integer_value(int64_t, const basic_parsing_context<CharT>&) override
    {
    }

    void do_uinteger_value(uint64_t, const basic_parsing_context<CharT>&) override
    {
    }

    void do_bool_value(bool, const basic_parsing_context<CharT>&) override
    {
    }
};

typedef basic_json_input_handler<char> json_input_handler;
typedef basic_json_input_handler<wchar_t> wjson_input_handler;

typedef basic_null_json_input_handler<char> empty_json_input_handler;
typedef basic_null_json_input_handler<wchar_t> wempty_json_input_handler;

}

#endif
