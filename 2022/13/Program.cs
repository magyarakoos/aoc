List<Packet> divs = [new Packet("[[6]]"), new Packet("[[2]]")];
List<Packet> input = [.. File.ReadAllText("input")
    .Split('\n').Where(s => s != "").Select(s => new Packet(s))];
input.AddRange(divs);

int p1 = 0;
for (int i = 1; i < input.Count; i += 2) {
    if (input[i - 1] < input[i]) p1 += i / 2 + 1;
}
Console.WriteLine(p1);

int p2 = 1;
input.Sort((a, b) => a < b ? -1 : 1);
foreach (Packet div in divs) {
    p2 *= input.IndexOf(div) + 1;
}
Console.WriteLine(p2); 

class Packet {
    List<Packet> a = [];
    int? data = null;
    public Packet(string s) {
        if (s.Length == 0) return;
        else if (s[0] == '[') {
            s = s[1..^1];
            int bal = 0;
            for (int i = 0; i < s.Length; i++) {
                if (s[i] == '[') bal++;
                else if (s[i] == ']') bal--;
                else if (s[i] == ',' && bal == 0) s = s[..i] + '$' + s[(i + 1)..];
            }
            a = [.. s.Split('$').Select(t => new Packet(t))];
        }
        else data = int.Parse(s);
    }
    public static bool operator <(Packet a, Packet b) {
        if (a.data != null && b.data != null) {
            return a.data < b.data;
        }
        if (a.data != null) {
            a = new Packet($"[{a.data}]");
        }
        if (b.data != null) {
            b = new Packet($"[{b.data}]");
        }
        for (int i = 0; ; i++) {
            if (i == a.a.Count) return a.a.Count != b.a.Count;
            if (i == b.a.Count) return false;
            if (a.a[i] < b.a[i]) return true;
            if (a.a[i] > b.a[i]) return false;
        }
    }
    public static bool operator >(Packet a, Packet b) => b < a;
}