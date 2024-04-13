a = [parse.(Int, split(l, "")) for l in eachline("input")]
zc = Vector{Int}(length(a)); oc = Vector{Int}(length(a))
# for j in eachindex(a[1]), i in eachindex(a)
#     if (a[i][j] == 1) global oc[j] += 1
#     else gloal zc[j] += 1 end
# end
# println(zc)
# println(oc)