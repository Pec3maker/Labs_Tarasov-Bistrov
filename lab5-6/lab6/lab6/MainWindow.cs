using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace lab6
{
    public partial class MainWindow : Form
    {
        private List<Pair> _cases = new List<Pair>();
        int pairType = 0;

        public MainWindow()
        {
            InitializeComponent();
        }

        private void AddButton_Click(object sender, EventArgs e)
        {
            if (pairType != 0 && textBox1.Text.Length != 0 && textBox2.Text.Length != 0)
            {
                try
                {
                    CreatePair(Convert.ToInt32(textBox1.Text), Convert.ToInt32(textBox2.Text), pairType);
                }
                catch(FormatException err)
                {
                    return;
                }
            }
        }

        private void ChoosePairBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (Convert.ToString(ChoosePairBox.SelectedItem) == "Money")
            {
                pairType = 2;
            }
            else if (Convert.ToString(ChoosePairBox.SelectedItem) == "Complex number")
            {
                pairType = 1;
            }
        }

        private void CalculateButton_Click(object sender, EventArgs e)
        {
            int selectedIndex1 = FirstNumBox.SelectedIndex;
            int selectedIndex2 = SecondNumBox.SelectedIndex;

            if (selectedIndex1 > -1 && selectedIndex1 < _cases.Count && selectedIndex2 > -1 && selectedIndex2 < _cases.Count)
            {
                if (radioButtonMinus.Checked)
                {
                    Minus(selectedIndex1, selectedIndex2);
                }
                else if (radioButtonPlus.Checked)
                {
                    Plus(selectedIndex1, selectedIndex2);
                }
            }
        }

        private void Minus(int index, int index2)
        {
            if (_cases[index].GetType() == _cases[index2].GetType())
            {
                ResultTextBox.Text = _cases[index].GetPair() + "\n-\n";
                ResultTextBox.Text += _cases[index2].GetPair() + "\n";
                ResultTextBox.Text += _cases[index].Minus(_cases[index2]).GetPair() + "\n";
            }
        }

        private void Plus(int index, int index2)
        {
            if (_cases[index].GetType() == _cases[index2].GetType())
            {
                ResultTextBox.Text = _cases[index].GetPair() + "\n+\n";
                ResultTextBox.Text += _cases[index2].GetPair() + "\n";
                ResultTextBox.Text += _cases[index].Plus(_cases[index2]).GetPair() + "\n";
            }
        }

        private void CreatePair(int firstNum, int secondNum, int type)
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
                    //Console.Write(err.Message);
                    return;
                }
            }

            _cases.Add(newElement);
            ChooseTable.Items.Add(newElement.GetPair());
            FirstNumBox.Items.Add(newElement.GetPair());
            SecondNumBox.Items.Add(newElement.GetPair());
        }


        private void DeletePair(int index)
        {
            _cases.RemoveAt(index);
        }

        private void textBox1_KeyPress(object sender, KeyPressEventArgs e)
        {
            char number = e.KeyChar;
            if (!Char.IsDigit(number) && number != 8 && number != '-')
            {
                e.Handled = true;
            }
        }

        private void textBox2_KeyPress(object sender, KeyPressEventArgs e)
        {
            char number = e.KeyChar;
            if (!Char.IsDigit(number) && number != 8 && number != '-')
            {
                e.Handled = true;
            }
        }

        private void DeleteButton_Click(object sender, EventArgs e)
        {
            if(ChooseTable.Items.Count != 0)
            {
                int index = ChooseTable.SelectedIndex;
                if (index > -1 && index < _cases.Count)
                {
                    ChooseTable.Items.RemoveAt(index);
                    FirstNumBox.Items.RemoveAt(index);
                    SecondNumBox.Items.RemoveAt(index);
                    DeletePair(index);
                }
            }
        }
    }
}

