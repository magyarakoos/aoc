﻿Console.Write(File.ReadAllLines("input")[0].Split(',').Sum(l => l.Aggregate(0, (s,c) => (s + c) * 17 % 256)));