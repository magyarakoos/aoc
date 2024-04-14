f = map(l -> map(x -> parse(Int, x), split(l, "")), readlines("input"))
ψ = (i, j) -> begin
    for di in [1, -1, 0, 0], dj in [0, 0, 1, -1]
        if (0 < di && 0 < dj && di <= length(f) && dj <= length(f[1]) && f[di][dj] <= f[i][j])
            return false
        end
    end
    return true
end
p1 = 0
for i in eachindex(f), j in eachindex(f[1])
    if ψ(i, j) global p1 += m[i][j] + 1 end
end
for row in f
    println()
end
println(p1)