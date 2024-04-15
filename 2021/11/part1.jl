f = map(l -> map(x -> parse(Int, x), split(l, "")), readlines("input"))
vis = zeros(Int, length(f), length(f[1]))
p1 = 0; curr = 0
ψ = (i, j) -> begin
    if ni < 1 || nj < 1 || ni > length(f) || nj > length(f[1]) ||
       vis[ni][nj] == curr return end
    f[i][j] += 1
    if f[i][j] <= 9 return end
    vis[i][j] = curr
    global p1 += 1
    f[i]
    for ni in (i - 1):(i + 1), nj in (j - 1):(j + 1)
            continue
        end
        vis[ni][nj] = curr
        f[ni][nj] += 1
        if f[ni][nj] > 9
            ψ(ni, nj)
        end
    end
end
for _ in 1:10
    global curr += 1
    global f = [l .+ 1 for l in f]
    for i in eachindex(f), j in eachindex(f[1])
        if f[i][j] > 9 ψ(i, j) end
    end
end
println(p1)