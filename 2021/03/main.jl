a = [parse.(Int, split(l, "")) for l in eachline("input")]
zc = zeros(length(a[1])); oc = zeros(length(a[1]))
for j in eachindex(a[1]), i in eachindex(a)
    if (a[i][j] == 1) global oc[j] += 1
    else global zc[j] += 1 end
end
reverse!(zc)
reverse!(oc)
g = 0; e = 0
for j in eachindex(zc)
    global (zc[j] < oc[j] ? e : g) |= 
    if 
        global e |= (1 << (j - 1))
    else
        global g |= (1 << (j - 1))
    end
end
println(g * e)