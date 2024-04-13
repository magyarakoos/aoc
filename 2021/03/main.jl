a = [parse(Int, split(line)) for line in eachline("input")]
for j in eachindex(a[1]), i in eachindex(a)
    println(a[i][j])
end