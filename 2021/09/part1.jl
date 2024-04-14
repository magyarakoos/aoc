m = map(l -> map(x -> parse(Int, x), split(l, "")), readlines("input"))
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
    if ψ(i, j) global p1 += m[i][j] + 1; println(m[i][j]) end
end
println(p1)