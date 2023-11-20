// part 1
Console.WriteLine(File.ReadAllLines("input.txt").Select(l => "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ".IndexOf(l.Substring(0, l.Length / 2).Intersect(l.Substring(l.Length / 2)).First()) + 1).Sum());

// part 2
string[] input = File.ReadAllLines("input.txt");
int result = 0;
for (int i = 2; i < input.Length; i+=3) {
    result += "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ".IndexOf(input[i-2].Intersect(input[i-1]).Intersect(input[i]).First()) + 1;
}
Console.WriteLine(result);

