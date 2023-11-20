using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.Permissions;
using System.Text;
using System.Threading.Tasks;

namespace AoC04
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int score = 0;
            string[] input = File.ReadAllLines("input.txt");
            for (int i = 0; i < input.Length; i++)
            {
                string line = input[i];
                string firstHalf = line.Split(',')[0];
                string secondHalf = line.Split(',')[1];
                int firstFirstNum = int.Parse(firstHalf.Split('-')[0]);
                int firstSecondNum = int.Parse(firstHalf.Split('-')[1]);
                int secondFirstNum = int.Parse(secondHalf.Split('-')[0]);
                int secondSecondNum = int.Parse(secondHalf.Split('-')[1]);
                if (firstFirstNum <= secondFirstNum && firstSecondNum >= secondSecondNum)
                {
                    score++;
                }
                else if (firstFirstNum >= secondFirstNum && firstSecondNum <= secondSecondNum)
                {
                    score++;
                }
            }
            Console.WriteLine(score);
            Console.ReadKey();
        }
    }
}




