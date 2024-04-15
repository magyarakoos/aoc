f = map(l -> map(x -> parse(Int, x), split(l, "")), readlines("input"))
vis = Set()
ψ = (i, j) -> begin
    f[i][j] = 0
    for ni in (i - 1):(i + 1), nj in (j - 1):(j + 1)
        if (ni == i && nj == j) || (ni, nj) ∈ vis continue end
        push!(vis, (ni, nj))
        f[ni][nj] += 1
        if f[ni][nj] > 9
            ψ(ni, nj)
        end
    end
end
for _ in 1:3
    f = [l .+ 1 for l in f]
    if 