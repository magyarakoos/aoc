f = open("input", "r")
a = []
for l in eachline(f)
    rows = parse.(Int, split(l))