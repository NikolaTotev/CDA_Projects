using System;
using System.Collections.Generic;
using System.Text;

namespace QuickGraphs
{
   class WeightedDirectedGraph
    {
        Dictionary<int, List<Connection>> Nodes = new Dictionary<int, List<Connection>>();
        void AddConnection(int head, int tail, int weight)
        {
            bool containsHead = Nodes.ContainsKey(head);
            bool containsTail = Nodes.ContainsKey(tail);

            if (!containsHead)
            {
                Nodes.Add(head, new List<Connection>());
            }

            if (!containsTail)
            {
                Nodes.Add(tail, new List<Connection>());
            }

           // Connection headConnection = new Connection(tail, weight);
           
           // Nodes[head].Add(headConnection);
        }

    }
}
