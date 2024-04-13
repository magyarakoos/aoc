f = open("input", "r")
rx = r"Card \d+: (\d+(?:\s+\d+)*) \| (\d+(?:\s+\d+)*)"
for l in eachline(f)
    a = parse.(Int, split(match(rx, l)[1]))
    b = parse.(Int, split(match(rx, l)[2]))
    println(length(intersect(a, b)))
end
