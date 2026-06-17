#pragma once

#include <cmath> // Для використання pow()

namespace Project3 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
            // Розміщення даних про задачу та автора
            richTextBox1->Text = "ЗАВДАННЯ 1: Використання циклів\n";
            richTextBox1->AppendText("Варіант 10: Знайти суму k^k від 1 до n\n");
            richTextBox1->AppendText("Автор: Нефедова К. Є.\n");
            richTextBox1->AppendText("----------------------------------\n");
        }

    protected:
        ~MyForm()
        {
            if (components) delete components;
        }

    private: System::Windows::Forms::RichTextBox^ richTextBox1;
    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::TextBox^ textBox1;

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->SuspendLayout();

            // richTextBox1 (Верхнє велике поле)
            this->richTextBox1->Location = System::Drawing::Point(70, 30);
            this->richTextBox1->Name = L"richTextBox1";
            this->richTextBox1->Size = System::Drawing::Size(240, 240);
            this->richTextBox1->TabIndex = 0;
            this->richTextBox1->Text = L"";

            // button1 (Кнопка "обчисли")
            this->button1->Location = System::Drawing::Point(120, 290);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(130, 35);
            this->button1->TabIndex = 1;
            this->button1->Text = L"обчисли";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);

            // textBox1 (Нижнє поле введення n)
            this->textBox1->Location = System::Drawing::Point(90, 345);
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(190, 22);
            this->textBox1->TabIndex = 2;

            // MyForm
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(380, 420);
            this->Controls->Add(this->textBox1);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->richTextBox1);
            this->Name = L"MyForm";
            this->Text = L"Використання циклів";
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            // Забезпечення очищення та перевірка вхідних даних
            if (String::IsNullOrWhiteSpace(textBox1->Text)) return;

            int n = Convert::ToInt32(textBox1->Text);
            double sum = 0;

            // Реалізація алгоритму обчислення суми через цикл for
            for (int k = 1; k <= n; k++) {
                sum += std::pow(k, k); // Додавання k у степені k до загальної суми
            }

            // Виведення результату у richTextBox
            richTextBox1->AppendText("При n = " + n + " сума = " + sum + "\n");

            // Очищення поля введення для нового розрахунку
            textBox1->Clear();
        }
        catch (Exception^) {
            MessageBox::Show("Будь ласка, введіть ціле число!");
            textBox1->Clear();
        }
    }
    };
}