using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp1
{
    class Arquivo
    {
       public static void lerArquivo(List<int> l,String endereco)
        {
            try
            {
                var lines = File.ReadAllLines(endereco);
                foreach (var line in lines)
                {

                   l.Add(int.Parse(line));
                }
            }catch(Exception e)
            {
                Console.WriteLine(e);
          
            }

           
            //return 0;
        }
    }
}
