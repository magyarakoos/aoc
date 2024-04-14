m = map(l -> split(l, ""), readlines("input"))
ψ = (i, j) -> begin
    for di in [1, -1, 0, 0], dj in [0, 0, 1, -1]
        if (0 < di && 0 < dj && di <= length(f) && dj <= length(f[1]) && m[di][dj] <= m[i][j])
            return false
        end
    end
    return true
end
for i in eachindex(f), j in eachline(f[1])
    if 
end