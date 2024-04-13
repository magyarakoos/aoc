f = open("input", "r")
rx = r"Card \d+:((?:\s+\d+)+) \|((?:\s+\d+)+)"
p1 = 0
for l in eachline(f)
    a = parse.(Int, split(match(rx, l)[1]))
    b = parse.(Int, split(match(rx, l)[2]))
    sz = length(intersect(a, b))
    # global p1 += sz != 0 ? 2 ^ (sz - 1) : 0
    global p1 += sz * (2.0 ^ (sz - 1))
end
println(Int{p1})