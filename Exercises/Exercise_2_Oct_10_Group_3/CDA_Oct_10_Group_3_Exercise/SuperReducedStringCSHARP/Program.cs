using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SuperReducedStringCSHARP
{
    class Program
    {
        static string SuperReducedString(string input)
        {
            if (input.Length == 0)
            {

                Dictionary<string, bool> neighbourhoodMap = new Dictionary<string, bool>();
                for (int i = 0; i < input.Length; i++)
                {
                    if (input.ElementAt(i) == input.ElementAt(i + 1))
                    {
                        neighbourhoodMap.Add(input.Substring(i, 1), true);
                    }
                    else
                    {
                        neighbourhoodMap.Add(input.Substring(i, 1), false);
                    }
                }

                if (!neighbourhoodMap.ContainsValue(true))
                {
                    return input;
                }

                string reduced = "";
                for (int i = 0; i < neighbourhoodMap.Count; i++)
                {
                    if (neighbourhoodMap.ElementAt(i).Value == false)
                    {
                        reduced += neighbourhoodMap.ElementAt(i).Key;
                    }
                }

                SuperReducedString(reduced);

            }
            return "Empty String";

        }

        static void Main(string[] args)
        {
           Console.WriteLine(SuperReducedString("aaabccddd")); 
        }

        
    }
}
