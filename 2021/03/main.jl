a = map(x -> [parse(Int, x[i]) for i in eachindex(x)], readlines("input"))
for j in eachindex(a[1]), i in eachindex(a)
    println(a[i][j])
end