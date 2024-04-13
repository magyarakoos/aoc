f = open("input", "r")
rx = r"Card\s+\d+:((?:\s+\d+)+) \|((?:\s+\d+)+)"
p1 = 0
matches = []
counts = []

for l in eachline(f)
    a = parse.(Int, split(match(rx, l)[1]))
    b = parse.(Int, split(match(rx, l)[2]))
    sz = length(intersect(a, b))
    if (sz != 0)
        global p1 += 2 ^ (sz - 1)
    end
    push!(matches, sz)
    push!(counts, 1)
end

for i in eachindex(matches)
    println((matches[i], countS[i]))
end