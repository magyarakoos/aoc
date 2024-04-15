f = map(l -> map(x -> parse(Int, x), split(l, "")), readlines("input"))
vis = zeros(Int, length(f), length(f[1]))
p1 = 0; label = 0; curr = 0
ψ = (i, j) -> begin
    if i < 1 || j < 1 || i > length(f) || j > length(f[1]) ||
       vis[i, j] == label return end
    f[i][j] += 1
    if f[i][j] <= 9 return end
    vis[i, j] = label
    global curr += 1
    f[i][j] = 0
    for ni in (i - 1):(i + 1), nj in (j - 1):(j + 1)
        ψ(ni, nj)
    end
end
while true
    global label += 1
    for i in eachindex(f), j in eachindex(f[1])
        ψ(i, j)
    end
    global p1 += curr
    if curr == 100 println(label) end
    if label == 100 println(p1) end
end