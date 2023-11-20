using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Security.Cryptography.X509Certificates;

namespace AoC02
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int score = 0;
            var lines = File.ReadAllLines("input.txt");
            first(lines, score);
            second(lines, score);  
            Console.ReadKey();

            void first(string[] strArray, int result)
            {
                foreach (var item in strArray)
                {
                    switch (item[2])
                    {
                        case 'X':
                            result++;
                            switch (item[0])
                            {
                                case 'A':
                                    result += 3;
                                    break;
                                case 'B':
                                    result += 0;
                                    break;
                                case 'C':
                                    result += 6;
                                    break;
                            }
                            break;
                        case 'Y':
                            result += 2;
                            switch (item[0])
                            {
                                case 'A':
                                    result += 6;
                                    break;
                                case 'B':
                                    result += 3;
                                    break;
                                case 'C':
                                    result += 0;
                                    break;
                            }
                            break;
                        case 'Z':
                            result += 3;
                            switch (item[0])
                            {
                                case 'A':
                                    result += 0;
                                    break;
                                case 'B':
                                    result += 6;
                                    break;
                                case 'C':
                                    result += 3;
                                    break;
                            }
                            break;
                    }
                }
                Console.WriteLine("Első rész eredménye: " + result);
            }

            void second(string[] strArray, int result)
            {
                foreach (var item in strArray)
                {
                    switch (item[2])
                    {
                        case 'X':
                            switch (item[0])
                            {
                                case 'A':
                                    result += 3;
                                    break;
                                case 'B':
                                    result += 1;
                                    break;
                                case 'C':
                                    result += 2;
                                    break;
                            }
                            break;
                        case 'Y':
                            switch (item[0])
                            {
                                case 'A':
                                    result += 4;
                                    break;
                                case 'B':
                                    result += 5;
                                    break;
                                case 'C':
                                    result += 6;
                                    break;
                            }
                            break;
                        case 'Z':
                            switch (item[0])
                            {
                                case 'A':
                                    result += 8;
                                    break;
                                case 'B':
                                    result += 9;
                                    break;
                                case 'C':
                                    result += 7;
                                    break;
                            }
                            break;
                    }
                }
                Console.WriteLine("Második rész eredménye: " + result);
            }
        }
    }
}


