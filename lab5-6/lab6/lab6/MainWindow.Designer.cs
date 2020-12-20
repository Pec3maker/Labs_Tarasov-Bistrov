
namespace lab6
{
    partial class MainWindow
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.AddButton = new System.Windows.Forms.Button();
            this.ChoosePairBox = new System.Windows.Forms.ComboBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.ChooseTable = new System.Windows.Forms.ListBox();
            this.DeleteButton = new System.Windows.Forms.Button();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.CalculateButton = new System.Windows.Forms.Button();
            this.radioButtonMinus = new System.Windows.Forms.RadioButton();
            this.radioButtonPlus = new System.Windows.Forms.RadioButton();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.SecondNumBox = new System.Windows.Forms.ComboBox();
            this.FirstNumBox = new System.Windows.Forms.ComboBox();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.ResultTextBox = new System.Windows.Forms.RichTextBox();
            this.pairBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.groupBox4.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pairBindingSource)).BeginInit();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.textBox2);
            this.groupBox1.Controls.Add(this.textBox1);
            this.groupBox1.Controls.Add(this.AddButton);
            this.groupBox1.Controls.Add(this.ChoosePairBox);
            this.groupBox1.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.9F);
            this.groupBox1.Location = new System.Drawing.Point(12, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.groupBox1.Size = new System.Drawing.Size(218, 133);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Choose pair type";
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(112, 59);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(100, 26);
            this.textBox2.TabIndex = 3;
            this.textBox2.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.textBox2_KeyPress);
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(5, 59);
            this.textBox1.MaxLength = 10;
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(100, 26);
            this.textBox1.TabIndex = 2;
            this.textBox1.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.textBox1_KeyPress);
            // 
            // AddButton
            // 
            this.AddButton.Location = new System.Drawing.Point(63, 91);
            this.AddButton.Name = "AddButton";
            this.AddButton.Size = new System.Drawing.Size(88, 35);
            this.AddButton.TabIndex = 1;
            this.AddButton.Text = "Add";
            this.AddButton.UseVisualStyleBackColor = true;
            this.AddButton.Click += new System.EventHandler(this.AddButton_Click);
            // 
            // ChoosePairBox
            // 
            this.ChoosePairBox.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.ChoosePairBox.Items.AddRange(new object[] {
            "Money",
            "Complex number"});
            this.ChoosePairBox.Location = new System.Drawing.Point(5, 25);
            this.ChoosePairBox.Name = "ChoosePairBox";
            this.ChoosePairBox.Size = new System.Drawing.Size(207, 28);
            this.ChoosePairBox.TabIndex = 0;
            this.ChoosePairBox.SelectedIndexChanged += new System.EventHandler(this.ChoosePairBox_SelectedIndexChanged);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.ChooseTable);
            this.groupBox2.Controls.Add(this.DeleteButton);
            this.groupBox2.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.8F);
            this.groupBox2.Location = new System.Drawing.Point(12, 161);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(218, 282);
            this.groupBox2.TabIndex = 1;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Pairs";
            // 
            // ChooseTable
            // 
            this.ChooseTable.FormattingEnabled = true;
            this.ChooseTable.ItemHeight = 20;
            this.ChooseTable.Location = new System.Drawing.Point(6, 25);
            this.ChooseTable.Name = "ChooseTable";
            this.ChooseTable.Size = new System.Drawing.Size(207, 204);
            this.ChooseTable.TabIndex = 2;
            // 
            // DeleteButton
            // 
            this.DeleteButton.Location = new System.Drawing.Point(6, 238);
            this.DeleteButton.Name = "DeleteButton";
            this.DeleteButton.Size = new System.Drawing.Size(207, 38);
            this.DeleteButton.TabIndex = 0;
            this.DeleteButton.Text = "Delete";
            this.DeleteButton.UseVisualStyleBackColor = true;
            this.DeleteButton.Click += new System.EventHandler(this.DeleteButton_Click);
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.CalculateButton);
            this.groupBox3.Controls.Add(this.radioButtonMinus);
            this.groupBox3.Controls.Add(this.radioButtonPlus);
            this.groupBox3.Controls.Add(this.label2);
            this.groupBox3.Controls.Add(this.label1);
            this.groupBox3.Controls.Add(this.SecondNumBox);
            this.groupBox3.Controls.Add(this.FirstNumBox);
            this.groupBox3.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.8F);
            this.groupBox3.Location = new System.Drawing.Point(262, 12);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(350, 254);
            this.groupBox3.TabIndex = 2;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Operations";
            // 
            // CalculateButton
            // 
            this.CalculateButton.Location = new System.Drawing.Point(6, 192);
            this.CalculateButton.Name = "CalculateButton";
            this.CalculateButton.Size = new System.Drawing.Size(338, 54);
            this.CalculateButton.TabIndex = 6;
            this.CalculateButton.Text = "Calculate";
            this.CalculateButton.UseVisualStyleBackColor = true;
            this.CalculateButton.Click += new System.EventHandler(this.CalculateButton_Click);
            // 
            // radioButtonMinus
            // 
            this.radioButtonMinus.AutoSize = true;
            this.radioButtonMinus.Location = new System.Drawing.Point(11, 65);
            this.radioButtonMinus.Name = "radioButtonMinus";
            this.radioButtonMinus.Size = new System.Drawing.Size(75, 24);
            this.radioButtonMinus.TabIndex = 5;
            this.radioButtonMinus.TabStop = true;
            this.radioButtonMinus.Text = "Minus";
            this.radioButtonMinus.UseVisualStyleBackColor = true;
            // 
            // radioButtonPlus
            // 
            this.radioButtonPlus.AutoSize = true;
            this.radioButtonPlus.Location = new System.Drawing.Point(11, 35);
            this.radioButtonPlus.Name = "radioButtonPlus";
            this.radioButtonPlus.Size = new System.Drawing.Size(63, 24);
            this.radioButtonPlus.TabIndex = 4;
            this.radioButtonPlus.TabStop = true;
            this.radioButtonPlus.Text = "Plus";
            this.radioButtonPlus.UseVisualStyleBackColor = true;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(217, 126);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(102, 20);
            this.label2.TabIndex = 3;
            this.label2.Text = "Second num";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(7, 126);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(104, 20);
            this.label1.TabIndex = 2;
            this.label1.Text = "First number";
            // 
            // SecondNumBox
            // 
            this.SecondNumBox.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.SecondNumBox.FormattingEnabled = true;
            this.SecondNumBox.Location = new System.Drawing.Point(220, 149);
            this.SecondNumBox.Name = "SecondNumBox";
            this.SecondNumBox.Size = new System.Drawing.Size(124, 28);
            this.SecondNumBox.TabIndex = 1;
            // 
            // FirstNumBox
            // 
            this.FirstNumBox.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.FirstNumBox.FormattingEnabled = true;
            this.FirstNumBox.Location = new System.Drawing.Point(6, 149);
            this.FirstNumBox.Name = "FirstNumBox";
            this.FirstNumBox.Size = new System.Drawing.Size(121, 28);
            this.FirstNumBox.TabIndex = 0;
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.ResultTextBox);
            this.groupBox4.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.8F);
            this.groupBox4.Location = new System.Drawing.Point(262, 272);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(350, 165);
            this.groupBox4.TabIndex = 7;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Result";
            // 
            // ResultTextBox
            // 
            this.ResultTextBox.AccessibleName = "ResultTextBox";
            this.ResultTextBox.Cursor = System.Windows.Forms.Cursors.IBeam;
            this.ResultTextBox.Location = new System.Drawing.Point(3, 22);
            this.ResultTextBox.Name = "ResultTextBox";
            this.ResultTextBox.ReadOnly = true;
            this.ResultTextBox.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.ResultTextBox.Size = new System.Drawing.Size(341, 137);
            this.ResultTextBox.TabIndex = 0;
            this.ResultTextBox.Text = "";
            // 
            // pairBindingSource
            // 
            this.pairBindingSource.DataSource = typeof(lab6.Pair);
            // 
            // MainWindow
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(627, 454);
            this.Controls.Add(this.groupBox4);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Name = "MainWindow";
            this.Text = "Laba5-6";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.groupBox4.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pairBindingSource)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.BindingSource pairBindingSource;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.ComboBox ChoosePairBox;
        private System.Windows.Forms.Button AddButton;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Button DeleteButton;
        private System.Windows.Forms.ListBox ChooseTable;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox SecondNumBox;
        private System.Windows.Forms.ComboBox FirstNumBox;
        private System.Windows.Forms.RadioButton radioButtonMinus;
        private System.Windows.Forms.RadioButton radioButtonPlus;
        private System.Windows.Forms.Button CalculateButton;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.RichTextBox ResultTextBox;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.TextBox textBox1;
    }
}

