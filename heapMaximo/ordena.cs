using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class ordena
    {
        public static Boolean estaOrdenado(List<int> l)
        {
            for(int i = 0; i < l.Count(); i++)
            {
                if (l[i] > l[i+1])
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
            return true;
        }
        public static Boolean estaHeapMaximo(List<int> l)
        {
            
            for(int i = 1; i < l.Count(); i++)
            {
                
                    if (l[i] < l[i * 2]||(i*2+1)<l.Count() && l[i] < l[i*2+1])
                    {

                        return false;

                    }
                    

                
                
            }

            return true;
        }
        public static void pente(List<int> l)
        {
            int i, tmp, dist = l.Count;
            bool troca;
            do
            {
                troca = false;
                dist = (int)((float)dist / 1.3);

                for (i = 0; i + dist < l.Count; i++)
                {
                    if (l[i] > l[i + dist])
                    {

                        tmp = l[i];
                        l[i] = l[i + dist];
                        l[i + dist] = tmp;
                        troca = true;
                    }
                }


            } while (dist > 1 || troca == true);

        }






    }
}
