a = [parse.(Int, split(l, "")) for l in eachline("input")]
res = []
for j in eachindex(a[1]), i in eachindex(a)
    println(a[i][j])
end