string[] input = File.ReadAllLines("input.txt");
(char[] dir, byte[] cnt) = (input.Select(l => l[0]).ToArray(), input.Select(l => byte.Parse(l.Split(' ')[1])).ToArray());

// TODO: solve the problem