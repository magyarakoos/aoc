a = map(x -> [parse(Int, x[i]) for i in eachindex(x)], readlines("input"))
for i in eachindex(a[1]), j in eachindex(a)
    println(a[i, j])
end