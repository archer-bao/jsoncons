// Copyright 2013 Daniel Parker
// Distributed under Boost license

#ifdef __linux__
#define BOOST_TEST_DYN_LINK
#endif

#include <boost/test/unit_test.hpp>
#include <jsoncons/json.hpp>
#include <jsoncons/json_serializer.hpp>
#include <jsoncons/json_filter.hpp>
#include <sstream>
#include <vector>
#include <utility>
#include <ctime>
#include <new>
#include <boost/optional.hpp>

using namespace jsoncons;

BOOST_AUTO_TEST_SUITE(small_string_test_suite)

BOOST_AUTO_TEST_CASE(test_small_string)
{
    json s("ABCD");
    BOOST_CHECK(s.type_id() == jsoncons::value_types::small_string_t);
    BOOST_CHECK(s.as<std::string>() == std::string("ABCD"));

    json t(s);
    BOOST_CHECK(t.type_id() == jsoncons::value_types::small_string_t);
    BOOST_CHECK(t.as<std::string>() == std::string("ABCD"));

    json q;
    q = s;
    BOOST_CHECK(q.type_id() == jsoncons::value_types::small_string_t);
    BOOST_CHECK(q.as<std::string>() == std::string("ABCD"));
}

BOOST_AUTO_TEST_SUITE_END()

