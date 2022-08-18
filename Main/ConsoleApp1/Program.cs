using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Threading;


namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            Stopwatch stopWatch = new Stopwatch();
            stopWatch.Start();
            List<int> numerosArquivo = new List<int>();
            String endereco = "C:/Users/laboratorio/Documents/numeros.txt";

            Arquivo.lerArquivo(numerosArquivo,endereco);

            ordenacao.agitacao(numerosArquivo);
            //ordenacao.bolha(numerosArquivo);

            Lista.exibir(numerosArquivo);

            stopWatch.Stop();
            Console.WriteLine(stopWatch.Elapsed);
        }
    }
}
