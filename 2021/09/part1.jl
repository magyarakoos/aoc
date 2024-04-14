f = map(l -> map(x -> parse(Int, x), split(l, "")), readlines("input"))
ψ = (i, j) -> begin
    di = [1, -1, 0, 0]; dj = [0, 0, 1, -1]
    for i in 1:4
        if (0 < i + di[i] && 0 < j + dj[i] && i + di[i] <= length(f) && j + dj[i] <= length(f[i]) && f[di[i]][dj[i]] <= f[i][j])
            return false
        end
    end
    return true
end
p1 = 0
for i in eachindex(f)
    for j in eachindex(f[i])
        if ψ(i, j) print(f[i][j]) end
    end
    println()
end
println(p1)