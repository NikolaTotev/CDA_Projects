using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homework_8_Ex4_Discos
{
    public class PriorityQueue<T> where T : IComparable
    {
        private List<T> data;
        private int size { get; set; }

        public int Count()
        {
            return data.Count;
        }

        public T Front()
        {
            return data[0];
        }

        public PriorityQueue(int numberOfExpectedElements)
        {
            data = new List<T>(numberOfExpectedElements);

        }

        public int Parent(int i) => (i - 1) / 2;
        
        public int LeftChild(int i) => (2 * i + 1);
        
        public int RightChild(int i) => (2 * i + 2);
 

        private void SwapT(int childIndex, int parentIndex)
        {
            T tmp = data[childIndex];
            data[childIndex] = data[parentIndex];
            data[parentIndex] = tmp;
        }
        
        public void Enqueue(T itemToAdd)
        {
            int childIndex = data.Count - 1;
            data.Add(itemToAdd);
            while (childIndex > 0)
            {
                if (data[childIndex].CompareTo(data[Parent(childIndex)]) > 0)
                {
                    break;
                }

                T tmp = data[childIndex];
                data[childIndex] = data[Parent(childIndex)];
                data[Parent(childIndex)] = tmp;
                childIndex = Parent(childIndex);
            }
        }

        public void Dequeue()
        {
            if (Count() > 0)
            {
                int lastIndex = data.Count - 1;
                T frontItem = data[0];
                data[0] = data[lastIndex];
                data.RemoveAt(lastIndex);
                
                MinHeapify(0);
            }
        }

        void MinHeapify(int i)
        {
            int leftIndex = LeftChild(i);
            int rightIndex = RightChild(i);
            int smallest = i;

            if (leftIndex < Count() && data[leftIndex].CompareTo(data[i]) == -1)
            {
                smallest = leftIndex;
            }

            if (rightIndex < Count() && data[rightIndex].CompareTo(data[smallest]) == -1)
            {
                smallest = rightIndex;
            }

            if (smallest != i)
            {
                SwapT(i, smallest);
                MinHeapify(smallest);
            }
        }

        public void Sort()
        {
            int lastIndex = Count();
            for (int i = lastIndex / 2 - 1; i >= 0; i--)
            {
                Heapify(data, lastIndex, i);
            }

            for (int i = lastIndex - 1; i >= 0; i--)
            {
                T temp = data[0];
                data[0] = data[i];
                data[i] = temp;
                Heapify(data, i, 0);
            }
        }

        private static void Heapify(List<T> arr, int lastIndex, int i)
        {
            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (left < lastIndex && arr[left].CompareTo(arr[largest]) == 1)
            {
                largest = left;
            }

            if (right < lastIndex && arr[right].CompareTo(arr[largest]) == 1)
            {
                largest = right;
            }

            if (largest != i)
            {
                T swap = arr[i];
                arr[i] = arr[largest];
                arr[largest] = swap;
                Heapify(arr, lastIndex, largest);
            }
        }
    }
    public class WeightedGraphConnection<T>
    {
        public WeightedUndirectedGraphNode<T> ConnectionNeighbor { get; set; }
        public int ConnectionWeight { get; set; }

        public WeightedGraphConnection(WeightedUndirectedGraphNode<T> connectionNeighbor, int weight)
        {
            ConnectionNeighbor = connectionNeighbor;
            ConnectionWeight = weight;
        }

    }
    public class WeightedUndirectedGraphNode<T> : IComparable
    {
        private readonly Dictionary<T, WeightedGraphConnection<T>> m_Neighbors;
        public T Data { get; set; }
        public bool IsVisited { get; set; }
        public int DistanceToThis { get; set; }

        public WeightedUndirectedGraphNode(T data)
        {

            m_Neighbors = new Dictionary<T, WeightedGraphConnection<T>>();
            Data = data;
        }

        public IReadOnlyDictionary<T, WeightedGraphConnection<T>> GetNeighbors()
        {
            return m_Neighbors;
        }
        public void AddNeighbor(WeightedUndirectedGraphNode<T> neighborToAdd, int connectionWeight)
        {
            if (!m_Neighbors.ContainsKey(neighborToAdd.Data))
            {
                WeightedGraphConnection<T> newConnection = new WeightedGraphConnection<T>(neighborToAdd, connectionWeight);
                m_Neighbors.Add(neighborToAdd.Data, newConnection);
                neighborToAdd.AddNeighbor(this, connectionWeight);
            }
        }

        public void Print()
        {
            Console.Write("{0} ", Data);
        }
        public int CompareTo(object obj)
        {
            if (obj is WeightedUndirectedGraphNode<T> compObj)
            {
                if (compObj.DistanceToThis > DistanceToThis)
                {
                    return -1;
                }

                if (compObj.DistanceToThis == DistanceToThis)
                {
                    return 0;
                }

                if (compObj.DistanceToThis < DistanceToThis)
                {
                    return 1;
                }
            }

            return 2;
        }
    }
    public class WeightedUndirectedGraph<T>
    {
        public Dictionary<T, WeightedUndirectedGraphNode<T>> Nodes { get; set; }
        public int NumberOfComponents { get; set; }

        public WeightedUndirectedGraph(T initialNodeData)
        {
            Nodes = new Dictionary<T, WeightedUndirectedGraphNode<T>>();
            WeightedUndirectedGraphNode<T> initialNode = new WeightedUndirectedGraphNode<T>(initialNodeData);
            Nodes.Add(initialNodeData, initialNode);
            NumberOfComponents = 0;
        }

        public void AddEdge(T vertexOne, T vertexTwo, int connectionWeight)
        {
            if (vertexOne == null) throw new ArgumentNullException(nameof(vertexOne));
            if (vertexTwo == null) throw new ArgumentNullException(nameof(vertexTwo));

            bool v2Index = Nodes.ContainsKey(vertexTwo);
            bool v1Index = Nodes.ContainsKey(vertexOne);

            if (!v1Index)
            {
                WeightedUndirectedGraphNode<T> nodeOne = new WeightedUndirectedGraphNode<T>(vertexOne);
                Nodes.Add(vertexOne, nodeOne);
            }

            if (!v2Index)
            {

                WeightedUndirectedGraphNode<T> nodeTwo = new WeightedUndirectedGraphNode<T>(vertexTwo);
                Nodes.Add(vertexTwo, nodeTwo);
            }


            Nodes[vertexTwo].AddNeighbor(Nodes[vertexOne], connectionWeight);
        }

        public Dictionary<WeightedUndirectedGraphNode<T>, int> FindPath(T source)
        {
            WeightedUndirectedGraphNode<T> sourceNode = Nodes[source];
            Dictionary<WeightedUndirectedGraphNode<T>, int> distances = new Dictionary<WeightedUndirectedGraphNode<T>, int>();
            PriorityQueue<WeightedUndirectedGraphNode<T>> distQueue = new PriorityQueue<WeightedUndirectedGraphNode<T>>(Nodes.Count);

            distances[sourceNode] = 0;
            sourceNode.DistanceToThis = 0;
            distQueue.Enqueue(sourceNode);

            foreach (var node in Nodes)
            {
                if (node.Value != sourceNode)
                {
                    node.Value.DistanceToThis = int.MaxValue;
                    distances[node.Value] = int.MaxValue;
                    distQueue.Enqueue(node.Value);
                }
            }
            while (distQueue.Count() > 0)
            {
                int currentMin = distQueue.Front().DistanceToThis;
                WeightedUndirectedGraphNode<T> currentVertex = distQueue.Front();
                distQueue.Dequeue();

                foreach (var neighbor in currentVertex.GetNeighbors())
                {
                    int alternativeDist = currentMin + neighbor.Value.ConnectionWeight;
                    if (alternativeDist < distances[neighbor.Value.ConnectionNeighbor])
                    {
                        distances[neighbor.Value.ConnectionNeighbor] = alternativeDist;
                        neighbor.Value.ConnectionNeighbor.DistanceToThis = alternativeDist;
                        distQueue.Sort();
                    }
                }
            }
            return distances;
        }
    }
    
    class Program
    {
        static void Main(string[] args)
        {
            int[] discoPathInfo = Array.ConvertAll(Console.ReadLine()?.Trim(' ').Split(), int.Parse);
            int numberOfDiscos = discoPathInfo[0];
            int numberOfKnownRoads = discoPathInfo[1];

            WeightedUndirectedGraph<int> discoGraph = new WeightedUndirectedGraph<int>(0);
            for (int i = 0; i < numberOfKnownRoads; i++)
            {
                int[] discoInfo = Array.ConvertAll(Console.ReadLine()?.Trim(' ').Split(), int.Parse);
                int dicsoOne = discoInfo[0];
                int discoTwo = discoInfo[1];
                int connectionWeight = discoInfo[2];

                discoGraph.AddEdge(dicsoOne, discoTwo, connectionWeight);
            }

            int numberOfDiscosOfInterest = Array.ConvertAll(Console.ReadLine()?.Trim(' ').Split(), int.Parse)[0];
            int[] numbers = Array.ConvertAll(Console.ReadLine()?.Trim(' ').Split(), int.Parse);

            int numberOfRequests = Array.ConvertAll(Console.ReadLine()?.Trim(' ').Split(), int.Parse)[0];

            for (int i = 0; i < numberOfRequests; i++)
            {
                if (numberOfKnownRoads == 0)
                {
                    Console.WriteLine(0);
                }
                int requestPosition = Array.ConvertAll(Console.ReadLine()?.Trim(' ').Split(), int.Parse)[0];
                var results = discoGraph.FindPath(requestPosition);

                int minDist = int.MaxValue;
                foreach (int number in numbers)
                {
                    int discoDist = results[discoGraph.Nodes[number]];
                    if (discoDist < minDist)
                    {
                        minDist = discoDist;
                    }
                }

                Console.WriteLine(minDist);
            }
        }
    }
}
