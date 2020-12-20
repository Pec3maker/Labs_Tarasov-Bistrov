using System;
using System.Collections.Generic;
using System.Text;

namespace lab6
{
    class Complex : Pair
    {

        public Complex(int first, int second) : base(first, second) { }

        public override string GetPair()
        {
            return _first + " + " + _second + "i";
        }

        public override Pair Minus(Pair source)
        {
            int resFirst = _first;
            int resSecond = _second;

            resFirst -= source.GetFirst;
            resSecond -= source.GetSecond;
            return new Complex(resFirst, resSecond);
        }

        public override Pair Plus(Pair source)
        {
            int resFirst = _first;
            int resSecond = _second;

            resFirst += source.GetFirst;
            resSecond += source.GetSecond;
            return new Complex(resFirst, resSecond);
        }
    }
}
