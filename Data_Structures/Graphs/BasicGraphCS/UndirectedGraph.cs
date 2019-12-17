using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.ExceptionServices;
using System.Text;
using System.Threading.Tasks;

namespace BasicGraphCS
{
    public class GraphNode
    {
        private GraphNode parent;
        private bool isVisited;
        private Dictionary<int, GraphNode> neighbors;
        private int data;

        public int Data { get; set; }
        public GraphNode Parent { get; set; }
        public bool IsVisited { get; set; }
        public Dictionary<int, GraphNode> Neighbors { get; set; }

        public GraphNode(int data, GraphNode parentNode = null)
        {
            Parent = parentNode;
            Neighbors = new Dictionary<int, GraphNode>();
            Data = data;
            IsVisited = false;
        }

    }

    public class UndirectedGraph
    {
        private Dictionary<int, GraphNode> vertecies;
        private int graphSize;

        public int GraphSize { get => graphSize; set => graphSize = value; }
        public Dictionary<int, GraphNode> Vertecies { get => vertecies; set => vertecies = value; }
        public UndirectedGraph()
        {
            Vertecies = new Dictionary<int, GraphNode>();
        }

        public void AddVertex(GraphNode firstNode, GraphNode secondNode)
        {
            if (firstNode == null || secondNode == null)
            {
                return;
            }

            if (vertecies.ContainsKey(firstNode.Data) || vertecies.ContainsKey(secondNode.Data))
            {
                //First node is already in the graph and we only want to add the second one.
                if (vertecies.ContainsKey(firstNode.Data) && !vertecies.ContainsKey(secondNode.Data))
                {
                    //Add second one to nodes in graph.
                    vertecies.Add(secondNode.Data, secondNode);

                    //Add second node into the neighbor list of the first one and add the first node into the neighbor list of the second one.
                    firstNode.Neighbors.Add(secondNode.Data, secondNode);
                    secondNode.Neighbors.Add(firstNode.Data, firstNode);

                    //Increase graph size counter;
                    GraphSize++;
                    return;
                }


                //Second node is already in the graph and we want to only add the first one.
                if (!vertecies.ContainsKey(firstNode.Data) && vertecies.ContainsKey(secondNode.Data))
                {
                    //Add first one to nodes in graph.
                    vertecies.Add(firstNode.Data, firstNode);

                    //Add first node into the neighbor list of the second one and the second node to the neighbor list of the first one.
                    secondNode.Neighbors.Add(firstNode.Data, firstNode);
                    firstNode.Neighbors.Add(secondNode.Data, secondNode);
                    GraphSize++;
                    return;
                }
            }

            //Add to list of available nodes
            vertecies.Add(firstNode.Data, firstNode);
            vertecies.Add(secondNode.Data, secondNode);

            //Insert into list of neighbors for each node.
            firstNode.Neighbors.Add(secondNode.Data, secondNode);
            secondNode.Neighbors.Add(firstNode.Data, firstNode);
        }

        private void internalDFS(GraphNode currentContext)
        {
            Stack<GraphNode> nodeStack = new Stack<GraphNode>();
            currentContext.IsVisited = true;
            nodeStack.Push(currentContext);

            while (nodeStack.Count!=0)
            {
                currentContext = nodeStack.Pop();
                Console.WriteLine("{0}",currentContext.Data);

                foreach (var neighbor in currentContext.Neighbors)
                {
                    if (!neighbor.Value.IsVisited)
                    {
                        neighbor.Value.IsVisited = true;
                        nodeStack.Push(neighbor.Value);
                    }
                }
            }
        }

        public void DFS()
        {
            internalDFS(vertecies[0]);
        }
    }
}
