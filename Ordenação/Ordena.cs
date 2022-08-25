using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ordenação
{
    internal class Ordena
    {
        public void pente(List<int> l) 
        {
            int i, tmp, dist = l.Count;
            bool troca;
            do
            {
                troca = false;
                dist = (int)((float)dist / 1.3);

                for(i = 0; i+dist < l.Count; i++)
                {
                    if(l[i] > l[i + dist]) {
                        
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
