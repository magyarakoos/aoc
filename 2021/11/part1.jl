f = map(l -> map(x -> parse(Int, x), split(l, "")), readlines("input"))
ψ = (i, j) -> begin
    for ni in (i - 1):(i + 1), nj in (j - 1):(j + 1)
        if ni == i && nj == j continue end
        f[ni][nj] += 1
        
end