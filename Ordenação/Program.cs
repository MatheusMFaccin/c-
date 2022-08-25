using Ordenação;
using System.IO;
public class Program {

    public static void Main()
    {
        String directory = "C:/Users/laboratorio/Documents/numeros.txt";
         List<int> l = new List<int>();

        Arquivo f = new Arquivo();
        Ordena ord = new Ordena();

        f.Read(directory, l);

        ord.pente(l);

        foreach(var i in l) 
        { 
        Console.WriteLine(i);
        
        }



    }






}
    
