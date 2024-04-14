f = map(l -> map(x -> parse(Int, x), split(l, "")), readlines("input"))
ψ = (i, j) -> begin
    di = [1, -1, 0, 0]; dj = [0, 0, 1, -1]
    for k in 1:4
        ni = i + di[k]; nj = j + dj[k]
        if ni > 0 &&  nj > 0 && ni <= length(f) && nj <= length(f[1]) && f[ni][nj] <= f[i][j]
            return false
        end
    end
    return true
end
p1 = 0
for i in eachindex(f), j in eachindex(f[1])
    if ψ(i, j) global p1 += f[i][j] + 1 end
end
println(p1)