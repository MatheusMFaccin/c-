using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class Lista
    {
        public static void popularLista(List<int> l,int qtd)
        {
            Random random = new Random();

            for (int i = 0; i < qtd; i++)
            {
                l.Add(random.Next(0, 100));
            }
        }
        public static void mostrarLista(List<int> l)
        {
            foreach (int i in l)
            {
                Console.WriteLine(i);
            }
        }
    }
}
