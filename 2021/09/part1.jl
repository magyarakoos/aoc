f = map(l -> split(l, ""), readlines("input"))
m = zeros(Int, length(f), length(f[1]))
for i in eachindex(f), j in eachindex(f[1])
    m[i, j] = parse(Int, f[i][j])
end
ψ = (i, j) -> begin
    for di in [1, -1, 0, 0], dj in [0, 0, 1, -1]
        if (0 < di && 0 < dj && di <= length(m) && dj <= length(m[1]) && m[di][dj] <= m[i][j])
            return false
        end
    end
    return true
end
p1 = 0
for i in eachindex(m), j in eachindex(m[1])
    if ψ(i, j) global p1 += m[i][j] + 1 end
end
for i in eachindex(m)
    for j in eachindex(m[1])
        print(m[i, j])
    end
    println()
end
println(p1)