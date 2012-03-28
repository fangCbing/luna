#ifndef VALUE_H
#define VALUE_H

#include <string>
#include <functional>

namespace lua
{
    enum TypeId
    {
        TYPE_NIL,
        TYPE_BOOL,
        TYPE_NUMBER,
        TYPE_STRING,
        TYPE_TABLE,
        TYPE_FUNCTION,
        TYPE_NATIVE_FUNCTION,
    };

    class Value
    {
    public:
        virtual ~Value() { }
        virtual int Type() const = 0;
        virtual std::string Name() const = 0;
        virtual std::size_t GetHash() const = 0;
        virtual bool IsEqual(const Value *other) const = 0;
    };

    struct ValueHasher : public std::unary_function<Value *, std::size_t>
    {
        std::size_t operator() (const Value *value) const
        {
            return value->GetHash();
        }
    };

    struct ValueEqualer : public std::binary_function<Value *, Value *, bool>
    {
        bool operator() (const Value *left, const Value *right) const
        {
            return left->IsEqual(right);
        }
    };
} // namespace lua

#endif // VALUE_H
