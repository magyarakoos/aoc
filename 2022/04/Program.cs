var input = File.ReadAllLines("input").Select(l => l.Split(new char[]{',', '-'}).Select(int.Parse).ToArray());
var p1 = 0;
var p2 = 0;
foreach (var a in input) {
    if ((a[0] <= a[2] && a[1] >= a[3]) || (a[0] >= a[2] && a[1] <= a[3])) p1++; 
    if ((a[0] <= a[2] && a[1] >= a[2]) || (a[0] >= a[2] && a[1] >= a[2])) p2++;
}
Console.WriteLine(p1 + "\n" + p2);