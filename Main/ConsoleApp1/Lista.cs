using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp1
{
    class Lista
    {
        public static void exibir(List<int> l)
        {
            foreach (var n in l)
            {
                Console.WriteLine(n);
            } 
        }
    }
}
