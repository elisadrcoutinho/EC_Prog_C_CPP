using System;
 
class Program{
    static void Main(){
 /*
        Console.WriteLine("Tamanho em bytes de um SByte: " + sizeof(SByte));
        Console.WriteLine("Valor mínimo de um SByte: " + SByte.MinValue);
        Console.WriteLine("Valor máximo de um SByte: " + SByte.MaxValue);
 
        Console.WriteLine("---------------------------------------------------------------");
 
        Console.WriteLine("Tamanho em bytes de um Byte: " + sizeof(Byte));
        Console.WriteLine("Valor mínimo de um Byte: " + Byte.MinValue);
        Console.WriteLine("Valor máximo de um Byte: " + Byte.MaxValue);
 
        Console.WriteLine("---------------------------------------------------------------");
 
        Console.WriteLine("Tamanho em bytes de um Boolean: " + sizeof(Boolean));
        Console.WriteLine("Valor mínimo de um Boolean: " + Boolean.FalseString);
        Console.WriteLine("Valor máximo de um Boolean: " + Boolean.TrueString);
 
        Console.WriteLine("---------------------------------------------------------------");
 
        Console.WriteLine("Tamanho em bytes de um Char: " + sizeof(Char));
        Console.WriteLine("Valor mínimo de um Char: " + Char.MinValue);
        Console.WriteLine("Valor máximo de um Char: " + Char.MaxValue);
 
        Console.WriteLine("---------------------------------------------------------------");
 
        Console.WriteLine("Tamanho em bytes de um Short: " + sizeof(Int16));
        Console.WriteLine("Valor mínimo de um Short: " + Int16.MinValue);
        Console.WriteLine("Valor máximo de um Short: " + Int16.MaxValue);
 
        Console.WriteLine("---------------------------------------------------------------");
 
        Console.WriteLine("Tamanho em bytes de um UShort: " + sizeof(UInt16));
        Console.WriteLine("Valor mínimo de um UShort: " + UInt16.MinValue);
        Console.WriteLine("Valor máximo de um UShort: " + UInt16.MaxValue);
 
        Console.WriteLine("---------------------------------------------------------------");
 
        Console.WriteLine("Tamanho em bytes de um Integer: " + sizeof(Int32));
        Console.WriteLine("Valor mínimo de um Integer: " + Int32.MinValue);
        Console.WriteLine("Valor máximo de um Integer: " + Int32.MaxValue);
 
        Console.WriteLine("---------------------------------------------------------------");
 
        Console.WriteLine("Tamanho em bytes de um Long: " + sizeof(Int64));
        Console.WriteLine("Valor mínimo de um Long: " + Int64.MinValue);
        Console.WriteLine("Valor máximo de um Long: " + Int64.MaxValue);
 
        Console.WriteLine("---------------------------------------------------------------");
 
        Console.WriteLine("Tamanho em bytes de um ULong: " + sizeof(UInt64));
        Console.WriteLine("Valor mínimo de um ULong: " + UInt64.MinValue);
        Console.WriteLine("Valor máximo de um ULong: " + UInt64.MaxValue);
 
        Console.WriteLine("---------------------------------------------------------------");
 
        Console.WriteLine("Tamanho em bytes de um Float: " + sizeof(Single));
        Console.WriteLine("Valor mínimo de um Float: " + Single.MinValue);
        Console.WriteLine("Valor máximo de um Float: " + Single.MaxValue);
 
        Console.WriteLine("---------------------------------------------------------------");
 
        Console.WriteLine("Tamanho em bytes de um Decimal: " + sizeof(Decimal));
        Console.WriteLine("Valor mínimo de um Decimal: " + Decimal.MinValue);
        Console.WriteLine("Valor máximo de um Decimal: " + Decimal.MaxValue);
 
        Console.WriteLine("---------------------------------------------------------------");
 
        Console.WriteLine("Tamanho em bytes de um Double: " + sizeof(Double));
        Console.WriteLine("Valor mínimo de um Double: " + Double.MinValue);
        Console.WriteLine("Valor máximo de um Double: " + Double.MaxValue);
        */
 
 /*
        Console.WriteLine("Enter your age: ");
        string ageString = Console.ReadLine()!;
        if (int.TryParse(ageString, out int age))
        {
            Console.WriteLine("Your age is " + age);
        }
        else
        {
            Console.WriteLine("Invalid input. Please enter a valid number.");
        }
        Console.Write("Enter your name: ");
        string input = Console.ReadLine();
        string name = string.IsNullOrWhiteSpace(input) ? "Unkhnown" : input;
        Console.WriteLine($"Hello {name}!");
        */
 
 /*
        Console.Write("Enter two numbers separated by spaces: ");
        string umExemplo = Console.ReadLine()!;
        string[] num = umExemplo.Split(' ');
        int num1, num2, soma;
        if (int.TryParse(num[0], out num1) && int.TryParse(num[1], out num2))
        {
            soma = num1 + num2;
            Console.WriteLine("Soma: " + soma);
        }
        else
        {
            Console.WriteLine("Invalid input.");
        }
        */
        
 /* DESAFIO 1
         Console.Write("Digite um número: ");
         string input = Console.ReadLine();

         // Verificar se o input é um número válido
         if (int.TryParse(input, out int numero))
         { 
             string reverso = ReverterNumero(input);

             if (input == reverso)
             { 
                 Console.WriteLine($"O número {numero} é um palíndromo.");
             }
             else
             {
                 Console.WriteLine($"O número {numero} não é um palíndromo.");
             }
 }
 else
 {
     Console.WriteLine("Entrada inválida! Por favor, insira um número.");
 }
    }

    static string ReverterNumero(string numero)
    {
        char[] caracteres = numero.ToCharArray();
        Array.Reverse(caracteres);
        return new string(caracteres);
        
        */
 
 // DESAFIO 2
 
         Console.Write("Digite um número de dois dígitos ou mais: ");
         string input = Console.ReadLine();

         // Verificar se a entrada é válida
         if (int.TryParse(input, out int numero))
         {
             int soma = 0;

             // Loop para calcular a soma dos dígitos
             while (numero > 0)
             {
                 int resto = numero % 10; // Obter o último dígito
                 soma += resto;          // Somar o dígito
                 numero /= 10;           // Remover o último dígito
             }

             Console.WriteLine($"A soma dos dígitos é: {soma}");
         }
         else
         {
             Console.WriteLine("Entrada inválida! Por favor, insira um número inteiro.");
         }
 
    }
}

