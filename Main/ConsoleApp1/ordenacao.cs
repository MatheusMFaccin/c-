using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp1
{
    class ordenacao
    {
        public static void agitacao(List<int> l)
        {
            Boolean houveTroca;
            int i, temp, inicio = 0, fim = l.Count -1;

            do
            {
                houveTroca = false;
                for (i = inicio; i < fim; i++)
                {
                    if (l[i] > l[i + 1])
                    {
                        houveTroca = true;
                        temp = l[i];
                        l[i] = l[i + 1];
                        l[i + 1] = temp;
                    }
                }
                fim--;
                for (i = fim; i > inicio; i--)
                {
                    if (l[i] < l[i - 1])
                    {
                        houveTroca = true;
                        temp = l[i];
                        l[i] = l[i - 1];
                        l[i - 1] = temp;
                    }
                }
                inicio++;

            } while (houveTroca == true&&inicio<=fim);


        }
        public static void bolha(List<int> l)
        {
            Boolean houveTroca;
            int i, temp;
            do
            {
                houveTroca = false;
                for (i = 0; i < l.Count - 1; i++)
                {
                    if (l[i] < l[i + 1])
                    {
                        houveTroca = true;
                        temp = l[i];
                        l[i] = l[i + 1];
                        l[i + 1] = temp;
                    }
                    
                }

            } while (houveTroca == true);
        }
    }

}
