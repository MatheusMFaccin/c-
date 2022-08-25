using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ordenação
{
    internal class Arquivo
    {
        public void Read(String directory, List<int> l)
        {
            try 
            {
                StreamReader sr = new StreamReader(directory);

                var lines = sr.ReadLine();

                while(lines != null)
                {
                    l.Add(int.Parse(lines));
                    lines = sr.ReadLine();
                }
                sr.Close();


            }catch(Exception e) 
            {

                Console.WriteLine("erro: " + e);
            
            }
        }

        
    }
}
