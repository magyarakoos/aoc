string[] input = File.ReadAllLines("input.txt");
(char[] dir, byte[] cnt) = (input.Select(l => l[0]).ToArray(), input.Select(l => byte.Parse(l.Split(' ')[1])).ToArray());




// log input
/*
    for (int i = 0; i < input.Length; i++) {
        Console.WriteLine(dir[i] + " " + cnt[i]);
    }
*/

