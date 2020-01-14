using System;

namespace QuickGraphs
{
    class Program
    {
        static void Main(string[] args)
        {
            WeightedUndirectedGraph graph1 = new WeightedUndirectedGraph();
            graph1.AddConnection("A", "B", 2);
            graph1.AddConnection("A", "C", 3);
            graph1.AddConnection("A", "D", 3);

            graph1.AddConnection("B", "C", 4);
            graph1.AddConnection("B", "E", 9);

            graph1.AddConnection("C", "E", 1);
            graph1.AddConnection("C", "F", 6);

            graph1.AddConnection("D", "F", 7);

            graph1.AddConnection("E", "F", 8);

            graph1.AddConnection("F", "G", 9);


            //MST_Algorithms.Prim(graph1);
            MST_Algorithms.Kruskal(graph1);

        }
    }
}
