namespace AdventOfCode2022
{
    class AoC05
    {
        static void Main(string[] args)
        {
            string[] input = File.ReadAllLines("input.txt");

            // Initialize the stacks of crates
            List<Stack<char>> stacks = new List<Stack<char>>();
            foreach (string line in input)
            {
                Stack<char> stack = new Stack<char>();
                foreach (char c in line)
                {
                    stack.Push(c);
                }
                stacks.Add(stack);
            }

            // Apply the rearrangement procedure
            foreach (string line in input)
            {
                string[] parts = line.Split(' ');
                if (parts[0] == "move")
                {
                    // Move a quantity of crates from one stack to another
                    try
                    {
                        int from = int.Parse(parts[2]) - 1;
                        int to = int.Parse(parts[5]) - 1;
                        char crate = stacks[from].Pop();
                        stacks[to].Push(crate);
                    }
                    catch (FormatException)
                    {
                        Console.WriteLine("Unable to parse integer from string.");
                    }
                }
                else
                {
                    // Pile a quantity of crates on top of another stack
                    try
                    {
                        int from = int.Parse(parts[2]) - 1;
                        int to = int.Parse(parts[5]) - 1;
                        char[] crates = stacks[from].Take(int.Parse(parts[4])).ToArray();
                        foreach (char crate in crates)
                        {
                            stacks[from].Pop();
                            stacks[to].Push(crate);
                        }
                    }
                    catch (FormatException)
                    {
                        Console.WriteLine("Unable to parse integer from string.");
                    }
                }
            }

            // Print the top crate of each stack
            foreach (Stack<char> stack in stacks)
            {
                Console.Write(stack.Peek());
            }
            Console.WriteLine();
        }
    }
}


