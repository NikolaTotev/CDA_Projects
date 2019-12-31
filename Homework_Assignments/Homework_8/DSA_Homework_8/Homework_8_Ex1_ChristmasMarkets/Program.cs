using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.Policy;
using System.Text;
using System.Threading.Tasks;

namespace Homework_8_Ex1_ChristmasMarkets
{
    public class DirectedGraphNode<T>
    {
        private readonly Dictionary<T, DirectedGraphNode<T>> m_Neighbors;
        public T Data { get; set; }

        public bool IsVisited { get; set; }

        public DirectedGraphNode(T data)
        {
            m_Neighbors = new Dictionary<T, DirectedGraphNode<T>>();
            Data = data;
        }

        public DirectedGraphNode(DirectedGraphNode<T> initialNeighbor, T data) : this(data)
        {
            m_Neighbors.Add(data, initialNeighbor);
        }

        public IReadOnlyDictionary<T, DirectedGraphNode<T>> GetNeighbors()
        {
            return m_Neighbors;
        }

        public void AddNeighbor(DirectedGraphNode<T> neighborToAdd)
        {
            if (!m_Neighbors.ContainsKey(neighborToAdd.Data))
            {
                m_Neighbors.Add(neighborToAdd.Data, neighborToAdd);
            }
        }
    }
    class Program
    {
        public static Stack<string> Path = new Stack<string>();
        public static bool PathFound = false;
        static void Main(string[] args)
        {
            Dictionary<string, DirectedGraphNode<string>> holidayMarkets =
                new Dictionary<string, DirectedGraphNode<string>>();

            int numberOfTickets = int.Parse(Console.ReadLine()?.Trim(' ').Split().ToArray()[1]);
            if (numberOfTickets == 1)
            {
                Console.WriteLine("-1");
            }
            for (int i = 0; i < numberOfTickets; i++)
            {
                string[] currentTownPair = Console.ReadLine().Trim(' ').Split();

                if (!holidayMarkets.ContainsKey(currentTownPair[0]))
                {
                    holidayMarkets[currentTownPair[0]] = new DirectedGraphNode<string>(currentTownPair[0]);
                }

                if (!holidayMarkets.ContainsKey(currentTownPair[1]))
                {
                    holidayMarkets[currentTownPair[1]] = new DirectedGraphNode<string>(currentTownPair[1]);
                }

                holidayMarkets[currentTownPair[0]].AddNeighbor(holidayMarkets[currentTownPair[1]]);
            }

            string startingCity = Console.ReadLine()?.Trim(' ');


            if (holidayMarkets.Count == 0)
            {
                return;
            }

            if (!Path.Contains(holidayMarkets[startingCity].Data))
            {
                Path.Push(holidayMarkets[startingCity].Data);
            }

            if (!holidayMarkets.ContainsKey(startingCity))
            {
                Console.WriteLine("-1");

            }

            DirectedGraphNode<string> passNode;
            holidayMarkets.TryGetValue(startingCity, out passNode);
            InternalDfs(holidayMarkets, passNode, startingCity);

            foreach (var node in holidayMarkets)
            {
                if (!node.Value.IsVisited)
                {
                    if (!Path.Contains(node.Value.Data))
                    {
                        Path.Push(node.Value.Data);
                    }

                    node.Value.IsVisited = true;
                    InternalDfs(holidayMarkets, node.Value, startingCity);
                }
            }

            if (!PathFound)
            {
                Console.WriteLine("-1");
            }
        }

        public static void InternalDfs(Dictionary<string, DirectedGraphNode<string>> nodes, DirectedGraphNode<string> node, string startCity)
        {
            int childLoopItteration = 0;

            foreach (var neighbor in node.GetNeighbors())
            {
                if (!neighbor.Value.IsVisited)
                {
                    if (!Path.Contains(neighbor.Value.Data))
                    {
                        Path.Push(neighbor.Value.Data);
                    }

                    neighbor.Value.IsVisited = true;
                    InternalDfs(nodes, neighbor.Value, startCity);
                }

                if (node.IsVisited)
                {
                    if (node.Data == startCity && !PathFound)
                    {
                        Console.WriteLine(string.Join(" ", Path.Reverse()) + " " + startCity);
                        PathFound = true;
                        return;
                    }
                    //If not found do nothing;
                }
                childLoopItteration++;

                if (Path.Count > 0 && Path.Peek() != node.Data && !PathFound)
                {
                    Path.Pop();
                }
            }
        }
    }
}
