using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            
            List<int> lista = new List<int>();
            Console.WriteLine("digite a quantidade numeros gerados");
            int qtd = Int32.Parse(Console.ReadLine());
            Lista.popularLista(lista,qtd);
            Console.WriteLine("lista desordenada \n");
            Lista.mostrarLista(lista);
            Console.WriteLine("lista ordenada \n");
            ordena.pente(lista);
            Lista.mostrarLista(lista);
            Console.WriteLine("\n");
            
            if (ordena.estaOrdenado(lista) == false)
            {
                Console.WriteLine("não esta ordenado");
                Console.WriteLine("\n");
            }
            else
            {
                Console.WriteLine("esta ordenado");
            }
            if (ordena.estaHeapMaximo(lista) == false)
            {
                Console.WriteLine("não esta heapMaximo");
                Console.WriteLine("\n");
            }
            else
            {
                Console.WriteLine("esta heapMaximo");
                Console.WriteLine("\n");
            }

        }
    }
}
