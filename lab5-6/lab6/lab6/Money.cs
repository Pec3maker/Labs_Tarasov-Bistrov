using System;

namespace lab6
{
    class Money : Pair
    {

        public Money(int first, int second) : base(first, second)
        {
            if (_second > MAX_SECOND)
            {
                _first += _second / MAX_SECOND;
                _second = _second % MAX_SECOND;
            }

            if (_first < 0 || _second < 0)
            {
                throw new ArgumentOutOfRangeException("Less than zero\n");
            }
        }

        public override string GetPair()
        {
            string result = _first + "." + _second + " rub";
            return result;
        }

        public override Pair Minus(Pair source)
        {
            int firstInt = source.GetFirst;
            int secondInt = source.GetSecond;

            int resFirst = _first;
            int resSecond = _second;

            resFirst = (_first > firstInt) ? _first - firstInt : 0;

            if (_second >= secondInt)
            {
                resSecond = _second - secondInt;
            }
            else if (_first == 1)
            {
                resFirst = _first - 1;
                resSecond = _second - secondInt + MAX_SECOND;
            }
            else
            {
                resSecond = 0;
            }

            return new Money(resFirst, resSecond);
        }

        public override Pair Plus(Pair source)
        {
            int firstInt = source.GetFirst;
            int secondInt = source.GetSecond;

            int resFirst = _first;
            int resSecond = _second;

            resFirst += firstInt + (_second + secondInt) / MAX_SECOND;
            resSecond = (_second + secondInt) % MAX_SECOND;

            return new Money(resFirst, resSecond);
        }

        private readonly int MAX_SECOND = 100;
    }
}
