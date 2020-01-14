using System;
using System.Collections.Generic;
using System.Text;

namespace QuickGraphs
{
    public class Connection
    {
        public string Data { get; set; }
        public int Weight { get; set; }

        public Connection(string data, int weight)
        {
            Data = data;
            Weight = weight;
        }
    }

    public class Edge
    {
        public string Node1 { get; set; }
        public string Node2 { get; set; }
        public int Weight { get; set; }

        public Edge(string node1, string node2, int weight)
        {
            Node1 = node1;
            Node2 = node2;
            Weight = weight;
        }

        public void PrintEdge()
        {
            Console.WriteLine("{0} : {1} - {2}", Node1, Node2, Weight.ToString());
        }
    }
    public class WeightedUndirectedGraph
    {
        public Dictionary<string, List<Connection>> Nodes = new Dictionary<string, List<Connection>>();
        public List<Edge> edges = new List<Edge>();

        public void AddConnection(string node1, string node2, int weight)
        {
            bool containsNode1 = Nodes.ContainsKey(node1);
            bool containsNode2 = Nodes.ContainsKey(node2);

            if (!containsNode1)
            {
                Nodes.Add(node1, new List<Connection>());
            }

            if (!containsNode2)
            {
                Nodes.Add(node2, new List<Connection>());
            }

            Connection node1Connection = new Connection(node2, weight);
            Connection node2Connection = new Connection(node1, weight);
            Edge newEdge = new Edge(node1,node2,weight);
            Nodes[node1].Add(node1Connection);
            Nodes[node2].Add(node2Connection);
            edges.Add(newEdge);
        }
    }
}
