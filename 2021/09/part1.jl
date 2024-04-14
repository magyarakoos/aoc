f = map(l -> map(x -> parse(Int, x), split(l, "")), readlines("input"))
ψ = (i, j) -> begin
    di = [1, -1, 0, 0]; dj = [0, 0, 1, -1]
    for k in 1:4
        ni = i + di[k]; nj = j + dj[k]
        if ni <= 0 
            continue 
        end
        # if f[i + di[i]][j + dj[i]] <= f[i][j]
        #     return false
        # end
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