f = map(l -> map(x -> parse(Int, x), split(l, "")), readlines("input"))
ψ = (i, j) -> begin
    di = [1, -1, 0, 0]; dj = [0, 0, 1, -1]
    for i in 
        if (0 < di && 0 < dj && di <= length(f) && dj <= length(f[i]) && f[di][dj] <= f[i][j])
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