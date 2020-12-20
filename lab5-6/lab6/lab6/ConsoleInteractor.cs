using System;

namespace lab6
{
    class ConsoleInteractor
    {
        public ConsoleInteractor()
        {
            Console.Write("Enter space for Pairs\n>> ");
            _count = Convert.ToInt32(Console.ReadLine());
            _names = new string[_count];
            _cases = new Pair[_count];
        }

        public void Init()
        {
            int code, arg; string name, name2;
            bool flag = true;
            while (flag)
            {
                Console.Write("Enter \"3\" - Help\n");
                Console.Write(">> ");
                code = Convert.ToInt32(Console.ReadLine());

                switch (code)
                {
                    case 1:
                        CreatePair();
                        break;
                    case 2:
                        DelPair();
                        break;
                    case 3:
                        Help();
                        break;
                    case 4:
                        Plus();
                        break;
                    case 5:
                        Minus();
                        break;
                    case 6:
                        PrintPair();
                        break;
                    case 7:
                        flag = false;
                        break;
                }
            }
        }


        private int GetIndex(string name)
        {
            for (int i = 0; i < _count; i++)
            {
                if (name == _names[i])
                {
                    return i;
                }
            }
            return -1;
        }

        private void Minus()
        {
            string name, name2;
            Console.Write("Enter name of first pair\n>> ");
            name = Console.ReadLine();
            Console.Write("Enter name of second pair\n>> ");
            name2 = Console.ReadLine();

            int indexName1 = GetIndex(name);
            int indexName2 = GetIndex(name2);

            if (indexName1 != -1 && indexName2 != -1)
            {
                Console.Write(_cases[indexName1].GetPair() + "\n-\n");
                Console.Write(_cases[indexName2].GetPair() + "\n");
                Console.Write(_cases[indexName1].Minus(_cases[indexName2]).GetPair() + "\n");
            }
            else
            {
                Console.Write("Wrond name\n");
            }
        }

        private void Plus()
        {
            string name, name2;
            Console.Write("Enter name of first pair\n>> ");
            name = Console.ReadLine();
            Console.Write("Enter name of second pair\n>> ");
            name2 = Console.ReadLine();

            int indexName1 = GetIndex(name);
            int indexName2 = GetIndex(name2);

            if (indexName1 != -1 && indexName2 != -1)
            {
                Console.Write(_cases[indexName1].GetPair() + "\n+\n");
                Console.Write(_cases[indexName2].GetPair() + "\n");
                Console.Write(_cases[indexName1].Plus(_cases[indexName2]).GetPair() + "\n");
            }
            else
            {
                Console.Write("Wrond name\n");
            }
        }

        private void Help()
        {
            Console.Write("\"1\" - Create new pair\n\"2\" - Delete pair\n\"3\" - Help\n\"4\" - Plus\n\"5\" - Minus\n\"6\" - Print pair\n\"7\" - Exit\n");
        }

        private void CreatePair()
        {
            int firstNum, secondNum;
            Console.Write("Enter first num:\n>> ");
            firstNum = Convert.ToInt32(Console.ReadLine());

            Console.Write("Enter second num:\n>> ");
            secondNum = Convert.ToInt32(Console.ReadLine());

            Console.Write("Enter name of Pair:\n>> ");
            string name;
            name = Console.ReadLine();

            int type;
            Console.Write("Is it Complex or Money (1 or 2):\n>> ");
            type = Convert.ToInt32(Console.ReadLine());

            bool isEnoughtSpace = false;
            int index = -1;
            for (int i = 0; i < _count && !isEnoughtSpace; i++)
            {
                if (_names[i] == null)
                {
                    isEnoughtSpace = true;
                    index = i;
                }
            }

            if (isEnoughtSpace)
            {
                FactoryComplex factoryComplex = new FactoryComplex();
                FactoryMoney factoryMoney = new FactoryMoney();
                Pair newElement = null;
                if (type == 1)
                {
                    newElement = factoryComplex.CreatePair(firstNum, secondNum);
                }
                else if (type == 2)
                {
                    try
                    {
                        newElement = factoryMoney.CreatePair(firstNum, secondNum);
                    }
                    catch (ArgumentOutOfRangeException err)
                    {
                        Console.Write(err.Message);
                        return;
                    }
                }

                _names[index] = name;
                _cases[index] = newElement;
            }
            else
            {
                Console.Write("You don't have enought space, delete something\n");
            }
        }

        private void DeletePair(string name)
        {
            int index = GetIndex(name);

            if (index == -1)
            {
                Console.Write("Can't find pair with this name\n");
            }
            else
            {
                _names[index] = null;
                _cases[index] = null;
            }
        }

        private void PrintPair()
        {
            string name;
            Console.Write("Enter name of pair to print\n>> ");
            name = Console.ReadLine();
            int index = GetIndex(name);
            if (index != -1)
            {
                Console.Write(_cases[index].GetPair() + "\n");
            }
            else
            {
                Console.Write("Wrong name\n");
            }
        }

        private void DelPair()
        {
            string name;
            Console.Write("Enter name of pair to delete\n>> ");
            name = Console.ReadLine();
            DeletePair(name);
            Console.Write("Complete\n");

        }

        private Pair[] _cases = null;
        private string[] _names = null;
        private int _count = 0;
    }
}
