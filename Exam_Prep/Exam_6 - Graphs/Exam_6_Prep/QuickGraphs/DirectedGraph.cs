using System;
using System.Collections.Generic;
using System.Text;

namespace QuickGraphs
{
    class DirectedGraph
    {
        Dictionary<int, List<int>> Nodes =  new Dictionary<int, List<int>>();

        void AddConnection(int head, int tail)
        {
            bool containsHead = Nodes.ContainsKey(head);
            bool containsTail = Nodes.ContainsKey(tail);

            if (!containsHead)
            {
                Nodes.Add(head, new List<int>());
            }

            if (!containsTail)
            {
                Nodes.Add(tail, new List<int>());
            }

            Nodes[head].Add(tail);
        }
    }

}
