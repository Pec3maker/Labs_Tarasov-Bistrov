using System;

namespace lab6
{
    abstract class Factory
    {
        public abstract Pair CreatePair(int first, int second);
    }

    class FactoryMoney : Factory
    {
        public override Pair CreatePair(int first, int second)
        {
            return new Money(first, second);
        }
    }

    class FactoryComplex : Factory
    {
        public override Pair CreatePair(int first, int second)
        {
            return new Complex(first, second);
        }
    }
}
