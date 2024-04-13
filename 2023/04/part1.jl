f = open("input", "r")
rx = r"Card\s+\d+:((?:\s+\d+)+) \|((?:\s+\d+)+)"
(p1 = 0; p2 = [])
for l in eachline(f)
    a, b = [parse.(Int, split(match(rx, l)[i])) for i in 1:2]
    sz = length(intersect(a, b))
    if (sz != 0)
        global p1 += 2 ^ (sz - 1)
    end
    push!(p2, (sz, 1))
end
for i in 1:length(p2), j in (i + 1):(i + p2[i][1])
    if j > length(p2)
        break
    end
    p2[j][2] += p2[i][2]
end
println((p1, sum(map(x -> x[2], p2))))