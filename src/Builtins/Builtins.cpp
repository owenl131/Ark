#define _USE_MATH_DEFINES
#include <cmath>
#include <limits>

#include <Ark/Builtins/Builtins.hpp>

#define Builtins_Function(name) Value name(std::vector<Value>& n)

namespace Ark::internal::Builtins
{
    extern const Value falseSym = Value(ValueType::False);
    extern const Value trueSym  = Value(ValueType::True);
    extern const Value nil      = Value(ValueType::Nil);

    namespace Mathematics
    {
        extern const Value pi_  = Value(M_PI);
        extern const Value e_   = Value(std::exp(1.0));
        extern const Value tau_ = Value(M_PI * 2.0);
        extern const Value inf_ = Value(HUGE_VAL);
        extern const Value nan_ = Value(std::numeric_limits<double>::signaling_NaN());
    }

    extern const std::vector<std::pair<std::string, Value>> builtins = {
        // builtin variables or constants
        { "false",  falseSym },
        { "true",   trueSym },
        { "nil",    nil },

        // List
        { "append", Value(List::append) },
        { "concat", Value(List::concat) },
        { "list",   Value(List::list) },
        { "list:reverse", Value(List::reverseList) },
        { "list:find", Value(List::findInList) },
        { "list:removeAt", Value(List::removeAtList) },
        { "list:slice", Value(List::sliceList) },
        { "list:sort", Value(List::sort_) },
        { "list:fill", Value(List::fill) },
        { "list:setAt", Value(List::setListAt) },

        // IO
        { "print",  Value(IO::print) },
        { "puts", Value(IO::puts_) },
        { "input",  Value(IO::input) },
        { "io:writeFile", Value(IO::writeFile) },
        { "io:readFile", Value(IO::readFile) },
        { "io:fileExists?", Value(IO::fileExists) },
        { "io:listFiles", Value(IO::listFiles) },
        { "io:dir?", Value(IO::isDirectory) },
        { "io:makeDir", Value(IO::makeDir) },
        { "io:removeFiles", Value(IO::removeFiles) },

        // Time
        { "time", Value(Time::timeSinceEpoch) },

        // System
        { "sys:exec", Value(System::system_) },
        { "sys:sleep", Value(System::sleep) },

        // String
        { "str:format", Value(String::format) },
        { "str:find", Value(String::findSubStr) },
        { "str:removeAt", Value(String::removeAtStr) },

        // Mathematics
        { "math:exp", Value(Mathematics::exponential) },
        { "math:ln", Value(Mathematics::logarithm) },
        { "math:ceil", Value(Mathematics::ceil_) },
        { "math:floor", Value(Mathematics::floor_) },
        { "math:round", Value(Mathematics::round_) },
        { "math:NaN?", Value(Mathematics::isnan_) },
        { "math:Inf?", Value(Mathematics::isinf_) },
        { "math:pi", Mathematics::pi_ },
        { "math:e", Mathematics::e_ },
        { "math:tau", Mathematics::tau_ },
        { "math:Inf", Mathematics::inf_ },
        { "math:NaN", Mathematics::nan_ },
        { "math:cos", Value(Mathematics::cos_) },
        { "math:sin", Value(Mathematics::sin_) },
        { "math:tan", Value(Mathematics::tan_) },
        { "math:arccos", Value(Mathematics::acos_) },
        { "math:arcsin", Value(Mathematics::asin_) },
        { "math:arctan", Value(Mathematics::atan_) }
    };

    // This list is related to include/Ark/Compiler/Instructions.hpp
    // from FIRST_OPERATOR, to LAST_OPERATOR
    // The order is very important
    extern const std::vector<std::string> operators = {
        "+", "-", "*", "/",
        ">", "<", "<=", ">=", "!=", "=",
        "len", "empty?", "firstOf", "tailOf", "headOf",
        "nil?", "assert",
        "toNumber", "toString",
        "@", "and", "or", "mod",
        "type", "hasField",
        "not"
    };
}
