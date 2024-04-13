f = open("input", "r")
rx = r"Card \d+:((?:\s+\d+)+) \|((?:\s+\d+)+)"
p1 = 0
for l in eachline(f)
    a = parse.(Int, split(match(rx, l)[1]))
    b = parse.(Int, split(match(rx, l)[2]))
    sz = length(intersect(a, b))
    if (sz)
end
println(p1)