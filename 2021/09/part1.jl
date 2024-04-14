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
for i in eachindex(f)
    for j in eachindex(f[i])
        print(f[i][j])
        if ψ(i, j) global p1 += f[i][j] + 1 end
    end
    println()
end
println(p1)