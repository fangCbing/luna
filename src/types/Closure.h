#ifndef CLOSURE_H
#define CLOSURE_H

#include "Value.h"

namespace lua
{
    class Table;
    class Function;

    class Closure : public Value
    {
    public:
        Closure(Function *func, Table *upvalue);

        virtual int Type() const
        {
            return TYPE_FUNCTION;
        }

        virtual std::string Name() const
        {
            return "function";
        }

        virtual std::size_t GetHash() const;
        virtual bool IsEqual(const Value *other) const;

        Table * GetUpvalueTable()
        {
            return upvalue_table_;
        }

    private:
        Function *func_;
        Table *upvalue_table_;
    };
} // namespace lua

#endif // CLOSURE_H
