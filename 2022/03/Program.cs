string abc = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

Console.WriteLine(File.ReadAllLines("input").Select(l => abc.IndexOf(l[..(l.Length / 2)].Intersect(l[(l.Length / 2)..]).First()) + 1).Sum());

string[] input = File.ReadAllLines("input");
int result = 0;
for (int i = 2; i < input.Length; i+=3) {
    result += abc.IndexOf(input[i-2].Intersect(input[i-1]).Intersect(input[i]).First()) + 1;
}
Console.WriteLine(result);