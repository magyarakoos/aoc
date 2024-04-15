f = map(l -> map(x -> parse(Int, x), split(l, "")), readlines("input"))
vis = Set()
ψ = (i, j) -> begin
    f[i][j] = 0
    for ni in (i - 1):(i + 1), nj in (j - 1):(j + 1)
        if (ni == i && nj == j) || (ni, nj) ∈ vis ||
            ni < 1 || nj < 1 || ni > length(f) || nj > length(f[1])
            continue
        end
        push!(vis, (ni, nj))
        f[ni][nj] += 1
        if f[ni][nj] > 9
            ψ(ni, nj)
        end
    end
end
for _ in 1:3
    global vis = Set()
    global f = [l .+ 1 for l in f]
    for i in eachindex(f), j in eachindex(f[1])
        if f[i][j] > 9 ψ(i, j) end
    end
    for l in f println(l) end
    println()
end

