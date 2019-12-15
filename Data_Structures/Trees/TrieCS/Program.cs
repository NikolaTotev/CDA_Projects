using System;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TrieCS
{
    class Program
    {
        static void Main(string[] args)
        { 
            Trie trie = new Trie(true);
            trie.Insert("abba");
            trie.Insert("abbb");
            trie.Insert("abbc");
            trie.Insert("abbd");
            trie.Insert("abbe");
            trie.Insert("abbz");
            trie.Insert("abse");

            trie.WordsStartingWith("abb");
            trie.WordsStartingWith("abs");
        }
    }

    class TrieNode
    {
        private List<TrieNode> chidren;
        private char nodeData;

        public char NodeData
        {
            get => nodeData;
            set => nodeData = value;
        }

        public List<TrieNode> Children { get => chidren; }

        public TrieNode()
        {
            chidren = new List<TrieNode>();
            initList();
            nodeData = ' ';
        }

        public TrieNode(char data)
        {
            chidren = new List<TrieNode>();
            initList();
            nodeData = data;
        }

        private void initList()
        {
            for (int i = 0; i < 26; i++)
            {
                chidren.Add(null);
            }
        }

        public void AddChild(int index, char data)
        {
            if (chidren[index] == null)
            {
                chidren[index] = new TrieNode(data);
            }
        }
    };

    class Trie
    {
        private TrieNode root;
        private bool printMessages;
        private Dictionary<char, int> alphabet = new Dictionary<char, int>()
        {
            {'a',0},{'b',1},{'c',2},{'d',3},{'e',4},
            {'f',5},{'g',6},{'h',7},{'i',8},{'j',9},
            {'k',10},{'l',11},{'m',12},{'n',13},{'o',14},
            {'p',15},{'q',16},{'r',17},{'s',18},{'t',19},
            {'u',20},{'v',21},{'w',22},{'x',23},{'y',24},
            {'z',25},
        };

        bool wordExists(string word)
        {
            TrieNode currentNode = root;
            for (int i = 0; i < word.Length; i++)
            {
                char currentLetter = word[i];
                int letterIndex = alphabet[currentLetter];


                if (currentNode.Children[letterIndex] == null)
                {
                    return false;
                }

                currentNode = currentNode.Children[letterIndex];
            }
            return true;
        }

        int countWords(string prefix)
        {
            bool reachedEndOfPrefix;
            int wordCounter = 0;
            TrieNode currentNode = root;
            for (int i = 0; i < prefix.Length; i++)
            {
                char currentLetter = prefix[i];
                int letterIndex = alphabet[currentLetter];


                if (currentNode.Children[letterIndex] == null)
                {
                    return 0;
                }

                currentNode = currentNode.Children[letterIndex];
            }
            reachedEndOfPrefix =  true;
            wordCounter++;
            for (int i = 0; i < 26; i++)
            {
                if (currentNode.Children[i] != null)
                {
                    wordCounter += countWords(prefix + currentNode.Children[i].NodeData);
                }
            }

            return wordCounter;
        }

        void insertWord(string word)
        {
            TrieNode currentNode = root;
            for (int i = 0; i < word.Length; i++)
            {
                char currentLetter = word[i];
                int letterIndex = alphabet[currentLetter];


                if (currentNode.Children[letterIndex] == null)
                {
                    currentNode.Children[letterIndex] = new TrieNode(word[i]);
                }

                currentNode = currentNode.Children[letterIndex];
            }
            Console.WriteLine("Word inserted successfully!");
        }
        public Trie(bool print)
        {
            printMessages = printMessages;
            root = new TrieNode();
        }

        public void Insert(string word)
        {
            if (wordExists(word))
            {
                Console.WriteLine("This word is already in the Trie.");
                return;
            }
            insertWord(word);
        }

        public void WordsStartingWith(string prefix)
        {
            if (!wordExists(prefix))
            {
                Console.WriteLine("0");
            }

            int result = countWords(prefix)-1;
            Console.WriteLine(result);
        }

    }
}
