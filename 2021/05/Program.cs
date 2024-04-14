class Line {
    public int x1, x2, y1, y2;
}

static void Main(string[] args) {
    List<Line> lines = new List<Line>();
    using (StreamReader f = new StreamReader("input")) {
        while (!f.EndOfStream) {
            int[] row = f.ReadLine().Split(' ').Select(int.Parse).ToArray();
            if (row[0] == row[2] || row[1] == row[3] || Math.Abs(row[0] - row[2]) == Math.Abs(row[1] - row[3])) {
                lines.Add(new Line { x1 = row[0], y1 = row[1], x2 = row[2], y2 = row[3] });
            }
        }
    }
    int[,] map = new int[lines.Max(x => Math.Max(x.y1, x.y2)) + 1, lines.Max(x => Math.Max(x.x1, x.x2)) + 1];
    int more = 0;
    foreach (Line e in lines) {
        if (e.x1 == e.x2) {
            for (int i = Math.Min(e.y1, e.y2); i <= Math.Max(e.y1, e.y2); i++) {
                if (++map[i, e.x1] == 2) {
                    ++more;
                }
            }
        }
        else if (e.y1 == e.y2) {
            for (int i = Math.Min(e.x1, e.x2); i <= Math.Max(e.x1, e.x2); i++) {
                if (++map[e.y1, i] == 2) {
                    ++more;
                }
            }
        }
        else {
            int i = e.x1, j = e.y1;
            while (i != e.x2) {
                if (++map[j, i] == 2) {
                    ++more;
                }
                i += Math.Sign(e.x2 - e.x1);
                j += Math.Sign(e.y2 - e.y1);
            }
            if (++map[j, i] == 2) {
                ++more;
            }
        }
    }
    Console.WriteLine(more);
}