byte[][] m = File.ReadAllLines("input").Select(line => line.Select(c => (byte)char.GetNumericValue(c)).ToArray()).ToArray();
(int w, int h) = (m[0].Length, m.Length);
(int sum, int max) = (0, 0);

for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
		if (i == 0 || j == 0 || i == h - 1 || j == w - 1) {
			sum++;
		}
		else {
			(int ls, int rs, int ts, int bs) = (0, 0, 0, 0);
			(bool l, bool r, bool t, bool b) = (true, true, true, true);
			for (int k = i + 1; k < h; k++) {
				bs++;
				if (m[k][j] >= m[i][j]) {
					b = false;
					break;
				}
			}
			for (int k = j + 1; k < w; k++) {
				rs++;
				if (m[i][k] >= m[i][j]) {
					r = false;
					break;
				}
			}
			for (int k = i - 1; k >= 0; k--) {
				ts++;
				if (m[k][j] >= m[i][j]) {
					t = false;
					break;
				}
			}
			for (int k = j - 1; k >= 0; k--) {
				ls++;
				if (m[i][k] >= m[i][j]) {
					l = false;
					break;
				}
			}
			if (b || t || r || l) sum++;
			max = Math.Max(max, bs*ts*rs*ls);
		}
    }
}

Console.WriteLine(sum + '\n' + max);