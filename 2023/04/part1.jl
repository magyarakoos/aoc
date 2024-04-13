f = open("input", "r")
rx = r"Card \d+: (\d+(?:\s+\d+)*) \| (\d+(?:\s+\d+)*)"
p1 = 0
for l in eachline(f)
    a = parse.(Int, split(match(rx, l)[1]))
    b = parse.(Int, split(match(rx, l)[2]))
    global p1 += 2 ^ (length(intersect(a, b)) - 1)
end
