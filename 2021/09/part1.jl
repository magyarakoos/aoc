f = map(l -> map(x -> parse(Int, x), split(l, "")), readlines("input"))
di = [1, -1, 0, 0]; dj = [0, 0, 1, -1]
vis = zeros(Int, length(f), length(f[1]))
basins = []
ψ = (i, j) -> begin
    for k in 1:4
        ni = i + di[k]; nj = j + dj[k]
        if ni > 0 &&  nj > 0 && ni <= length(f) && nj <= length(f[1]) && f[ni][nj] <= f[i][j]
            return false
        end
    end
    return true
end
φ = (i, j, k) -> begin
    vis[i, j] = k
    for k in 1:4
        ni = i + di[k]; nj = j + dj[k]
        if ni > 0 && nj > 0 && ni <= length(f) && nj <= length(f[1]) && vis[ni, nj] == 0 && f[ni][nj] < 9
            φ(ni, nj, k)
        end
    end
end
for i in eachindex(f), j in eachindex(f[1])
    if ψ(i, j) push!(basins, (i, j)) end
end
for i in eachindex(basins)
    φ(basins[i][1], basins[i][2], i)
end
println(sum(x -> f[x[1]][x[2]], basins) + length(basins))
for row in vis
    println(row)
end