using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LongBoi = System.Int64;
namespace Problem_2_GrandHotel
{
    class Program
    {
        static void Main(string[] args)
        {
            Dictionary<LongBoi, LongBoi> roomKeys = new Dictionary<long, long>();
            Dictionary<LongBoi, LongBoi> doorKeys = new Dictionary<long, long>();

            LongBoi numberOfRooms;
            string[] initNumbers = Console.ReadLine().Trim(' ').Split(' ');
            LongBoi[] numbersConverted = Array.ConvertAll(initNumbers, long.Parse);
            numberOfRooms = numbersConverted[0];

            string [] roomKeyInput = Console.ReadLine().Trim(' ').Split(' ');
            List<LongBoi> roomKeyValues = Array.ConvertAll(roomKeyInput, long.Parse).ToList();

            string[]  doorKeyInput = Console.ReadLine().Trim(' ').Split(' ');
            List<LongBoi> doorKeyValues = Array.ConvertAll(doorKeyInput, long.Parse).ToList();

            for (int i = 0; i < roomKeyValues.Count; i++)
            {
                roomKeys[i] = roomKeyValues[i];
                
            }

            for (int i = 0; i < doorKeyValues.Count; i++)
            {
                doorKeys[i] = doorKeyValues[i];
            }

            LongBoi minimumNumberOfKeys = 0;
            Dictionary<LongBoi,LongBoi> currentKeys = new Dictionary<long,long>();
            for (int i = 0; i < doorKeys.Count; i++)
            {
                if (!currentKeys.ContainsKey(roomKeys[i]))
                {
                    currentKeys.Add(roomKeys[i], 1);
                }
                else
                {
                    currentKeys[roomKeys[i]]++;
                }
                
                LongBoi keyNeededForDoor = doorKeys[i];
                if (currentKeys.ContainsKey(keyNeededForDoor))
                {
                    if (currentKeys[keyNeededForDoor]==1)
                    {
                        currentKeys.Remove(keyNeededForDoor);
                    }
                    else
                    {
                        currentKeys[keyNeededForDoor]--;
                    }
                }
                else
                {
                    minimumNumberOfKeys++;
                }
            }

            Console.WriteLine(minimumNumberOfKeys);
        }
    }
}
