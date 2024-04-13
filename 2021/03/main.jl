a = [parse.(Int, split(l, "")) for l in eachline("input")]
res = Array{Array{Int}(2)}(length(a))
for j in eachindex(a[1]), i in eachindex(a)
end