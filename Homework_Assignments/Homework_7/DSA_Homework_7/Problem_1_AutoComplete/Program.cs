using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;


namespace Problem_1_AutoComplete
{
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
        private List<string> dictionary;
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
        int wordCounter = 0;

        int countWords(string prefix)
        {
            bool reachedEndOfPrefix;
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
            reachedEndOfPrefix = true;
            if (dictionary.Contains(prefix))
            {
                wordCounter++;
            }
            
            for (int i = 0; i < 26; i++)
            {
                if (currentNode.Children[i] != null)
                {
                    string currentWord = prefix+currentNode.Children[i].NodeData;
                    countWords(prefix + currentNode.Children[i].NodeData);
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

            
            if (printMessages)
            {
                Console.WriteLine("Word inserted successfully!");
            }
        }
        public Trie(bool print, List<string> validWords)
        {
            printMessages = printMessages;
            root = new TrieNode();
            dictionary = validWords;
        }

        public void Insert(string word)
        {
            if (wordExists(word))
            {
                if (printMessages)
                {
                    Console.WriteLine("This word is already in the Trie.");
                }
                return;
            }
            insertWord(word);
        }

        public void WordsStartingWith(string prefix)
        {
            if (!wordExists(prefix))
            {
                Console.WriteLine("0");
                return;
            }
            wordCounter = 0;
            int result = countWords(prefix) - 1;
            Console.WriteLine(result);
        }

    }

    class Program
    {
        static void Main(string[] args)
        {

            int numberOfWords;
            int numberOfBeginnings;
            string initValues = Console.ReadLine();
            string initFixed = initValues.Trim(' ');

            string[] initNumbers = initFixed.Split(' ');
            int[] numbersConverted = Array.ConvertAll(initNumbers, int.Parse);

            numberOfWords = numbersConverted[0];
            numberOfBeginnings = numbersConverted[1];

            string availableWords = Console.ReadLine();
            List<string> words = availableWords.Split().ToList();
            Trie trie = new Trie(false, words);

            foreach (var word in words)
            {
                trie.Insert(word);
            }


            List<string> beginnings = new List<string>();
            for (int i = 0; i < numberOfBeginnings; i++)
            {
                string inputBeginning = Console.ReadLine();
                beginnings.Add(inputBeginning);
            }

            for (int i = 0; i < numberOfBeginnings; i++)
            {
                trie.WordsStartingWith(beginnings[i]);
            }
        }
    }
}
