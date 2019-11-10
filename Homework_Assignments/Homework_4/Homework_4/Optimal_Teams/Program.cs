using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using longBoi = System.Int32;

struct studentInfo
{
    public longBoi position;
    public longBoi numberOfSkills;

}
namespace Optimal_Teams
{
    class Program
    {
        static void Main(string[] args)
        {
            string initValues = Console.ReadLine();
            string initFixed = initValues.Trim(' ');

            string[] initNumbers = initFixed.Split(' ');
            int[] numbersConverted = Array.ConvertAll(initNumbers, int.Parse);
            longBoi numberOfStudents = numbersConverted[0];
            longBoi selectionRange = numbersConverted[1];

            string rawNumbers = Console.ReadLine();
            string Fixed = rawNumbers.Trim(' ');
            string[] numbers = Fixed.Split(' ');
            
            List<longBoi> studentSkills = Array.ConvertAll(numbers, longBoi.Parse).ToList();
            List<longBoi> sortedSkills = Array.ConvertAll(numbers, longBoi.Parse).ToList();
            List<longBoi> tempList = Array.ConvertAll(numbers, longBoi.Parse).ToList();
            sortedSkills.Sort();

            Dictionary<int, longBoi> studentInfo = new Dictionary<int, longBoi>();
            for (int i = 0; i < numberOfStudents; i++)
            {
                studentInfo.Add(sortedSkills[i], studentSkills.IndexOf(sortedSkills[i]));
            }

            longBoi studentsPlaced = 0;
            bool isIvansTurn = true;

            while (studentsPlaced < numberOfStudents)
            {
                longBoi currentMax = studentInfo.ElementAt(studentInfo.Count - 1).Key;
                longBoi indexOfCurrentMax = studentInfo.ElementAt(studentInfo.Count - 1).Value;
                studentInfo.Remove(currentMax);
                if (!isIvansTurn)
                {
                    studentSkills[indexOfCurrentMax] = -2;
                }
                else
                {
                    studentSkills[indexOfCurrentMax] = -1;
                }

                studentsPlaced++;
                for (int i = indexOfCurrentMax + 1; i <= indexOfCurrentMax + selectionRange && i < tempList.Count; i++)
                {
                    if (studentSkills[i] != -1 && studentSkills[i] != -2)
                    {
                        studentInfo.Remove(studentSkills[i]);
                        tempList.Remove(studentSkills[i]);
                        if (!isIvansTurn)
                        {
                            studentSkills[i] = -2;
                        }
                        else
                        {
                            studentSkills[i] = -1;
                        }
                        studentsPlaced++;
                        //continue;
                    }

                  //  break;
                }

                for (int i = indexOfCurrentMax - 1; i >= indexOfCurrentMax - selectionRange && i >= 0; i--)
                {
                    if (studentSkills[i] != -1 && studentSkills[i] != -2)
                    {
                        studentInfo.Remove(studentSkills[i]);

                        if (!isIvansTurn)
                        {
                            studentSkills[i] = -2;
                        }
                        else
                        {
                            studentSkills[i] = -1;
                        }

                        studentsPlaced++;
                        //continue;
                    }

                   // break;
                }

                isIvansTurn = !isIvansTurn;
            }

            foreach (var skill in studentSkills)
            {
                if (skill == -1)
                {
                    Console.Write(1);
                }
                else
                {
                    Console.Write(2);
                }
            }
        }//Main end

    }
}
