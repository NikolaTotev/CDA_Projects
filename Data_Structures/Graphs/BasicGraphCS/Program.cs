using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BasicGraphCS
{
    class Program
    {
        static void Main(string[] args)
        {
            UndirectedGraph graph = new UndirectedGraph();
            GraphNode newNode = new GraphNode(1);
            GraphNode newNode2 = new GraphNode(2);
            
            graph.AddVertex(newNode, newNode2);
        }
    }
}
