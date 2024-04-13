a = [parse.(Int, split(l, "")) for l in eachline("input")]
zc = Vector{Int}(length(a))
for j in eachindex(a[1]), i in eachindex(a)
    res[j][]
end