f = map(l -> split(l, ""), readlines("input"))
m = zeros(Int, length(f), length(f[1]))
ψ = (i, j) -> begin
    for di in [1, -1, 0, 0], dj in [0, 0, 1, -1]
        if (0 < di && 0 < dj && di <= length(f) && dj <= length(f[1]) && m[di, dj] <= m[i, j])
            return false
        end
    end
    return true
end
for i in eachindex(f), j in eachindex(f[1])
    m[i, j] = parse(Int, f[i][j])
end
for i in eachindex(f), j in eachline(f[1]), 
end