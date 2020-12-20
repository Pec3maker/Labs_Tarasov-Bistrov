using System;

namespace lab6
{
    abstract class Pair
    {
        protected int _first = 0;
        protected int _second = 0;

        public int GetFirst
        {
            get
            {
                return _first;
            }
        }
        public int GetSecond
        {
            get
            {
                return _second;
            }
        }

        public Pair(int first, int second)
        {
            _first = first;
            _second = second;
        }

        abstract public Pair Plus(Pair source);
        abstract public Pair Minus(Pair source);
        abstract public string GetPair();

    }
}
