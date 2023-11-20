string[] input = File.ReadAllLines("input");
Stack<string> path = new();
Dictionary<string, int> sizes = new();

foreach (string line in input) {
    if (line == "$ cd ..") {
        path.Pop();
    }
    else if (line.StartsWith("$ cd")) {
        path.Push(string.Join("", path) + line.Split(' ')[2]);
    }
    else if (char.IsNumber(line[0])) {
        int size = int.Parse(line.Split(' ')[0]);
        foreach (string dir in path) {
            sizes[dir] = sizes.GetValueOrDefault(dir) + size;
        }
    }
}

List<int> directorySizes = sizes.Values.ToList();
Console.WriteLine(directorySizes.Where(x => x < 100000).Sum());

int freeSpace = 70000000 - directorySizes.Max();
Console.WriteLine(directorySizes.Where(size => size + freeSpace >= 30000000).Min());