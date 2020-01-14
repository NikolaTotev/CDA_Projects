using System;
using System.Collections.Generic;
using System.Text;

namespace QuickGraphs
{
    class UndirectedGraph
    {
        Dictionary<int, List<int>> Nodes = new Dictionary<int, List<int>>();


        void AddConnection(int node1, int node2)
        {
            bool containsNode1 = Nodes.ContainsKey(node1);
            bool containsNode2 = Nodes.ContainsKey(node2);

            if (!containsNode1)
            {
                Nodes.Add(node1, new List<int>());
            }

            if (!containsNode2)
            {
                Nodes.Add(node2, new List<int>());
            }

            Nodes[node1].Add(node2);
            Nodes[node2].Add(node1);
        }
    }
}
