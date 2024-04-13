s = Set()
f = (l) -> push!(s, (parse(l[1]), parse(l[2]), parse(l[3])))
for p in map(l -> (parse(l[1]), parse(l[2]), parse(l[3])), readlines("input"))
    push!(s, p)
end