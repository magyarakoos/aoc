using StatsBase
f = map(l -> map(x -> parse(Int, x), split(l, "")), readlines("input"))
vis = zeros(Int, length(f), length(f[1]))
p1 = 0; curr = 0
ψ = (i, j) -> begin
    if i < 1 || j < 1 || i > length(f) || j > length(f[1]) ||
       vis[i, j] == curr return end
    f[i][j] += 1
    if f[i][j] <= 9 return end
    vis[i, j] = curr
    global p1 += 1
    f[i][j] = 0
    for ni in (i - 1):(i + 1), nj in (j - 1):(j + 1)
        ψ(ni, nj)
    end
end
while true
    global curr += 1
    for i in eachindex(f), j in eachindex(f[1])
        ψ(i, j)
    end
    if curr == 100 println(p1) end
    if curr != 1 && length(countmap(collect(reduce(vcat, vis)))) == 1
        println(curr)
        exit(0)
    end
end
